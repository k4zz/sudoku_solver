#pragma once

#include <memory>
#include <unordered_set>

#include "Cell.h"

class Group
{
public:
    Group() = default;
    Group(std::vector<const Cell*> _group) { mCells = _group; };

public:
    std::vector<const Cell*> mCells;
};