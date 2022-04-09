#include "BoardPrinter.h"
#include "Logger.h"

void BoardPrinter::printBoard(const std::string& _notation)
{
    printTopFrame();
    printRow(_notation.substr(0, 9));
    printRow(_notation.substr(9, 9));
    printRow(_notation.substr(18, 9));
    printMiddleFrame();
    printRow(_notation.substr(27, 9));
    printRow(_notation.substr(36, 9));
    printRow(_notation.substr(45, 9));
    printMiddleFrame();
    printRow(_notation.substr(54, 9));
    printRow(_notation.substr(63, 9));
    printRow(_notation.substr(72, 9));
    printBottomFrame();
}

void BoardPrinter::printRow(const std::string& _str)
{
    std::string str{};
    str += "|";
    for (size_t i = 0; i < 17; ++i)
    {
        if (i == 0 or !(i % 2))
            if(_str[i / 2] == '0')
                str += ".";
            else
                str += _str[i / 2];
        else if (i == 5 or i == 11)
            str += "|";
        else
            str += " ";
    }
    str += "|";
    Log(str);
}

void BoardPrinter::printTopFrame()
{
    std::string str{};
    for (size_t i = 0; i < 19; ++i)
    {
        if (i == 0 or !(i % 6))
            str += ".";
        else
            str += "-";
    }
    Log(str);
}

void BoardPrinter::printMiddleFrame()
{
    std::string str{};
    for (size_t i = 0; i < 19; ++i)
    {
        if (i == 0 or i == 18)
            str += ":";
        else if (!(i % 6))
            str += " ";
        else
            str += "-";
    }
    Log(str);
}

void BoardPrinter::printBottomFrame()
{
    std::string str{};
    for (size_t i = 0; i < 19; ++i)
    {
        if (i == 0 or !(i % 6))
            str += "'";
        else
            str += "-";
    }
    Log(str);
}


