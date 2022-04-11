#include "Logger.h"
#include "BoardPrinter.h"
#include "Board.h"
#include "Solver.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Log("Provide notation");
        return -1;
    }

    //TODO: notation validator
    //TODO: 81 chars, only numbers

    Board board(argv[1]);
    BoardPrinter::printBoard(board);
    Solver::solve(board);
    BoardPrinter::printBoard(board);


    return 0;
}