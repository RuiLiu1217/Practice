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