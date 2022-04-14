#pragma once

#include <utility>

#include "Cell.h"

class Group
{
public:
    Group() = default;
    Group(std::vector<Cell*> _group) { mCells = std::move(_group); };

public:
    std::vector<Cell*> mCells;
};