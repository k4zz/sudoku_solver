#pragma once

#include <string>

class BoardPrinter
{
public:
    static void printBoard(const std::string& _notation);

private:
    static void printTopFrame();
    static void printBottomFrame();
    static void printMiddleFrame();
    static void printRow(const std::string& _str);
};

