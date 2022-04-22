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
        case SolveMode::BRUTEFORCE_WITH_PRIO:
        {
            auto time = FunctionStopwatch::duration(solveBruteForceWithPrio, _board, result);
            if (result)
            {
                Log("Solving by BruteForce with prio took " + std::to_string(time.count()) + " [ms]");
            } else
            {
                Log("Failed to resolve by BruteForce with prio");
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

void Solver::solveBruteForceWithPrio(Board &_board, bool &_result)
{
    fillPencileMarks(_board);

    size_t row, col;
    if(!findEmptyWithPrio(_board, row, col))
    {
        _result = true;
        return;
    }

    for (int num = 0; num <= 9; ++num)
    {
        if (Checker::validNumberForCell(_board, row, col, num))
        {
            _board.getCell(row, col)->value = num;
            fillPencileMarks(_board);
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
            if (vec->at(colIdx)->value == 0)
            {
                row = rowIdx;
                col = colIdx;
                return true;
            }
        }
    }
    return false;
}

bool Solver::findEmptyWithPrio(Board& board, size_t& row, size_t& col)
{
    size_t lowPencilMarks = std::numeric_limits<size_t>::max();
    bool status = false;
    for (int rowIdx = 0; rowIdx < 9; ++rowIdx)
    {
        for (int colIdx = 0; colIdx < 9; ++colIdx)
        {
            auto cell = board.getCell(rowIdx,colIdx);
            if (cell->value == 0)
            {
                if(cell->pencilMarks.size() < lowPencilMarks)
                {
                    lowPencilMarks = cell->pencilMarks.size();
                    row = rowIdx;
                    col = colIdx;
                    status = true;
                }
            }
        }
    }
    return status;
}

void Solver::fillPencileMarks(Board& _board)
{
    for(int rowIdx = 0; rowIdx < 9; ++rowIdx)
    {
        for(int colIdx = 0; colIdx < 9; ++colIdx)
        {
            auto cell = _board.getCell(rowIdx, colIdx);
            cell->pencilMarks.clear();
            for(int i = 1; i <=9; ++i)
            {
                if(Checker::validNumberForCell(_board, rowIdx, colIdx, i))
                {
                    cell->pencilMarks.push_back(i);
                }
            }
        }
    }
}
