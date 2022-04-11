#include "Board.h"

#include "Logger.h"

#include <string>

Board::Board(const std::string& _notation)
{
    if(_notation.length() != 81)
        Log("Board: invalid size of notation");

    // Create cells in board matrix
    for(size_t row = 0; row < 9; ++row)
    {
        std::vector<Cell*> vecRow;
        for(size_t column = 0; column < 9; ++column)
        {
            uint8_t val = _notation[row*9 + column] - 48;
            vecRow.push_back(new Cell(val));
        }
        mBoardMatrix.push_back(vecRow);
    }

    // Assign cells to row groups
    for(const auto& row : mBoardMatrix)
    {
        auto* rowGroup = new Group({row.begin(), row.end()});
        for(auto cell : row)
        {
            cell->rowGroups = rowGroup;
        }
        mRowGroups.push_back(rowGroup);
    }

    // Assign cells to column groups
    for(int column = 0; column < 9; ++column)
    {
        std::unordered_set<const Cell*> columnSet{};
        auto* columnGroup= new Group();
        for(int row = 0; row < 9; ++row)
        {
            auto cell = mBoardMatrix.at(row).at(column);
            columnGroup->mCells.push_back(cell);
            cell->columnGroup = columnGroup;
        }
        mColumnGroups.push_back(columnGroup);
    }

    // Assign cells to squares
    for(int squareY = 0; squareY < 3; ++squareY)
    {
        for(int squareX = 0; squareX < 3; ++squareX)
        {
            auto* squareGroup = new Group();
            for(int cellInSquareY = 0; cellInSquareY < 3; ++cellInSquareY)
            {
                for(int cellInSquareX = 0; cellInSquareX < 3; ++cellInSquareX)
                {
                    auto cell = mBoardMatrix.at(cellInSquareY + 3*squareY).at(cellInSquareX + 3*squareX);
                    squareGroup->mCells.push_back(cell);
                    cell->squareGroup = squareGroup;
                }
            }
            mSquareGroups.push_back(squareGroup);
        }
    }
}

std::vector<Cell*> Board::getRow(size_t _idx) const
{
    return mRowGroups.at(_idx)->mCells;
}

std::vector<Cell*> Board::getColumn(size_t _idx) const
{
    return mColumnGroups.at(_idx)->mCells;
}

std::vector<Cell*> Board::getSquare(size_t _idx) const
{
    return mSquareGroups.at(_idx)->mCells;
}

Cell* Board::getCell(size_t row, size_t column) const
{
    return this->getRow(row).at(column);
}