#pragma once

#include "Cell.h"

class Group
{
public:
    Group() = default;
    Group(std::vector<Cell*> _group) { mCells = _group; };

public:
    std::vector<Cell*> mCells;
};