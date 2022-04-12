#include <gtest/gtest.h>

#include "Solver.h"
#include "Board.h"

TEST(Solver, InvalidSudoku_SolverReturnFalse)
{
    Board board("123456789100000000100000000123456789100000000100000000123456789100000000100000000");
    ASSERT_EQ(Solver::solve(SolveMode::BRUTEFORCE, board), false);
}

TEST(Solver, ValidBoard_SolverReturnTrue)
{
    Board board("310004069000000200008005040000000005006000017807030000590700006600003050000100002");
    ASSERT_EQ(Solver::solve(SolveMode::BRUTEFORCE, board), true);
}

TEST(Solver, ValidBoard_BoardedResolvedCorrectly)
{
    std::string solution{"312874569465319278978265143139427685246598317857631924591742836624983751783156492"};
    Board board("310004069000000200008005040000000005006000017807030000590700006600003050000100002");
    Solver::solve(SolveMode::BRUTEFORCE, board);

    std::string solverSolution = board.getNotation();

    ASSERT_EQ(solverSolution, solution);
}