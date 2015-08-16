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

#ifndef MAINCLASS_H
#define MAINCLASS_H


#include <sstream>
#include <string>
//#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include "curl/curl.h"
#include "Config.h"
#include "colors_in_the_shell.h"

#include "dependances-developpement/jsoncpp/dist/json/json-forwards.h"
#include "dependances-developpement/jsoncpp/dist/json/json.h"

// Fix Unused variable warning, usage: UNUSED(x);
#define UNUSED(x) (void)(x)

struct Bricolage
{
    int etape;
    std::string loginId;
    std::string adresseIp;
    std::list<std::string> hebergeursListe;
    std::string fichierEnCours;

    std::string lien;
    std::string lienDelete;
};

enum EtatConnexion
{
    Bad, Ok, Error
};



std::streampos getFileSize(const std::string& filename);
std::string convertIntToString(const int &number);
bool webhostParsing(const Json::Value webhost, const std::streampos file_size);

class MainClass
{

public:
    MainClass(const std::list<std::string> &listeFichiers); //consructeur par def
    MainClass(const std::string &login, const std::string &password, const std::list<std::string> &listeFichiers); //consructeur si identifiants
    virtual ~MainClass();
    static int progress_func(void *ptr, double TotalToDownload, double NowDownloaded, double TotalToUpload, double NowUploaded);
    static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userdata);
    void lancement();
    void afficher();
    void connexion();

    void finProcedure(CURLcode hResult);


private:
    std::string             m_login;
    std::string             m_password;
    std::list<std::string>  m_listeFichiers;
    std::string             m_fichierEnCours;

    bool                    m_connecte;
    CURL                    *m_hCurl;
    struct curl_httppost    *m_post;
    struct curl_httppost    *m_last;
};

#endif // MAINCLASS_H
