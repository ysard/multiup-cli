#This file is part of multiup-cli.
#
#    multiup-cli is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    multiup-cli is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with multiup-cli.  If not, see <http://www.gnu.org/licenses/>.
#
#    Copyright 2013-2016 Lex
#    www.multiup.org

#-------------------------------------------------
#
# Project created by QtCreator 2013-01-27T12:56:28
#
#-------------------------------------------------

CONFIG -= qt
TARGET = multiup-cli
CONFIG += console
CONFIG += c++11
#CONFIG   -= app_bundle

TEMPLATE = app

#CURL unix
#unix:INCLUDEPATH += /usr/include/curl
unix:INCLUDEPATH    += ./third-party/curl-7.44.0-devel-unix-static/include
unix:LIBS           += -L"./third-party/curl-7.44.0-devel-unix-static/lib"
unix:LIBS           += -lcurl
#  -lidn -lssl -lcrypto -lz
#-lidn -lssl -lcrypto -lrt -lssl -lz -lrtmp (selon les restrictions lors de la compilation de curl..)


#CURL windows
# Avec mingw32 :
win32:INCLUDEPATH   += D:\Projets\multiup\multiup_cli\third-party\curl-7.28.1-devel-mingw32\include
win32:INCLUDEPATH   += D:\Projets\multiup\multiup_cli\third-party\curl-7.28.1-devel-mingw32\include\curl
win32:LIBS          += -L"D:\Projets\multiup\multiup_cli\third-party\curl-7.28.1-devel-mingw32\lib"
#revoir la lib ici..-lws2_32  ptetre aussi... -lwldap32 ??
win32:LIBS          += -lcurl -lwldap32 -lws2_32


# Pour les libraries CURL en static
DEFINES += CURL_STATICLIB
DEFINES += HTTP_ONLY


#JSON CPP
# amalgamate

SOURCES +=  main.cpp \
            mainClass.cpp \
            third-party/jsoncpp/dist/jsoncpp.cpp \
            colors_in_the_shell.cpp

HEADERS +=  mainClass.h \
            Config.h \
            third-party/jsoncpp/dist/json/json-forwards.h \
            third-party/jsoncpp/dist/json/json.h \
            colors_in_the_shell.h
