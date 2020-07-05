#include <gtest/gtest.h>
#include "../LeetCode_GreedyAlgorithmProblems.hpp"

TEST(LC, _0012_IntegerToRoman) {
    LC::_0012_IntegerToRoman obj;
    EXPECT_EQ(obj.intToRoman(3), "III");
    EXPECT_EQ(obj.intToRoman(4), "IV");
    EXPECT_EQ(obj.intToRoman(9), "IX");
    EXPECT_EQ(obj.intToRoman(58), "LVIII");
    EXPECT_EQ(obj.intToRoman(1994), "MCMXCIV");
}

TEST(LC, _0013_RomanToInteger) {
    LC::_0013_RomanToInteger obj;
    EXPECT_EQ(obj.romainToInt("I"), 1);
    EXPECT_EQ(obj.romainToInt("IV"), 4);
    EXPECT_EQ(obj.romainToInt("VI"), 6);
}