#include "Solver.h"

#include "Board.h"
#include "Logger.h"
#include "Checker.h"
#include "Stopwatch.h"

bool Solver::solve(SolveMode _mode, Board& _board)
{
    bool result = false;

    switch (_mode)
    {
        case SolveMode::UNKNOWN:
            Log("Unknown mode for solving");
            return false;
        case SolveMode::BRUTEFORCE:
        {
            auto time = FunctionStopwatch::duration(solveBruteForce, _board, result);
            if (result)
            {
                Log("Solving by BruteForce took " + std::to_string(time.count()) + " [ms]");
            } else
            {
                Log("Failed to resolve by BruteForce");
            }
            break;
        }
        default:
            Log("Non handled mode");
    }
    return result;
}

void Solver::solveBruteForce(Board& _board, bool& _result)
{
    std::size_t row, col;

    if (!findEmpty(_board, row, col))
    {
        _result = true;
        return;
    }

    for (int num = 0; num <= 9; ++num)
    {
        if (Checker::validNumberForCell(_board, row, col, num))
        {
            _board.getCell(row, col)->value = num;
            solveBruteForce(_board, _result);
            if (_result)
            {
                _result = true;
                return;
            }
            _board.getCell(row, col)->value = 0;
        }
    }
    _result = false;
}

bool Solver::findEmpty(const Board& board, size_t& row, size_t& col)
{
    for (int rowIdx = 0; rowIdx < 9; ++rowIdx)
    {
        auto vec = board.getRow(rowIdx);
        for (int colIdx = 0; colIdx < 9; ++colIdx)
        {
            if (vec.at(colIdx)->value == 0)
            {
                row = rowIdx;
                col = colIdx;
                return true;
            }
        }
    }
    return false;
}


