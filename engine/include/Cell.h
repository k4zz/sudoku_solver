#pragma once

#include <vector>

class Group;

class Cell
{
public:
    Cell(uint8_t _value)
            : value{_value}
    {

    }

public:
    uint8_t value{0};
    std::vector<uint8_t> pencilMarks{};
    const Group *rowGroups{};
    const Group *columnGroup{};
    const Group *squareGroup{};
};