#pragma once

#include "Board.h"

#include <string>

class BoardPrinter
{
public:
    static void printBoard(const std::string& _notation);
    static void printBoard(Board& _board);

private:
    static void printTopFrame();
    static void printBottomFrame();
    static void printMiddleFrame();
    static void printRow(const std::string& _str);
    static void printRow(const Group& _group);
};

