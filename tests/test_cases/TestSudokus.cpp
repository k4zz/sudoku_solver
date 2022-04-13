#include <gtest/gtest.h>
#include <fstream>

#include "Solver.h"
#include "Board.h"

#include "TestFilesPaths.h"

TEST(Sudokus, SetOfValidSudokus_AllResolvedCorrectly)
{
    std::ifstream file(SET_OF_SUDOKUS);
    std::string line{};
    while (std::getline(file, line))
    {
        std::string notation = line.substr(0, 81);
        Board board(notation);
        Solver::solve(SolveMode::BRUTEFORCE, board);
        std::string solverSolution = board.getNotation();
        std::string actualSolution = line.substr(82, 81);
        ASSERT_EQ(solverSolution, actualSolution);
    }
}