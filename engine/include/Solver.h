#pragma once

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
    static bool solveBruteForce(Board& _board);
    static bool findEmpty(const Board& board, int& row, int& col);
};

