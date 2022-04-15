#pragma once

#include <cstddef>
#include <vector>

class Board;
class Cell;

class Checker
{
public:
    static bool validNumberForCell(const Board& _board, size_t _row, size_t _column, size_t _num);
private:
    static bool validForRow(const Board& _board, size_t _row, size_t _num);
    static bool validForColumn(const Board& _board, size_t _column, size_t _num);
    static bool validForSquare(const Board& _board, size_t _row, size_t _column, size_t _num);
    static bool validForGroup(const std::vector<Cell*>* _group, size_t _num);
};

