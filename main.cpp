/*
This file is part of multiup-cli.

    multiup-cli is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    multiup-cli is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with multiup-cli.  If not, see <http://www.gnu.org/licenses/>.

    Copyright 2013-2016 Lex
    www.multiup.org
*/

#include <iostream>
// Note : If you can't compile this with Qt due to error in header iostream, do this:
//sudo apt-get install gcc-4.9-multilib
#include <fstream>
#include <list>

#include "Config.h"

// Internationalization dependencies
#ifdef ENABLE_NLS
#include <libintl.h>
#include <locale.h>
#define _(STRING) gettext(STRING)
#else
#define _(STRING) STRING
#endif

#include "mainClass.h"

using namespace std;

void display_help(string nomApp);

int main(int argc, char *argv[])
{
    string login;
    string password;
    string outputLinks;
    list<string> fileList;
    list<string> hostList;

    #ifdef ENABLE_NLS
    //~ i18n: initializes the entire current locale of the program as per environment variables set by the user
    //setlocale(LC_ALL, "en_GB");
    //~ i18n: Indicate the path of the i18n catalog file
    // The section "multiup-cli" of this catalog will be called
    bindtextdomain("multiup-cli", LOCALES);
    //~ i18n: sets the message domain
    textdomain("multiup-cli");
    #endif


    string argument;
    bool read(false);
    bool hosts = false;
    bool viewOnly = false;
    bool output = false;

    cout << "Multiup MaNaGer CLI v" VERSION << _(" - Copyright 2013-2023 Lex - Bienvenue !") << endl << endl;
    cout << _("\tPour des fonctionnalités plus evoluées, \n\tveuillez vous diriger vers \"Multiup MaNaGer GUI\",\n\tdisponible sur https://github.com/ysard/MultiupMaNaGeR") << endl << endl;

    std::size_t found;

    // Si il y a au moins 1 argument passé en manuel (le premier est toujours le nom de l'application)
    for(int i = 1; i < argc; i++) {

        argument = argv[i];

        // si --read a déjà été trouvé on tente d'ajouter l'argument suivant dans la liste sauf si il s'agit d'un autre paramètre
        if ((argument != "--login") && (argument != "--password") && (argument != "--help") && (argument != "--view") && (argument != "--output") && (argument != "--hosts") && (read == true))
        {
            // Test du fichier
            ifstream file(argument.c_str(), ios::in); //ouverture en lecture
            if (file) { // ouverture réussie
                file.close();

                //cout << "Ajout de : " << argument << endl;

                fileList.push_back(argument);
            }
        }
        else { // Autre paramètre détecté => on arrête d'essayer l'ajout des fichier
            read = false;
        }

        // si --hosts a déjà été trouvé on tente d'ajouter l'argument suivant dns la liste sauf si il s'agit d'un autre paramètre
        if ((argument != "--login") && (argument != "--password") && (argument != "--help") && (argument != "--view") && (argument != "--output") && (argument != "--read") && (hosts == true))
        {
            hostList.push_back(argument);
        }
        else { // Autre paramètre détecté => on arrête d'essayer l'ajout des hosts
            hosts = false;
        }

        //Recherche de l'aide
        found = argument.find("--help");
        if (found != string::npos)
        {
            // Affichage de l'aide
            display_help(argv[0]);
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

        // Recherche du fichier de liens
        found = argument.find("--output");
        if (found != string::npos)
        {
            //cout << "Output : " << argv[i+1] << endl;
            outputLinks = argv[i+1];
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
    //for (it=fileList.begin(); it!=fileList.end(); ++it)
    //            cout << " " << *it;

    //list<string>::iterator it;
    //    for (it=hostList.begin(); it!=hostList.end(); ++it)
    //                cout << " " << *it;

    if ((login.size() != 0) && (password.size() != 0) && (fileList.size() != 0))
    {
        //cout << "Demarrage en mode connecte" << endl;
        MainClass multiup(login, password, outputLinks, viewOnly, fileList, hostList);
        multiup.launch();
        return 0;
    }
    else if ((login.size() == 0) && (password.size() == 0) && (fileList.size() != 0))
    {
        //cout << "Demarrage en mode anonyme" << endl;
        MainClass multiup(outputLinks, viewOnly, fileList, hostList);
        multiup.launch();
        return 0;
    }
    else {
        display_help(argv[0]);
    }

    return 0;
}

void display_help(string nomApp)
{
    cout << _("Syntaxe:") << endl;
    cout << nomApp;
    cout << _(" [options...] --read [\"fichier\" \"fichier\"...] --hosts [\"hébergeur\" \"hébergeur\"...] [2>liens.txt]") << endl;

    cout << endl << _("Options:") << endl;
            cout << _("\t--login <nom> --password <password>") << endl;
            cout << _("\t--view\t\tSimulation d'upload (vérification des paramètres).") << endl;
            cout << _("\t--hosts\t\tSpécifier une liste personnelle d'hébergeurs.") << endl;
            cout << _("\t--output\tEnregistre les liens dans le fichier choisi.") << endl;
            cout << _("\t--read\t\tEnvoyer un ou plusieurs fichiers.") << endl;
            cout << _("\t[2>liens.txt]\tRedirige stderr pour avoir les liens uniquement.") << endl << endl;
}
