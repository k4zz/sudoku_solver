#include <algorithm>
#include "Solver.h"

bool Solver::solve(Board& _board)
{
    int row, col;

    if(!findEmpty(_board, row, col))
        return true;

    for (int num = 0; num <= 9; ++num)
    {
        if(checkRules(_board, row, col, num))
        {
            _board.getCell(row, col)->value = num;
            if (solve(_board))
                return true;
            _board.getCell(row, col)->value = 0;
        }
    }
    return false;
}

bool Solver::findEmpty(const Board& board, int& row, int& col)
{
    for (int rowIdx = 0; rowIdx < 9; ++rowIdx)
    {
        auto vec = board.getRow(rowIdx);
        for (int colIdx = 0; colIdx < 9; ++colIdx)
        {
            if(vec.at(colIdx)->value == 0)
            {
                row = rowIdx;
                col = colIdx;
                return true;
            }
        }
    }
    return false;
}

bool Solver::checkRules(Board& board, int row, int col, int num)
{
    auto isSame = [num](Cell* cell){ return cell->value == num; };

    auto rowGroup = board.getRow(row);
    if(std::find_if(rowGroup.begin(), rowGroup.end(), isSame) != rowGroup.end())
        return false;

    auto columnGroup = board.getColumn(col);
    if(std::find_if(columnGroup.begin(), columnGroup.end(), isSame) != columnGroup.end())
        return false;

    auto squareGroup = board.getCell(row, col)->squareGroup->mCells;
    if(std::find_if(squareGroup.begin(), squareGroup.end(), isSame) != squareGroup.end())
        return false;

    return true;
}
