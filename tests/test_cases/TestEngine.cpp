#include <gtest/gtest.h>
#include "Board.h"

TEST(Engine, Board_ValidNotation_AllCellsHaveProperValue)
{
    auto notation = "310004069000000200008005040000000005006000017807030000590700006600003050000100002";

    Board board(notation);
    std::vector<std::vector<int>> validBoard({{3, 1, 0, 0, 0, 4, 0, 6, 9},
                                              {0, 0, 0, 0, 0, 0, 2, 0, 0},
                                              {0, 0, 8, 0, 0, 5, 0, 4, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0, 5},
                                              {0, 0, 6, 0, 0, 0, 0, 1, 7},
                                              {8, 0, 7, 0, 3, 0, 0, 0, 0},
                                              {5, 9, 0, 7, 0, 0, 0, 0, 6},
                                              {6, 0, 0, 0, 0, 3, 0, 5, 0},
                                              {0, 0, 0, 1, 0, 0, 0, 0, 2}});
    for (size_t row = 0; row < 9; ++row)
    {
        for (int column = 0; column < 9; ++column)
        {
            ASSERT_EQ(board.getCell(row, column)->value, validBoard.at(row).at(column));
        }
    }
}

TEST(Engine, Board_InvalidNotation_)
{
    auto notation = "310004069000000200008005040000000005006000017807030000590700006600003050000100002";

    Board board(notation);
    std::vector<std::vector<int>> validBoard({{3, 1, 0, 0, 0, 4, 0, 6, 9},
                                              {0, 0, 0, 0, 0, 0, 2, 0, 0},
                                              {0, 0, 8, 0, 0, 5, 0, 4, 0},
                                              {0, 0, 0, 0, 0, 0, 0, 0, 5},
                                              {0, 0, 6, 0, 0, 0, 0, 1, 7},
                                              {8, 0, 7, 0, 3, 0, 0, 0, 0},
                                              {5, 9, 0, 7, 0, 0, 0, 0, 6},
                                              {6, 0, 0, 0, 0, 3, 0, 5, 0},
                                              {0, 0, 0, 1, 0, 0, 0, 0, 2}});
    for (size_t row = 0; row < 9; ++row)
    {
        for (int column = 0; column < 9; ++column)
        {
            ASSERT_EQ(board.getCell(row, column)->value, validBoard.at(row).at(column));
        }
    }
}
