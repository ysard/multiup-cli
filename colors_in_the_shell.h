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

    Copyright 2013-2023 Lex
    www.multiup.org
*/
#ifndef COLORS_IN_THE_SHELL
#define COLORS_IN_THE_SHELL

#include <sstream>
#include <iostream>

#include "Config.h"

#ifdef WINDOWS
    // WinApi header
	//#include <winsock2.h>
	#define _WINSOCKAPI_    // stops windows.h including winsock.h
    #include <windows.h>
#endif

std::string putInRed(std::string st);
std::string putInGreen(std::string st);
std::string putInBlink(std::string st);
std::string putBgInRed(std::string st);

#endif // COLORS_IN_THE_SHELL
