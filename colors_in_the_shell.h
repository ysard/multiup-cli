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
