#include "Validator.h"

bool Validator::isValid(const std::string& _notation, char _emptyCell)
{
    if(_notation.size() != 81)
        return false;

    if(_emptyCell >= '1' && _emptyCell <= '9')
        return false;

    for(const auto& chr : _notation)
    {
        if((chr < '1' || chr > '9') && chr != _emptyCell)
            return false;
    }

    return true;
}

void Validator::reformatNotation(std::string& _notation)
{
    for (auto& chr : _notation)
    {
        if(chr < '1' || chr > '9')
            chr = '0';
    }
}
