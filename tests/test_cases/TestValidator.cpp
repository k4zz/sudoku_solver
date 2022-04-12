#include <gtest/gtest.h>
#include "Validator.h"

TEST(Validator, ValidNotationAndEmptyCell_ValidatorReturnTrue)
{
    auto notation = "023123123123123123123123123123123123123123123123123123123123123123123123123123123";
    char emptyCell = '0';

    ASSERT_EQ(Validator::isValid(notation, emptyCell), true);
}

TEST(Validator, InvalidNotation_ValidatorReturnFalse)
{
    auto notation = "";
    char emptyCell = '0';

    ASSERT_EQ(Validator::isValid(notation, emptyCell), false);
}

TEST(Validator, InvalidEmptyCell_ValidatorReturnFalse)
{
    auto notation = "1231231231231231231231231231231abc23123123123123123123123123123123123123123123123";
    char emptyCell = '0';

    ASSERT_EQ(Validator::isValid(notation, emptyCell), false);
}