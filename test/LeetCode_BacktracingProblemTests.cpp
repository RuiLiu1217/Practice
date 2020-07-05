#include <gtest/gtest.h>
#include "../LeetCode_BacktracingProblems.hpp"

TEST(LC, LC__0017__Test) {
    LC::_0017_LetterCombinationsOfAPhoneNumber obj;
    std::string digits = "2";
    std::vector<std::string> res = obj.letterCombinations(digits);
    std::vector<std::string> grd{"a", "b", "c"};
    EXPECT_EQ(res, grd);
}