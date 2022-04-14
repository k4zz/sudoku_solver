#include "Checker.h"

#include "Board.h"

#include <algorithm>

bool Checker::validNumberForCell(const Board& _board, size_t _row, size_t _column, size_t _num)
{
    if (Checker::validForRow(_board, _row, _num) &&
        Checker::validForColumn(_board, _column, _num) &&
        Checker::validForSquare(_board, _row, _column, _num))
        return true;

    return false;
}

bool Checker::validForRow(const Board& _board, size_t _row, size_t _num)
{
    auto isSame = [_num](Cell* cell)
    { return cell->value == _num; };

    auto rowGroup = _board.getRow(_row);
    if (std::find_if(rowGroup.begin(), rowGroup.end(), isSame) == rowGroup.end())
        return true;
    return false;
}

bool Checker::validForColumn(const Board& _board, size_t _column, size_t _num)
{
    auto isSame = [_num](Cell* cell)
    { return cell->value == _num; };

    auto columnGroup = _board.getColumn(_column);
    if (std::find_if(columnGroup.begin(), columnGroup.end(), isSame) == columnGroup.end())
        return true;

    return false;
}

bool Checker::validForSquare(const Board& _board, size_t _row, size_t _column, size_t _num)
{
    auto isSame = [_num](Cell* cell)
    { return cell->value == _num; };

    auto squareGroup = _board.getCell(_row, _column)->squareGroup->mCells;
    if (std::find_if(squareGroup.begin(), squareGroup.end(), isSame) == squareGroup.end())
        return true;

    return false;
}
