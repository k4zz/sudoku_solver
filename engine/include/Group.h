#pragma once

#include <memory>
#include <utility>

#include "Cell.h"

class Group
{
public:
    Group() = default;
    Group(std::vector<const Cell*> _group) { mCells = std::move(_group); };

public:
    std::vector<const Cell*> mCells;
};