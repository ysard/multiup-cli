#include "colors_in_the_shell.h"


std::string putInRed(std::string st)
{
    return "\033[31;1m" + st + "\033[0m";
}

std::string putInGreen(std::string st)
{

    return "\033[32;1m" + st + "\033[0m";
}

std::string putInBlink(std::string st)
{
    return "\033[5;7m" + st + "\033[0m";
}

std::string putBgInRed(std::string st)
{
    return "\033[31;7m" + st + "\033[0m";
}
