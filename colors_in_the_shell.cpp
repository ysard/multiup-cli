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
#include "colors_in_the_shell.h"

using namespace std;


std::string putInRed(std::string st)
{
#ifdef WINDOWS
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 12); //0x0C
    cout << st;
    SetConsoleTextAttribute(hConsole, 15); //0x0F

    return "";
#else
    return "\033[31;1m" + st + "\033[0m";
#endif
}

std::string putInGreen(std::string st)
{
#ifdef WINDOWS
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 10); //0x0A
    cout << st;
    SetConsoleTextAttribute(hConsole, 15); //0x0F

    return "";
#else
    return "\033[32;1m" + st + "\033[0m";
#endif
}

std::string putInBlink(std::string st)
{
    return "\033[5;7m" + st + "\033[0m";
}

std::string putBgInRed(std::string st)
{
#ifdef WINDOWS
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 192); //0xC0
    cout << st;
    SetConsoleTextAttribute(hConsole, 15); //0x0F

    return "";
#else
    return "\033[31;7m" + st + "\033[0m";
#endif
}
