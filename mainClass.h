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

    Copyright 2013-2016 Lex
    www.multiup.org
*/

#ifndef MAINCLASS_H
#define MAINCLASS_H


#include <sstream>
#include <string>
//#include <iostream>
#include <algorithm>
#include <iomanip>
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

#include "colors_in_the_shell.h"
#include "curl/curl.h"
#include "third-party/jsoncpp/dist/json/json-forwards.h"
#include "third-party/jsoncpp/dist/json/json.h"

// Fix Unused variable warning, usage: UNUSED(x);
#define UNUSED(x) (void)(x)
#define MINIMAL_PROGRESS_FUNCTIONALITY_INTERVAL     1

struct Bricolage
{
    std::string dataBuffer;
};

struct myprogress {
    double lastruntime;
    CURL *curl;
};



std::streampos getFileSize(const std::string& filename);
std::string convertIntToString(const int &number);
bool webhostParsing(const Json::Value webhost, const std::streampos file_size);

class MainClass
{

public:
    enum class EtatConnexion
    {
        Bad, Ok, Error
    };

    //consructeur par def
    MainClass(const bool viewOnly,
              const std::list<std::string> &fileList,
              const std::list<std::string> &hostList);
    //consructeur si identifiants
    MainClass(const std::string &login,
              const std::string &password,
              const bool viewOnly,
              const std::list<std::string> &fileList,
              const std::list<std::string> &hostList);
    virtual ~MainClass();

    static int progress_func(void *ptr,
                             double dltotal, double dlnow,
                             double ultotal, double ulnow);
    static int xferinfo(void *ptr,
                        curl_off_t dltotal, curl_off_t dlnow,
                        curl_off_t ultotal, curl_off_t ulnow);
    static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userdata);

    void launch();
    void printParameters();
    void connection();
    void endProcess(CURLcode hResult);


private:
    EtatConnexion connectionDataProcessing();
    EtatConnexion fastestServerDataProcessing();
    EtatConnexion webhostsDataProcessing();
    EtatConnexion uploadDataProcessing();

    std::string             m_login;
    std::string             m_loginId;
    std::string             m_password;
    bool                    m_connected;
    bool                    m_viewOnly;

    std::string             m_fastestServerUrl;

    std::list<std::string>  m_hostList;
    std::list<std::string>  m_fileList;
    std::list<std::string>  m_listeHosts;
    std::string             m_currentUploadedFile;

    std::string             m_finalLink;

    int                     m_processingStep;
    CURL                    *m_hCurl;
    struct curl_httppost    *m_post;
    struct curl_httppost    *m_last;
};

#endif // MAINCLASS_H
