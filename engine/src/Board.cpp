#include "Board.h"

#include <string>

Board::Board(const std::string& _notation)
{
    for(auto& chr : _notation)
    {
        mCells.push_back(new Cell(chr - 48));
    }

    // Assign cells to row groups
    for(int row = 0; row < 9; ++row)
    {
        std::vector<const Cell*> subVec = {mCells.begin() + (row * 9), mCells.begin() + (row * 9) + 9};
        Group rowGroup(subVec);
        mRowGroups.push_back(rowGroup);
    }

    // Assign cells to column groups
    for(int column = 0; column < 9; ++column)
    {
        std::vector<const Cell*> columnVec{};
        columnVec.reserve(9);
        for(int row = 0; row < 9; ++row)
        {
            columnVec.push_back(mCells.at(row*9+column));
        }
        mColumnGroups.push_back(columnVec);

    }
}

Group Board::getRow(size_t _idx)
{
    return mRowGroups.at(_idx);
}

Group Board::getColumn(size_t _idx)
{
    return mColumnGroups.at(_idx);
}

Group Board::getSquare(size_t _idx)
{
    return mSquareGroups.at(_idx);
}
