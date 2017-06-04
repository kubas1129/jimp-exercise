//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include "ArabicRoman.h"

using namespace ::arabicroman;

TEST(RomanToArabic, CheckIfNullArgumentReturnNullValue)
{
    EXPECT_EQ(0, RomanToArabic(""));
}

TEST(RomanToArabic, CheckValue1)
{
    EXPECT_EQ(1, RomanToArabic("I"));
}

TEST(RomanToArabic, CheckValue50)
{
    EXPECT_EQ(50, RomanToArabic("L"));
}

TEST(RomanToArabic, CheckValue120)
{
    EXPECT_EQ(120, RomanToArabic("CXX"));
}

TEST(RomanToArabic, CheckValue567)
{
    EXPECT_EQ(567, RomanToArabic("DLXVII"));
}