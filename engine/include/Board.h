#pragma once

#include "Group.h"

#include <string>
#include <vector>

class Board
{
public:
    using BoardVecMatrix = std::vector<std::vector<Cell*>>;
    using Groups = std::vector<Group*>;

    Board() = default;
    Board(const Board&) = delete;
    Board(const Board&&) = delete;
    explicit Board(const std::string& _notation);

    std::vector<const Cell*> getRow(size_t _idx) const;
    std::vector<const Cell*> getColumn(size_t _idx) const;
    std::vector<const Cell*> getSquare(size_t _idx) const;

private:
    BoardVecMatrix mBoardMatrix{};
    Groups mRowGroups{};
    Groups mColumnGroups{};
    Groups mSquareGroups{};
};