#pragma once

#include <vector>
#include <memory>


class Cell
{
public:
    using Group = std::vector<Cell*>;

    Cell(uint8_t _value)
            : value{_value}
    {
    }

    void setValue(uint8_t _val) { value = _val; }

public:
    uint8_t value{0};
    std::vector<uint8_t> pencilMarks{};
    const Group* rowGroups{};
    const Group* columnGroup{};
    const Group* squareGroup{};
};
