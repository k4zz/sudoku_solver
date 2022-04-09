#include "Logger.h"
#include "BoardPrinter.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Log("Provide notation");
        return -1;
    }

    BoardPrinter::printBoard(argv[1]);

    return 0;
}