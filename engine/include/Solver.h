#pragma once

#include <cstddef>

class Board;

enum class SolveMode
{
    UNKNOWN,
    BRUTEFORCE
};

class Solver
{
public:
    static bool solve(SolveMode _mode, Board& _board);
private:
    static void solveBruteForce(Board& _board, bool& _result);
    static bool findEmpty(const Board& board, size_t& _row, size_t& _col);
};

