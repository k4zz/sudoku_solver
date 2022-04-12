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

    [[nodiscard]] std::vector<Cell*> getRow(size_t _idx) const;
    [[nodiscard]] std::vector<Cell*> getColumn(size_t _idx) const;
    [[nodiscard]] std::vector<Cell*> getSquare(size_t _idx) const;
    [[nodiscard]] Cell* getCell(size_t row, size_t column) const;

    std::string getNotation() const;

private:
    BoardVecMatrix mBoardMatrix{};
    Groups mRowGroups{};
    Groups mColumnGroups{};
    Groups mSquareGroups{};
};