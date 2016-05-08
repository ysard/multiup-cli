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


MainClass::MainClass(const bool viewOnly, const list<string> &listeFichiers, const std::list<string> &listeHosts)
{
    m_listeFichiers     = listeFichiers;
    m_connecte          = false;
    m_viewOnly          = viewOnly;
    m_listeHosts        = listeHosts;

    m_processingStep    = 1;
}

MainClass::MainClass(const string &login, const string &password, const bool viewOnly, const list<string> &listeFichiers, const std::list<string> &listeHosts)
{
    m_login             = login;
    m_password          = password;

    m_listeFichiers     = listeFichiers;
    m_connecte          = true;
    m_viewOnly          = viewOnly;
    m_listeHosts        = listeHosts;

    m_processingStep   = 0;

    // Etape de login (m_processingStep = 0)
    connexion();
}

MainClass::~MainClass()
{
    // E.Valls's brain:
}

void MainClass::lancement()
{
    //afficher();

    // Upload des fichiers les uns après les autres
    list<string>::iterator iterator;
    for (iterator=m_listeFichiers.begin(); iterator!=m_listeFichiers.end(); ++iterator)
    {
        // Mémorise le fichier courant
        m_fichierEnCours = *iterator;
        cout << "Fichier en cours d'up : " << m_fichierEnCours << endl;

        // Initialisation de la structure
        m_hebergeursListe.clear();

        // Début du traitement du fichier
        m_processingStep = 1;
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
}

void MainClass::connexion()
{
    // Vidage du buffer remplit par le callback de Curl (CURLOPT_WRITEFUNCTION)
    bricolo.dataBuffer = "";

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
    if (m_processingStep == 0) { // Connexion
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
    else if (m_processingStep == 1) { // Sélection du serveur

        //Specify the API Endpoint
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_URL, URL_SELECTION_SERVEUR);

        //Progression désactivée
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_NOPROGRESS, 1);
    }
    else if (m_processingStep == 2) { // Récupération des hébergeurs

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
    else if (m_processingStep == 3) { // Upload
        // Ajoute le nom d'utilisateur à la requête de curl (v2)
        if (m_connecte == true) {
            //cout << "Curl :: Login : " << m_login << endl;

            curl_formadd(&m_post,
                         &m_last,
                         CURLFORM_COPYNAME,
                         "user",
                         CURLFORM_COPYCONTENTS,
                         m_loginId.c_str(),
                         CURLFORM_END);
        }

        list<string>::iterator iterator;
        string hebergeur;
        for (iterator=m_hebergeursListe.begin(); iterator!=m_hebergeursListe.end(); ++iterator)
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
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_URL, m_fastestServerUrl.c_str());

        //Progression activée et fonction
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_NOPROGRESS, 0);
        hResult = curl_easy_setopt(m_hCurl, CURLOPT_PROGRESSFUNCTION, &progress_func);
    }

    //Récupération de la réponse du serveur
    hResult = curl_easy_setopt(m_hCurl, CURLOPT_WRITEFUNCTION, write_data);

    //UserAgent
    hResult = curl_easy_setopt(m_hCurl, CURLOPT_USERAGENT, "User-Agent: Mozilla/5.0 (Windows NT 5.1; rv:10.0.2) Gecko/20100101 Firefox/10.0.2");

    //Specify the HTTP Method
    if (m_processingStep == 1) {
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
    UNUSED(ptr);
    UNUSED(TotalToDownload);
    UNUSED(NowDownloaded);

    // Retour chariot sans saut de ligne
    cout << '\r' << (NowUploaded/(1024*1024)) << "/" << (TotalToUpload/(1024*1024)) << " Mio | ";
    cout << (NowUploaded / TotalToUpload)*100 << " %    ";

    return 0;
}

size_t MainClass::write_data(void *buffer, size_t size, size_t nmemb, void *userdata)
{
    UNUSED(userdata);

    //PS: fonction statique => on ne peut pas se servir des attributs/fonctions/signaux de la classe en cours..
    // Obligé de faire appel à une structure statique pour la remplir et s'en servir...
    stringstream strmResponse;
    size_t nReal = size * nmemb;
    strmResponse << string((char*)buffer, nReal);
    string sLine("");

    while (getline(strmResponse, sLine)) {
        //utiliser la surcharge += ? => si jamais la réponse fait plusieurs lignes ...
        bricolo.dataBuffer += sLine.c_str();
    }

    //cout << "Curl :: Write data :: " << bricolo.dataBuffer << endl;
    return nReal;
}

MainClass::EtatConnexion MainClass::connectionDataProcessing()
{

    // will contain state of JSON parser
    bool            parsing_state;
    // will contain the root value after parsing
    Json::Value     root;
    Json::Reader    reader;

    parsing_state = reader.parse(bricolo.dataBuffer, root);

    if (parsing_state == true) {
        // Récupération du statut
        string objet = root.get("error", "").asString();

        //cout << "Connexion :: Statut : " << objet << endl;
        if (objet == "success") {
            // Succès certain

            // Récupération de l'id
            m_loginId = root.get("user", 0).asString();
            //cout << "Connexion :: Id utilisateur : " << m_loginId << endl;

            return EtatConnexion::Ok;
        }
        else {
            //"bad username OR bad password"
            // Echec certain
            return EtatConnexion::Bad;
        }
    }
    else {
        // report to the user the failure and their locations in the document.
        cout  << "Failed to parse configuration\n"
              << reader.getFormattedErrorMessages() + '\n'
              << root;
        return EtatConnexion::Error;
    }
}

MainClass::EtatConnexion MainClass::fastestServerDataProcessing()
{
    // will contain state of JSON parser
    bool            parsing_state;
    // will contain the root value after parsing
    Json::Value     root;
    Json::Reader    reader;

    parsing_state = reader.parse(bricolo.dataBuffer, root);

    if (parsing_state == true) {
        // Récupération du statut
        string objet = root.get("error", "").asString();

        //cout << "SelectionServeur :: Statut : " << objet << endl;
        if (objet == "success") {
            // Succès certain
            m_fastestServerUrl = root.get("server", "").asString();

            //cout << "SelectionServeur :: Serveur " << m_fastestServerUrl  << " trouve !" << endl;
            return EtatConnexion::Ok;
        }
        else {
            // Echec certain
            return EtatConnexion::Bad;
        }
    }
    else {
        // report to the user the failure and their locations in the document.
        cout  << "Failed to parse configuration\n"
              << reader.getFormattedErrorMessages() + '\n'
              << root;
        return EtatConnexion::Error;
    }
}

MainClass::EtatConnexion MainClass::webhostsDataProcessing()
{

    // will contain state of JSON parser
    bool            parsing_state;
    // will contain the root value after parsing
    Json::Value     root;
    Json::Reader    reader;

    parsing_state = reader.parse(bricolo.dataBuffer, root);

    if (parsing_state == true) {
        // Récupération du statut
        string objet = root.get("error", "").asString();

        //cout << "Hebergeurs :: Statut : " << objet << endl;

        if (objet == "success") {
            // Succès certain
            /* Objet "hosts":
            {
                "error":"success",
                "hosts":
                        {
                            "1fichier.com": {
                                                "selected":"true",
                                                "size":5120
                                            },
                            "easybytez.com":{
                                                "selected":"false",
                                                "size":5120
                                            }
                        },
                "default":
                        [
                            "dl.free.fr",
                            "uptobox.com",
                        ],
                "maxHosts":18
            }
            */
#ifdef WINDOWS
            cout << "Selectionne : [";
            putInGreen("true");
            cout << "]; Deselectionne : [";
            putInRed("false");
            cout  << "]; Taille excessive : [";
            putBgInRed("false");
            cout << "];"
                 << endl;
#else
            cout << "Selectionne : [" << putInGreen("true") << "]; "
                 << "Deselectionne : [" << putInRed("false") << "]; "
                 << "Taille excessive : [" << putBgInRed("false") << "];"
                 << endl;
#endif

            vector<string> members = root["hosts"].getMemberNames();
            vector<string>::iterator iterator;


            // Recherche des hébergeurs spécifiés manuellement.
            if (m_listeHosts.size()) {
                for (iterator=members.begin(); iterator!=members.end(); ++iterator)
                {
                    bool found = (std::find(m_listeHosts.begin(), m_listeHosts.end(), *iterator) != m_listeHosts.end());

                    // Si un hébergeur officiel n'est pas dans la liste manuelle => on le passe à false
                    // Sinon on l'active => passe à true
                    if (!found)
                        root["hosts"][*iterator]["selected"] = "false";
                    else
                        root["hosts"][*iterator]["selected"] = "true";
                }
            }


            // Récupération de la taille du fichier courant
            std::streampos fileSize = getFileSize(m_fichierEnCours);

            for (iterator=members.begin(); iterator!=members.end(); ++iterator)
            {
                /* La liste des hébergeurs et leurs états doit être sur 2 colonnes
                 * nomHébergeur tailleMax [etat]; nomHébergeur tailleMax [etat];
                 *
                 * Mise en forme : http://en.cppreference.com/w/cpp/io/manip/setw
                 * stew() définit le nombre de caractères de l'élément qui suit
                 * left permet d'aligner à gauche l'élément qui suit (par défaut à droite)
                 */

                // Nom1
                cout << setw(19) << left << *iterator;
                // Etat1
                bool ret = webhostParsing(root["hosts"][*iterator], fileSize);
                // Hébergeur1 autorisé
                if (ret)
                    m_hebergeursListe.push_back(*iterator);

                // Hébergeur suivant
                ++iterator;
                if (iterator == members.end()) {
                    cout << endl;
                    break;
                }

                // Nom2
                cout << setw(6) << ' '
                     << setw(19) << *iterator;
                // Etat2
                ret = webhostParsing(root["hosts"][*iterator], fileSize);
                cout << endl;
                // Hébergeur2 autorisé
                if (ret)
                    m_hebergeursListe.push_back(*iterator);
            }

            // Transtypage pour la comparaison juste après...
            std::vector<int>::size_type maxHosts = (std::vector<int>::size_type)root.get("maxHosts", 100).asInt();
            cout << "Hebergeurs :: Nombre selectionnes : " << m_hebergeursListe.size() << '/' << maxHosts << endl;

            if (m_hebergeursListe.size() > maxHosts)
                cout << "Hebergeurs :: /!\\ Trop d'hebergeurs selectionnes : Resultats non garantis" << endl;

            return EtatConnexion::Ok;
        }
        else {
            // Echec certain
            return EtatConnexion::Bad;
        }
    }
    else {
        // report to the user the failure and their locations in the document.
        cout  << "Failed to parse configuration\n"
              << reader.getFormattedErrorMessages() + '\n'
              << root;
        return EtatConnexion::Error;
    }
}

MainClass::EtatConnexion MainClass::uploadDataProcessing()
{

    // will contain state of JSON parser
    bool            parsing_state;
    // will contain the root value after parsing
    Json::Value     root;
    Json::Reader    reader;

    // Suppression de [,] aux extremite pour transformer l'array en objet JSON correct...
    /*
      [
        {
                "delete_type" : "DELETE",
                "delete_url" : "http://barbie.multiup.org/upload/?file=test.txt",
                "hash" : "7de6e976e6e8bd7183bf008e39f20d9e",
                "hashUpload" : "",
                "md5" : ".",
                "name" : "test.txt",
                "sha" : ".",
                "sid" : "",
                "size" : 7,
                "type" : "text/plain",
                "url" : "http://www.multiup.org/download/7de6e976e6e8bd7183bf008e39f20d9e/test.txt",
                "user" : "1111"
        }
      ]
    */
    bricolo.dataBuffer.erase(0, 1);
    bricolo.dataBuffer.erase(bricolo.dataBuffer.size()-1, 1);

    parsing_state = reader.parse(bricolo.dataBuffer, root);

    if (parsing_state == true) {
        // Récupération du statut
        m_finalLink = root.get("url", "").asString();

        // Affichage sur std et stderr
        cout << endl << "Upload :: Lien : ";
        cerr << m_finalLink << endl;

        return EtatConnexion::Ok;
    }
    else {
        // Echec certain
        return EtatConnexion::Bad;
        // PS: pas d'objet "error" ici..
        // report to the user the failure and their locations in the document.
        cout << "Failed to parse configuration\n"
             << reader.getFormattedErrorMessages() + '\n'
             << root
             << endl;
    }
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

    if (m_processingStep == 0) {
        EtatConnexion etatConnexion = connectionDataProcessing();

        switch(etatConnexion)
        {
            case EtatConnexion::Bad:
                        cout << "Connexion :: Mauvais login ou mauvais mot de passe => Upload Anonyme" << endl;
                        m_connecte = false;
                        break;

            case EtatConnexion::Ok:
                        cout << "Connexion :: Upload en tant que " << m_login << endl;
                        // Pas de destruction car le processus va tenter de lui meme une obtention des droits sur debridpowa
                        m_connecte = true;
                        break;

            default:
                        cout << "Connexion :: Verifiez votre connexion internet ou la disponibilite du site... => Upload Anonyme" << endl;
                        m_connecte = false;
                        // on arrete pas le programme car le login n'est pas obligatoire;
                        //même si dans ce cas on sait très bien que la liaison avec le site a un problème...
                        break;
        }
        return;
    }
    else if (m_processingStep == 1) {
        EtatConnexion etatConnexion = fastestServerDataProcessing();

        switch (etatConnexion) {

            case EtatConnexion::Bad:
                        cout << "SelectionServeur :: Pas de serveur trouve" << endl;
                        return;
                        break;

            case EtatConnexion::Ok:
                        //cout << "SelectionServeur :: Serveur trouve" << endl;
                        break;

            default:    cout << "SelectionServeur :: Erreur inconnue" << endl;
                        return;
                        break;
        }
        m_processingStep++;
        connexion();
        return;
    }
    else if (m_processingStep == 2) {
        EtatConnexion etatConnexion = webhostsDataProcessing();

        switch (etatConnexion) {

            case EtatConnexion::Bad:
                        cout << "Hebergeurs :: Pas d'hebergeurs trouves" << endl;
                        return;
                        break;

            case EtatConnexion::Ok:
                        //cout << "Hebergeurs :: trouves" << endl;
                        break;

            default:    cout << "Hebergeurs :: Erreur inconnue" << endl;
                        return;
                        break;
        }

        if (m_viewOnly) {
            cout << "Fin de simulation pour ce fichier" << endl << endl;
            return;
        }

        m_processingStep++;
        connexion();
        return;
    }
    else if (m_processingStep == 3) {
        EtatConnexion etatConnexion = uploadDataProcessing();

        switch (etatConnexion) {

            case EtatConnexion::Bad:
                        cout << endl << "Upload :: Pas d'url trouvee" << endl << endl;
                        break;

            case EtatConnexion::Ok:
                        cout << endl << "Upload :: Termine" << endl << endl;
                        break;

            default:    cout << endl << "Upload :: Erreur inconnue" << endl << endl;
                        break;
        }
        //cout << "Upload :: Fichier suivant..." << endl;
        return;
    }
}


bool webhostParsing(const Json::Value webhost, const std::streampos file_size)
{
    /*
     * Met en forme un hébergeur (affichage dans la console de la taille et de l'état de sélection)
     * et retourne true ou false selon que l'hébergeur doit être ajouté à la liste ou non.
     *
     * Un hébergeur sélectionné mais n'acceptant pas la taille du fichier proposée sera
     * affiché différemment des autres
     */


    // Récupération de l'état de sélection et de la taille max autorisée sur cet hébergeur
    string selection_state = webhost.get("selected", "false").asString();
    std::streampos max_upload_size = (std::streampos)webhost.get("size", 0).asInt();

    // On affiche la taille en premier
    cout << setw(4) << left << convertIntToString(max_upload_size)
         << setw(5) << left << " Mo";

    if (selection_state == "false") {
        // Hébergeur désélectionné => False => lettres rouges
#ifdef WINDOWS
        cout << '[';
        putInRed(selection_state);
        cout << ']'
             << setw(3) << ';';
#else
        cout << setw(10) << '[' + putInRed(selection_state) + ']'
             << setw(3) << ';';
#endif
        return false;

    } else {
        // Vérification de la taille autorisée
        if (file_size > (std::streampos)(max_upload_size * 1024*1024)) {
            // Taille de fichier excessive => False => fond rouge
#ifdef WINDOWS
            cout << '[';
            putBgInRed("false");
            cout << ']'
                 << setw(3) << ';';
#else
            cout << setw(10) << '[' + putBgInRed("false") + ']'
                 << setw(3) << ';';
#endif
            return false;
        } else {
            // Taille de fichier correcte => True => lettres vertes
#ifdef WINDOWS
            cout << '[';
            putInGreen(selection_state + ' ');
            cout << ']'
                 << setw(3) << ';';
#else
            cout << setw(10) << '[' + putInGreen(selection_state + ' ') + ']'
                 << setw(3) << ';';
#endif
            return true;
        }
    }
}

string convertIntToString(const int &number)
{
    // créer un flux de sortie
    ostringstream oss;
    // écrire un nombre dans le flux
    oss << number;
    // récupérer une chaîne de caractères
     return oss.str();
}

std::streampos getFileSize(const string& filename)
{
    // ios::ate flag, which means that the get pointer will be positioned at the end of the file.
    //This way, when we call to member tellg(), we will directly obtain the size of the file.
    std::ifstream in(filename.c_str(), std::ifstream::ate | std::ifstream::binary);

    if (in.is_open()) {
        std::streampos size = in.tellg();
        in.close();
        //cout << "TAILLE: " << filename << size << endl;
        return size;
    }
    return 0;
}













