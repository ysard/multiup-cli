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

#ifndef CONFIG_H
#define CONFIG_H

//#define WINDOWS
//#define LINUX
//#define ENABLE_NLS
//#define LOCALES "/usr/share/locale"
#ifndef VERSION
    #define VERSION "0.4.1"
#endif

// --- Configuration des urls de l'API
#define URL_USER_LOGIN "https://www.multiup.org/api/login"
#define URL_SERVER_SELECTION "https://www.multiup.org/api/get-fastest-server"
#define URL_GET_UP_RIGHTS "https://www.multiup.org/api/get-list-hosts"

#endif // CONFIG_H
