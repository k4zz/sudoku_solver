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
    auto rowGroup = _board.getRow(_row);
    return validForGroup(rowGroup, _num);
}

bool Checker::validForColumn(const Board& _board, size_t _column, size_t _num)
{
    auto columnGroup = _board.getColumn(_column);
    return validForGroup(columnGroup, _num);
}

bool Checker::validForSquare(const Board& _board, size_t _row, size_t _column, size_t _num)
{
    auto squareGroup = _board.getCell(_row, _column)->squareGroup;
    return validForGroup(squareGroup, _num);
}


bool Checker::validForGroup(const std::vector<Cell*>* _group, size_t _num)
{
    auto isSame = [_num](Cell* cell)
    { return cell->value == _num; };

    if (std::find_if(_group->begin(), _group->end(), isSame) == _group->end())
        return true;

    return false;
}
