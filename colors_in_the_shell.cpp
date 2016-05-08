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
