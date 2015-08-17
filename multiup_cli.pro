#This file is part of multiup_cli.
#
#    multiup_cli is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    multiup_cli is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with multiup_cli.  If not, see <http://www.gnu.org/licenses/>.
#
#    Copyright 2013 Lex
#    www.multiup.org

#-------------------------------------------------
#
# Project created by QtCreator 2013-01-27T12:56:28
#
#-------------------------------------------------

CONFIG -= qt

#QT       += core
#QT       -= gui

TARGET = multiup_cli
CONFIG += console
CONFIG += c++11
#CONFIG   -= app_bundle

TEMPLATE = app

#CURL unix
#unix:INCLUDEPATH += /usr/include/curl
unix:INCLUDEPATH += ./dependances-developpement/curl-7.44.0-devel-unix-static/include
unix:LIBS += -L"./dependances-developpement/curl-7.44.0-devel-unix-static/lib"
unix:LIBS += -lcurl
#  -lidn -lssl -lcrypto -lz
#-lidn -lssl -lcrypto -lrt -lssl -lz -lrtmp (selon les restrictions lors de la compilation de curl..)


#CURL windows
# Avec mingw32 :
win32:INCLUDEPATH += .\dependances-developpement\curl-7.28.1-devel-mingw32\include
win32:LIBS += -L".\dependances-developpement\curl-7.28.1-devel-mingw32\lib"
#revoir la lib ici..-lws2_32  ptetre aussi... -lwldap32 ??
win32:LIBS += -lcurl -lwldap32 -lws2_32


# Pour les libraries CURL en static
DEFINES += CURL_STATICLIB
DEFINES += HTTP_ONLY


#JSON CPP
# Avec mingw32 :
win32:INCLUDEPATH += .\dependances-developpement\jsoncpp-static-mingw32\include
win32:LIBS += -L".\dependances-developpement\jsoncpp-static-mingw32\lib" -ljson_mingw_libmt

#unix:INCLUDEPATH += ./dependances-developpement/jsoncpp-static-unix/include
#unix:LIBS += -L"./dependances-developpement/jsoncpp-static-unix/lib" -ljson_linux-gcc-4.4.3_libmt

SOURCES +=  main.cpp \
            mainClass.cpp \
    dependances-developpement/jsoncpp/dist/jsoncpp.cpp \
    colors_in_the_shell.cpp

HEADERS +=  mainClass.h \
            Config.h \
    dependances-developpement/jsoncpp/dist/json/json-forwards.h \
    dependances-developpement/jsoncpp/dist/json/json.h \
    colors_in_the_shell.h
