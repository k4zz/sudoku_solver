#include "../cmd/include/Cmd.h"

int main(int argc, char** argv)
{
    if (argc > 1) // CMD
    {
        return Cmd::exec(argc, argv);
    }
    else // GUI
    {
        return 0;
    }
}