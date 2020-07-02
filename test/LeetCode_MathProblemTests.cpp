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