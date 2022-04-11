#pragma once

#include "Board.h"

class Solver
{
public:
    static bool solve(Board& _board);
    static bool findEmpty(const Board& board, int& row, int& col);
    static bool checkRules(Board& board, int row, int col, int num);
};

