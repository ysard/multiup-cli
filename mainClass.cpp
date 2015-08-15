/*
This file is part of multiup_cli.

    multiup_cli is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    multiup_cli is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with multiup_cli.  If not, see <http://www.gnu.org/licenses/>.
    
    Copyright 2013 Lex
    www.multiup.org
*/

#include "mainClass.h"

using namespace std;

// REVOIR ça ! structure globale dans tous les fichiers (extern) => très sale !
struct Bricolage    bricolo;
enum EtatConnexion  etatConnexion;


MainClass::MainClass(const list<string> &listeFichiers)
{
    m_listeFichiers = listeFichiers;
    m_connecte      = false;

    bricolo.etape   = 1;

    //lancement();
}

MainClass::MainClass(const string &login, const string &password, const list<string> &listeFichiers)
{
    m_login         = login;
    m_password      = password;

    m_listeFichiers = listeFichiers;
    m_connecte      = true;

    bricolo.etape   = 0;

    // Etape de login ( bricolo.etape   = 0)
    connexion();

    //lancement();
}

MainClass::~MainClass()
{
    // Pouet
}

void MainClass::lancement()
{
    //afficher();

    // Upload des fichiers les uns après les autres
    list<string>::iterator iterator;
    for (iterator=m_listeFichiers.begin(); iterator!=m_listeFichiers.end(); ++iterator)
    {
        m_fichierEnCours = *iterator;
        cout << "Fichier en cours d'up : " << m_fichierEnCours << endl;

        bricolo.etape = 1;
        connexion();
    }
    cout << "Fin du programme" << endl;
}

void MainClass::afficher()
{
    cout << m_login << " " << m_password;

    list<string>::iterator iterator;
    for (iterator=m_listeFichiers.begin(); iterator!=m_listeFichiers.end(); ++iterator)
        cout << " " << *iterator;

    cout << endl;
    //qDebug() << m_listeFichiers;
}

void MainClass::connexion()
{
    //---------- Curl
    CURLcode hResult;

    // Réinitialisation des params de curl
    // Curl for form data
    m_post = NULL;
    m_last = NULL;

    // Initialize curl, just don't let easy_init to do it for you
    #ifdef WINDOWS
        curl_global_init(CURL_GLOBAL_WIN32);
    #endif
    #ifdef LINUX
        curl_global_init(CURL_GLOBAL_ALL);
    #endif

    // Handle to the curl
    m_hCurl = curl_easy_init();

    // Constitution des requêtes en fonction des étapes
    if (bricolo.etape == 0) { // Connexion
        curl_formadd(&m_post,
                     &m_last,
                     CURLFORM_COPYNAME,
                     "username",
                     CURLFORM_COPYCONTENTS,
                     m_login.c_str(),
                     CURLFORM_END);
        curl_formadd(&m_post,
                     &m_last,
                     CURLFORM_COPYNAME,
                     "password",
                     CURLFORM_COPYCONTENTS,
                     m_password.c_str(),
                     CURLFORM_END);

        //Specify the API Endpoint
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_URL, URL_CONNEXION_UTILISATEUR);

        //Progression désactivée
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_NOPROGRESS, 1);
    }
    else if (bricolo.etape == 1) { // Sélection du serveur

        //Specify the API Endpoint
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_URL, URL_SELECTION_SERVEUR);

        //Progression désactivée
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_NOPROGRESS, 1);
    }
    else if (bricolo.etape == 2) { // Récupération des hébergeurs

        // Ajoute le nom d'utilisateur à la requête de curl (v2)
        if (m_connecte == true) {
            curl_formadd(&m_post,
                         &m_last,
                         CURLFORM_COPYNAME,
                         "username",
                         CURLFORM_COPYCONTENTS,
                         m_login.c_str(),
                         CURLFORM_END);
            curl_formadd(&m_post,
                         &m_last,
                         CURLFORM_COPYNAME,
                         "password",
                         CURLFORM_COPYCONTENTS,
                         m_password.c_str(),
                         CURLFORM_END);
        }

        //Specify the API Endpoint
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_URL, URL_RECUPERATION_DROITS);

        //Progression désactivée
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_NOPROGRESS, 1);
    }
    else if (bricolo.etape == 3) { // Upload
        // Ajoute le nom d'utilisateur à la requête de curl (v2)
        if (m_connecte == true) {
            //cout << "Curl :: Login : " << m_login << endl;

            curl_formadd(&m_post,
                         &m_last,
                         CURLFORM_COPYNAME,
                         "user",
                         CURLFORM_COPYCONTENTS,
                         bricolo.loginId.c_str(),
                         CURLFORM_END);
        }

        list<string>::iterator iterator;
        string hebergeur;
        for (iterator=bricolo.hebergeursListe.begin(); iterator!=bricolo.hebergeursListe.end(); ++iterator)
        {
            // Désolé mais l'itérateur n'a pas la méthode c_str().. obligé de convertir en string...
            hebergeur = *iterator;

            //cout << "Curl :: Hebergeur : " << hebergeur << endl;

            curl_formadd(&m_post,
                         &m_last,
                         CURLFORM_COPYNAME,
                         hebergeur.c_str(),
                         CURLFORM_COPYCONTENTS,
                         "true",
                         CURLFORM_END); // Apparait dans valgrind..
        }

        // Ajoute le fichier  la requête d'upload de curl
        curl_formadd(&m_post,
                     &m_last,
                     CURLFORM_COPYNAME,
                     "files[]",
                     CURLFORM_FILE,
                     m_fichierEnCours.c_str(),
                     CURLFORM_END); // Apparait dans valgrind..

        //Specify the API Endpoint
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_URL, bricolo.adresseIp.c_str());

        //Progression activée et fonction
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_NOPROGRESS, 0);
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_PROGRESSFUNCTION, &progress_func);
    }

    //Récupération de la réponse du serveur
    hResult = curl_easy_setopt(m_hCurl, CURLOPT_WRITEFUNCTION, write_data);

    //UserAgent
    hResult = curl_easy_setopt(m_hCurl, CURLOPT_USERAGENT, "User-Agent: Mozilla/5.0 (Windows NT 5.1; rv:10.0.2) Gecko/20100101 Firefox/10.0.2");

    //Specify the HTTP Method
    if (bricolo.etape == 1) {
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_HTTPGET, m_post);
    }
    else {
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_HTTPPOST, m_post);
    }

    //Excution de la requte (envoi du fichier et rception du lien)
    //cout << "Curl :: Demarrage de la requete.." << endl;
    hResult = curl_easy_perform(m_hCurl);

    curl_easy_cleanup(m_hCurl);
    // Ces 2 lignes qui suivent, apparaissent dans Valgrind. pourtant c'est dans la doc de Curl :-( => déplacées dans le destructeur
    //EDIT: corrigé => ne pas libérer m_last !
    curl_formfree(m_post);
    curl_global_cleanup();

    finProcedure(hResult);
}

int MainClass::progress_func(void *ptr, double TotalToDownload, double NowDownloaded, double TotalToUpload, double NowUploaded)
{
    // Retour chariot sans saut de ligne
    cout << '\r' << (NowUploaded/(1024*1024)) << "/" << (TotalToUpload/(1024*1024)) << " Mio | ";
    cout << (NowUploaded / TotalToUpload)*100 << " %    ";

    return 0;
}

size_t MainClass::write_data(void *buffer, size_t size, size_t nmemb, void *userdata)
{
    //PS: fonction statique => on ne peut pas se servir des attributs/fonctions/signaux de la classe en cours..
    // Obligé de faire appel à une structure statique pour la remplir et s'en servir...
    stringstream strmResponse;
    size_t nReal = size * nmemb;
    strmResponse << string((char*)buffer, nReal);
    string sLine("");
    string temp;

    while (getline(strmResponse, sLine)) {
        //utiliser la surcharge += ? => si jamais la réponse fait plusieurs lignes ...
        temp += sLine.c_str();
    }

    // V2 json
    bool ok;
    Json::Value root;   // will contains the root value after parsing.
    Json::Reader reader;

    if (bricolo.etape == 0) { // Connexion
        ok = reader.parse(temp, root);
        if (ok == true) {
            // Récupération du statut
            string objet = root.get("error", "").asString();

            //cout << "Connexion :: Statut :" << objet << endl;
            if (objet == "success") {
                // Succès certain

                // Récupération de l'id
                objet = convertInt( root.get("user", 0).asInt() );
                //cout << "Connexion :: Id utilisateur :" << objet << endl;
                bricolo.loginId = objet;
                etatConnexion = Ok;
            }
            else {
                //"bad username OR bad password"
                // Echec certain
                etatConnexion = Bad;
            }
        }
        else {
            // report to the user the failure and their locations in the document.
            cout  << "Failed to parse configuration\n"
                       << reader.getFormatedErrorMessages();
            etatConnexion = Error;
        }
    }
    else if (bricolo.etape == 1) { // Sélection du serveur
        ok = reader.parse(temp, root);
        if (ok == true) {
            // Récupération du statut
            string objet = root.get("error", "").asString();

            //cout << "SelectionServeur :: Statut :" << objet << endl;
            if (objet == "success") {
                // Succès certain
                bricolo.adresseIp = root.get("server", "").asString();

                //cout << "SelectionServeur :: Serveur" << bricolo.adresseIp  << "trouve !" << endl;
                etatConnexion = Ok;
            }
            else {
                // Echec certain
                etatConnexion = Bad;
            }
        }
        else {
            // report to the user the failure and their locations in the document.
            cout  << "Failed to parse configuration\n"
                       << reader.getFormatedErrorMessages();
            etatConnexion = Error;
        }
    }
    else if (bricolo.etape == 2) { // Récupération des hébergeurs
        ok = reader.parse(temp, root);
        if (ok == true) {
            // Récupération du statut
            string objet = root.get("error", "").asString();

            cout << "Hebergeurs :: Statut :" << objet << endl;

            if (objet == "success") {
                // Succès certain
                vector<string> members = root["hosts"].getMemberNames();
                vector<string>::iterator iterator;

                for (iterator=members.begin(); iterator!=members.end(); ++iterator)
                {
                    //cout << *iterator << endl;
                    bricolo.hebergeursListe.push_back(*iterator);
                }

                etatConnexion = Ok;
            }
            else {
                // Echec certain
                etatConnexion = Bad;
            }
        }
        else {
            // report to the user the failure and their locations in the document.
            cout  << "Failed to parse configuration\n"
                       << reader.getFormatedErrorMessages();
            etatConnexion = Error;
        }
    }
    else if (bricolo.etape == 3) { // Upload
        // Suppression de [,] aux extremite pour transformer l'array en objet
        /*
        temp.remove(0,1);
        temp.remove(temp.size()-1,1);
        */

        temp.erase(0, 1);
        temp.erase(temp.size()-1, 1);

        ok = reader.parse(temp, root);
        if (ok == true) {
            // Récupération du statut
            string objet = root.get("url", "").asString();

            cout << endl << "Upload :: Lien : ";
            cerr << objet << endl;

            bricolo.lien = objet;

            objet = root.get("delete_url", "").asString();
            cout << "Upload :: LienDelete : ";
            cerr << objet << endl;

            bricolo.lienDelete = objet;
            etatConnexion = Ok;
        }
        else {
            // Echec certain
            etatConnexion = Bad;
            // PS: pas d'objet "error" ici..
            // report to the user the failure and their locations in the document.
            cout << "Failed to parse configuration\n"
                       << reader.getFormatedErrorMessages();
        }
    }
    return nReal;
}

void MainClass::finProcedure(CURLcode hResult)
{
    switch(hResult)
    {
        case CURLE_OK:                  //cout << "Curl :: Termine sans erreur" << endl;
                                        break;

        default:                        cout << "Curl :: Erreur " << hResult << endl;
                                        break;
    }

    if (bricolo.etape == 0) {
        switch(etatConnexion)
        {
            case Bad:   cout << "Connexion :: Mauvais login ou mauvais mot de passe => Upload Anonyme" << endl;
                        m_connecte = false;
                        break;

            case Ok:    cout << "Connexion :: Upload en tant que " << m_login << endl;
                        // Pas de destruction car le processus va tenter de lui meme une obtention des droits sur debridpowa
                        m_connecte = true;
                        break;

            default:    cout << "Connexion :: Verifiez votre connexion internet ou la disponibilite du site... => Upload Anonyme" << endl;
                        m_connecte = false;
                        // on arrete pas le programme car le login n'est pas obligatoire;
                        //même si dans ce cas on sait très bien que la liaison avec le site a un problème...
                        break;
        }
        return;
    }
    else if (bricolo.etape == 1) {
        switch (etatConnexion) {

            case Bad:   cout << "SelectionServeur :: Pas d'adresse IP trouvee" << endl;
                        return;
                        break;

            case Ok:    //cout << "SelectionServeur :: Adresse IP trouvee" << endl;
                        break;

            default:    cout << "SelectionServeur :: Erreur inconnue" << endl;
                        return;
                        break;
        }
        bricolo.etape++;
        connexion();
        return;
    }
    else if (bricolo.etape == 2) {
        switch (etatConnexion) {

            case Bad:   cout << "Hebergeurs :: Pas d'hebergeurs trouves" << endl;
                        return;
                        break;

            case Ok:    //cout << "Hebergeurs :: trouves" << endl;
                        break;

            default:    cout << "Hebergeurs :: Erreur inconnue" << endl;
                        return;
                        break;
        }
        bricolo.etape++;
        connexion();
        return;
    }
    else if (bricolo.etape == 3) {
        switch (etatConnexion) {

            case Bad:   cout << endl << "Upload :: Pas d'url trouvee" << endl << endl;
                        break;

            case Ok:    cout << endl << "Upload :: Termine" << endl << endl;
                        break;

            default:    cout << endl << "Upload :: Erreur inconnue" << endl << endl;
                        break;
        }
        //cout << "Upload :: Fichier suivant..." << endl;
        return;
    }
}

string convertInt(int number)
{
    // créer un flux de sortie
    ostringstream oss;
    // écrire un nombre dans le flux
    oss << number;
    // récupérer une chaîne de caractères
     return oss.str();
}
