#pragma once

#include <string>

class Validator
{
public:
    static bool isValid(const std::string& _notation, char _emptyCell);
    static void reformatNotation(std::string& _notation);
};

