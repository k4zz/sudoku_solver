#pragma once

class Board;

class Checker
{
public:
    static bool validNumberForCell(Board& board, int row, int column, int num);
    static bool validForRow(const Board& board, int row, int num);
    static bool validForColumn(const Board& board, int column, int num);
    static bool validForSquare(const Board& board, int row, int column, int num);

};

