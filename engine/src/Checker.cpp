#include "Checker.h"

#include "Board.h"

#include <algorithm>

bool Checker::validNumberForCell(Board& board, int row, int column, int num)
{
    if (Checker::validForRow(board, row, num) &&
        Checker::validForColumn(board, column, num) &&
        Checker::validForSquare(board, row, column, num))
        return true;

    return false;
}

bool Checker::validForRow(const Board& board, int row, int num)
{
    auto isSame = [num](Cell* cell)
    { return cell->value == num; };

    auto rowGroup = board.getRow(row);
    if (std::find_if(rowGroup.begin(), rowGroup.end(), isSame) == rowGroup.end())
        return true;
    return false;
}

bool Checker::validForColumn(const Board& board, int column, int num)
{
    auto isSame = [num](Cell* cell)
    { return cell->value == num; };

    auto columnGroup = board.getColumn(column);
    if (std::find_if(columnGroup.begin(), columnGroup.end(), isSame) == columnGroup.end())
        return true;

    return false;
}

bool Checker::validForSquare(const Board& board, int row, int column, int num)
{
    auto isSame = [num](Cell* cell)
    { return cell->value == num; };

    auto squareGroup = board.getCell(row, column)->squareGroup->mCells;
    if (std::find_if(squareGroup.begin(), squareGroup.end(), isSame) == squareGroup.end())
        return true;

    return false;
}
