#pragma once

#include "Group.h"

#include <string>

class Board
{
public:
    using BoardVecMatrix = std::vector<std::vector<Cell*>>;
    using Groups = std::vector<Group*>;

    Board() = default;
    ~Board();
    Board(const Board&) = delete;
    Board(const Board&&) = delete;
    explicit Board(const std::string& _notation);

    [[nodiscard]] std::vector<Cell*> getRow(size_t _idx) const;
    [[nodiscard]] std::vector<Cell*> getColumn(size_t _idx) const;
    [[nodiscard]] std::vector<Cell*> getSquare(size_t _idx) const;
    [[nodiscard]] Cell* getCell(size_t _row, size_t _column) const;

    [[nodiscard]] std::string getNotation() const;

private:
    BoardVecMatrix mBoardMatrix{};
    Groups mRowGroups{};
    Groups mColumnGroups{};
    Groups mSquareGroups{};
};