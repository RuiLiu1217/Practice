#include <gtest/gtest.h>
#include "../LeetCode_MathProblems.hpp"

TEST(LC, _0007_ReverseInteger) {
    LC::_0007_ReverseInteger obj;
    EXPECT_EQ(obj.reverse(123), 321);
    EXPECT_EQ(obj.reverse(-123), -321);
}

TEST(LC, _0009_PalindromeNumber) {
    LC::_0009_PalindromeNumber obj;
    EXPECT_TRUE(obj.isPalindrome(121));
    EXPECT_FALSE(obj.isPalindrome(-121));
    EXPECT_FALSE(obj.isPalindrome(10));
}

TEST(LC, _0029_DivideTwoIntegers) {
    LC::_0029_DivideTwoIntegers obj;
    EXPECT_EQ(obj.divide(4, 2), 2);
    EXPECT_EQ(obj.divide(6, 3), 2);
    EXPECT_EQ(obj.divide(14, 2), 7);
    EXPECT_EQ(obj.divide(24, 7), 3);
}

TEST(LC, _1447_SimplifiedFractions) {
    LC::_1447_SimplifiedFractions obj;
    std::vector<std::string> base{"1/2","1/3","2/3"};
    EXPECT_EQ(obj.simplifiedFractions(3), base);
}

TEST(LC, _0263_UglyNumber) {
    LC::_0263_UglyNumber obj;
    EXPECT_TRUE(obj.isUgly(2));
    EXPECT_FALSE(obj.isUgly(7));
}