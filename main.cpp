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

#include <iostream>
#include <fstream>
#include <list>
#include "mainClass.h"

using namespace std;

void affichage_syntaxe(string nomApp);

int main(int argc, char *argv[])
{
    string login;
    string password;
    list<string> listeFichier;
    list<string> listHosts;


    string argument;
    bool read(false);
    bool hosts = false;
    bool viewOnly = false;

    cout << "Multiup MaNaGer CLI v" << VERSION << " - Copyright 2013-2015 Lex - Bienvenue !" << endl << endl;
    cout << "\tPour des fonctionnalites plus evoluees, \n\tveuillez vous diriger vers \"Multiup MaNaGer GUI\",\n\tdisponible sur le site..." << endl << endl;

    std::size_t found;

    // Si il y a au moins 1 argument passé en manuel (le premier est toujours le nom de l'application)
    for(int i = 1; i < argc; i++) {

        argument = argv[i];

        // si --read a déjà été trouvé on tente d'ajouter l'argument suivant dans la liste sauf si il s'agit d'un autre paramètre
        if ((argument != "--login") && (argument != "--password") && (argument != "--help") && (argument != "--view") && (argument != "--hosts") && (read == true))
        {
            // Test du fichier
            ifstream fichier(argument.c_str(), ios::in); //ouverture en lecture
            if (fichier) { // ouverture réussie
                fichier.close();

                //cout << "Ajout de : " << argument << endl;

                listeFichier.push_back(argument);
            }
        }
        else { // Autre paramètre détecté => on arrête d'essayer l'ajout des fichier
            read = false;
        }

        // si --hosts a déjà été trouvé on tente d'ajouter l'argument suivant dns la liste sauf si il s'agit d'un autre paramètre
        if ((argument != "--login") && (argument != "--password") && (argument != "--help") && (argument != "--view") && (argument != "--read") && (hosts == true))
        {
            listHosts.push_back(argument);
        }
        else { // Autre paramètre détecté => on arrête d'essayer l'ajout des hosts
            hosts = false;
        }

        //Recherche de l'aide
        found = argument.find("--help");
        if (found != string::npos)
        {
            // Affichage de l'aide
            affichage_syntaxe(argv[0]);
            return 0;
        }

        //Recherche du login
        found = argument.find("--login");
        if (found != string::npos)
        {
            //cout << "Login : " << argv[i+1] << endl;
            login = argv[i+1];
        }

        //Recherche du password
        found = argument.find("--password");
        if (found != string::npos)
        {
            //cout << "Password : " << argv[i+1] << endl;
            password = argv[i+1];
        }

        //Recherche des chemins des fichiers
        found = argument.find("--read");
        if (found != string::npos)
        {
            read = true;
        }

        //Recherche des hosts
        found = argument.find("--hosts");
        if (found != string::npos)
        {
            hosts = true;
        }

        //Recherche du paramètre de simulation d'upload
        found = argument.find("--view");
        if (found != string::npos)
        {
            viewOnly = true;
        }
    }

    //list<string>::iterator it;
    //for (it=listeFichier.begin(); it!=listeFichier.end(); ++it)
    //            cout << " " << *it;

    //list<string>::iterator it;
    //    for (it=listHosts.begin(); it!=listHosts.end(); ++it)
    //                cout << " " << *it;

    if ((login.size() != 0) && (password.size() != 0) && (listeFichier.size() != 0))
    {
        //cout << "Demarrage en mode connecte" << endl;
        MainClass multiup(login, password, viewOnly, listeFichier, listHosts);
        multiup.launch();
        return 0;
    }
    else if ((login.size() == 0) && (password.size() == 0) && (listeFichier.size() != 0))
    {
        //cout << "Demarrage en mode anonyme" << endl;
        MainClass multiup(viewOnly, listeFichier, listHosts);
        multiup.launch();
        return 0;
    }
    else {
        affichage_syntaxe(argv[0]);
    }

    return 0;
}

void affichage_syntaxe(string nomApp)
{
    cout << "Syntaxe:" << endl;
    cout << nomApp;
    cout << " [options...] --read [\"fichier\" \"fichier\"...] --hosts [\"hebergeur\" \"hebergeur\"...] [2>liens.txt]" << endl;

    cout << endl << "Options:" << endl;
            cout << "\t--login <nom> --password <password>" << endl;
            cout << "\t--view\t\tSimulation d'upload (verification des parametres)." << endl;
            cout << "\t--hosts\t\tSpecifier une liste personnelle d'hebergeurs." << endl;
            cout << "\t[2>liens.txt]\tRedirige stderr pour avoir les liens uniquement." << endl << endl;
}
