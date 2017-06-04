//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include "ArabicRoman.h"

using namespace ::arabicroman;

TEST(ArabicToRoman, CheckIfNullArgumentReturnNullValue)
{
    EXPECT_EQ("", ArabicToRoman(0));
}

TEST(ArabicToRoman, CheckIfArgumentOutOfRangeReturnNull)
{
    EXPECT_EQ("", ArabicToRoman(4500));
}

TEST(ArabicToRoman, CheckValue1)
{
    EXPECT_EQ("I", ArabicToRoman(1));
}

TEST(ArabicToRoman, CheckValue1997)
{
    EXPECT_EQ("MCMXCVII", ArabicToRoman(1997));
}

TEST(ArabicToRoman, CheckValueMinus1)
{
    EXPECT_EQ("", ArabicToRoman(-1));
}

