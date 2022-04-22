#pragma once

#include <cstddef>

class Board;

enum class SolveMode
{
    UNKNOWN,
    BRUTEFORCE,
    BRUTEFORCE_WITH_PRIO
};

class Solver
{
public:
    static bool solve(SolveMode _mode, Board& _board);
private:
    static void solveBruteForce(Board& _board, bool& _result);
    static void solveBruteForceWithPrio(Board &_board, bool &_result);

    static bool findEmpty(const Board& board, size_t& _row, size_t& _col);
    static bool findEmptyWithPrio(Board &board, size_t &row, size_t& col);

    static void fillPencileMarks(Board &_board);
};

