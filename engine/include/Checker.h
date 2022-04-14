#pragma once

#include <cstddef>

class Board;

class Checker
{
public:
    static bool validNumberForCell(const Board& _board, size_t _row, size_t _column, size_t _num);
    static bool validForRow(const Board& _board, size_t _row, size_t _num);
    static bool validForColumn(const Board& _board, size_t _column, size_t _num);
    static bool validForSquare(const Board& _board, size_t _row, size_t _column, size_t _num);
};

