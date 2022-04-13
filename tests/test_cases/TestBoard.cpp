#include <gtest/gtest.h>
#include "Board.h"

TEST(Unit_Board, HorizontalNotation_AllCellsHaveProperValue)
{
    auto notation = "123456789123456789123456789123456789123456789123456789123456789123456789123456789";

    Board board(notation);
    std::vector<std::vector<int>> validBoard({{1, 2, 3, 4, 5, 6, 7, 8, 9},
                                              {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                              {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                              {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                              {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                              {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                              {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                              {1, 2, 3, 4, 5, 6, 7, 8, 9},
                                              {1, 2, 3, 4, 5, 6, 7, 8, 9}});
    for (size_t row = 0; row < 9; ++row)
    {
        for (int column = 0; column < 9; ++column)
        {
            ASSERT_EQ(board.getCell(row, column)->value, validBoard.at(row).at(column));
        }
    }
}

TEST(Unit_Board, VerticalNotation_AllCellsHaveProperValue)
{
    auto notation = "111111111222222222333333333444444444555555555666666666777777777888888888999999999";

    Board board(notation);
    std::vector<std::vector<int>> validBoard({{1, 1, 1, 1, 1, 1, 1, 1, 1},
                                              {2, 2, 2, 2, 2, 2, 2, 2, 2},
                                              {3, 3, 3, 3, 3, 3, 3, 3, 3},
                                              {4, 4, 4, 4, 4, 4, 4, 4, 4},
                                              {5, 5, 5, 5, 5, 5, 5, 5, 5},
                                              {6, 6, 6, 6, 6, 6, 6, 6, 6},
                                              {7, 7, 7, 7, 7, 7, 7, 7, 7},
                                              {8, 8, 8, 8, 8, 8, 8, 8, 8},
                                              {9, 9, 9, 9, 9, 9, 9, 9, 9}});
    for (size_t row = 0; row < 9; ++row)
    {
        for (int column = 0; column < 9; ++column)
        {
            ASSERT_EQ(board.getCell(row, column)->value, validBoard.at(row).at(column));
        }
    }
}

TEST(Unit_Board, DiagonalNotation_AllCellsHaveProperValue)
{
    auto notation = "123456789234567891345678912456789123567891234678912345789123456891234567912345678";

    Board board(notation);
    std::vector<std::vector<int>> validBoard({{1, 2, 3, 4, 5, 6, 7, 8, 9},
                                              {2, 3, 4, 5, 6, 7, 8, 9, 1},
                                              {3, 4, 5, 6, 7, 8, 9, 1, 2},
                                              {4, 5, 6, 7, 8, 9, 1, 2, 3},
                                              {5, 6, 7, 8, 9, 1, 2, 3, 4},
                                              {6, 7, 8, 9, 1, 2, 3, 4, 5},
                                              {7, 8, 9, 1, 2, 3, 4, 5, 6},
                                              {8, 9, 1, 2, 3, 4, 5, 6, 7},
                                              {9, 1, 2, 3, 4, 5, 6, 7, 8}});
    for (size_t row = 0; row < 9; ++row)
    {
        for (int column = 0; column < 9; ++column)
        {
            ASSERT_EQ(board.getCell(row, column)->value, validBoard.at(row).at(column));
        }
    }
}

TEST(Unit_Board, InvalidCharsInNotation_ThrowException)
{
    auto notation = "abc456789234567891345678912456789123567891234678912345789123456891234567912345678";

    ASSERT_ANY_THROW(Board board(notation));
}

TEST(Unit_Board, InvalidLengthOfNotation_ThrowException)
{
    auto notation = "123123123";

    ASSERT_ANY_THROW(Board board(notation));
}
