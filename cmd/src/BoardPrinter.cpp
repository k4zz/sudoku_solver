#include "BoardPrinter.h"
#include "Logger.h"

void BoardPrinter::printBoard(const Board& _board)
{
    printTopFrame();
    printRow(_board.getRow(0));
    printRow(_board.getRow(1));
    printRow(_board.getRow(2));
    printMiddleFrame();
    printRow(_board.getRow(3));
    printRow(_board.getRow(4));
    printRow(_board.getRow(5));
    printMiddleFrame();
    printRow(_board.getRow(6));
    printRow(_board.getRow(7));
    printRow(_board.getRow(8));
    printBottomFrame();
}

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

void BoardPrinter::printRow(const std::vector<const Cell*>& _row)
{
    std::string str{};
    str += "|";
    for (size_t i = 1; i <= _row.size(); ++i)
    {
        std::string val{};
        if (_row.at(i - 1)->value != 0)
            val = std::to_string(_row.at(i - 1)->value);
        else
            val = ".";

        str += val;
        if (i != 0 and !(i % 3))
            str += "|";
        else
            str += " ";
    }
    Log(str);
}

void BoardPrinter::printRow(const std::string& _str)
{
    std::string str{};
    str += "|";
    for (size_t i = 0; i < 17; ++i)
    {
        if (i == 0 or !(i % 2))
            if (_str[i / 2] == '0')
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


