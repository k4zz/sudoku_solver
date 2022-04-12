#include <gtest/gtest.h>
#include "Validator.h"

TEST(Validator, ValidNotationAllFilled_ValidatorReturnTrue)
{
    auto notation = "123123123123123123123123123123123123123123123123123123123123123123123123123123123";
    char emptyCell = '0';

    ASSERT_EQ(Validator::isValid(notation, emptyCell), true);
}

TEST(Validator, ValidNotationAllEmpty_ValidatorReturnTrue)
{
    auto notation = "000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    char emptyCell = '0';

    ASSERT_EQ(Validator::isValid(notation, emptyCell), true);
}

TEST(Validator, ValidNotationMixed_ValidatorReturnTrue)
{
    auto notation = "103050607103050607103050607103050607103050607103050607103050607103050607103050607";
    char emptyCell = '0';

    ASSERT_EQ(Validator::isValid(notation, emptyCell), true);
}

TEST(Validator, InvalidEmptyCell_ValidatorReturnFalse)
{
    auto notation = "123000000000000000000000000000000000000000000000000000000000000000000000000000000";
    char emptyCell = 'a';

    ASSERT_EQ(Validator::isValid(notation, emptyCell), false);
}

TEST(Validator, InvalidEmptyCellSameAsSudoku_ValidatorReturnTrue)
{
    auto notation = "103050607103050607103050607103050607103050607103050607103050607103050607103050607";
    char emptyCell = '1';

    ASSERT_EQ(Validator::isValid(notation, emptyCell), false);
}

TEST(Validator, InvalidNotationLength_ValidatorReturnFalse)
{
    auto notation = "123123";
    char emptyCell = '0';

    ASSERT_EQ(Validator::isValid(notation, emptyCell), false);
}

TEST(Validator, ValidNotationWithZeros_ReformatSameString)
{
    std::string notation1 = "103050607103050607103050607103050607103050607103050607103050607103050607103050607";
    std::string notation2 = "103050607103050607103050607103050607103050607103050607103050607103050607103050607";

    Validator::reformatNotation(notation1);

    ASSERT_EQ(notation1, notation2);
}

TEST(Validator, ValidNotationWithA_ReformatSameString)
{
    std::string notation1 = "1a3a5a6a71a3a5a6a71a3a5a6a71a3a5a6a71a3a5a6a71a3a5a6a71a3a5a6a71a3a5a6a71a3a5a6a7";
    std::string notation2 = "103050607103050607103050607103050607103050607103050607103050607103050607103050607";

    Validator::reformatNotation(notation1);

    ASSERT_EQ(notation1, notation2);
}
