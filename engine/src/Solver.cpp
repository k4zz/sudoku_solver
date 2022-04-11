#include "Solver.h"

#include "Board.h"
#include "Cell.h"
#include "Logger.h"
#include "Checker.h"
#include "TimerObject.h"

bool Solver::solve(SolveMode _mode, Board& _board)
{
    switch (_mode)
    {
        case SolveMode::UNKNOWN:
            Log("Unknown mode for solving");
            return false;
        case SolveMode::BRUTEFORCE:
        {
            //TODO: I don't like the order of that, Timer also a little bit hacky :/
            TimerObject obj;
            Log("Solved by BruteForce");
            return solveBruteForce(_board);
        }
        default:
            Log("Non handled mode");
            return false;
    }
}

bool Solver::solveBruteForce(Board& _board)
{
    int row, col;

    if(!findEmpty(_board, row, col))
        return true;

    for (int num = 0; num <= 9; ++num)
    {
        if(Checker::validNumberForCell(_board, row, col, num))
        {
            _board.getCell(row, col)->value = num;
            if (solveBruteForce(_board))
                return true;
            _board.getCell(row, col)->value = 0;
        }
    }
    return false;
}

bool Solver::findEmpty(const Board& board, int& row, int& col)
{
    for (int rowIdx = 0; rowIdx < 9; ++rowIdx)
    {
        auto vec = board.getRow(rowIdx);
        for (int colIdx = 0; colIdx < 9; ++colIdx)
        {
            if(vec.at(colIdx)->value == 0)
            {
                row = rowIdx;
                col = colIdx;
                return true;
            }
        }
    }
    return false;
}


