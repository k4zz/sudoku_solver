#pragma once

#include "Group.h"

#include <string>
#include <vector>

class Board
{
public:
    using Cells = std::vector<const Cell*>;
    using Groups = std::vector<Group>;

    Board() = default;
    Board(const Board&) = delete;
    Board(const Board&&) = delete;
    explicit Board(const std::string& _notation);

    Group getRow(size_t _idx);
    Group getColumn(size_t _idx);
    Group getSquare(size_t _idx);

private:
    Cells mCells{};
    Groups mRowGroups{};
    Groups mColumnGroups{};
    Groups mSquareGroups{};
};