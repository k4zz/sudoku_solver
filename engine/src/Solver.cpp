#include "Solver.h"
#include "Logger.h"
#include "Checker.h"

bool Solver::solve(SolveMode _mode, Board& _board)
{
    switch (_mode)
    {
        case SolveMode::BRUTEFORCE:
            return solve(_board);
        default:
            Log("Non handled mode");
            return false;
    }
}

bool Solver::solve(Board& _board)
{
    int row, col;

    if(!findEmpty(_board, row, col))
        return true;

    for (int num = 0; num <= 9; ++num)
    {
        if(Checker::validNumberForCell(_board, row, col, num))
        {
            _board.getCell(row, col)->value = num;
            if (solve(_board))
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


