#include <cxxopts.hpp>

#include "Logger.h"
#include "BoardPrinter.h"
#include "Board.h"
#include "Solver.h"
#include "Validator.h"

int main(int argc, char** argv)
{
    cxxopts::Options options("SudokuSolver", "Small tool that allows to solve sudoku based on given notations");

    options.add_options()
            ("h,help", "Show help")
            ("e, empty-cell", "Character used to indicate empty cells", cxxopts::value<char>())
            ("notation", "Notation of sudoku to be solved", cxxopts::value<std::string>());

    options.positional_help("notation");
    options.parse_positional("notation");

    auto results = options.parse(argc, argv);

    if (results.count("help"))
    {
        Log(options.help());
        return 0;
    }

    // TODO: can be removed when GUI will be available
    if(!results.count("notation"))
    {
        Log("Notation argument is mandatory (at least for now)");
        return 0;
    }

    char emptyCell = '0';
    if(results.count("empty-cell"))
        emptyCell = results["empty-cell"].as<char>();

    auto notation = results["notation"].as<std::string>();

    Validator::isValid(notation, emptyCell);
    Validator::reformatNotation(notation);

    Board board(notation);
    BoardPrinter::printBoard(board);
    Solver::solve(SolveMode::BRUTEFORCE, board);
    BoardPrinter::printBoard(board);

    return 0;
}