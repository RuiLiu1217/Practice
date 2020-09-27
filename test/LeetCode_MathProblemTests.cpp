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

TEST(LC, _0258_AddDigits) {
    LC::_0258_AddDigits obj;
    EXPECT_EQ(obj.addDigits(234623), 2);
}

TEST(LC, _0263_UglyNumber) {
    LC::_0263_UglyNumber obj;
    EXPECT_TRUE(obj.isUgly(2));
    EXPECT_FALSE(obj.isUgly(7));
}

TEST(LC, _0311_SparseMatrixMultiplication) {
    LC::_0311_SparseMatrixMultiplication obj;
    std::vector<std::vector<int>> A{{1, 0, 0}, {-1, 0, 3}};
    std::vector<std::vector<int>> B{{7, 0, 0}, {0, 0, 0 }, {0, 0, 1}};
    std::vector<std::vector<int>> res{{7,0,0},{-7,0,3}};
    EXPECT_EQ(obj.multiply(A, B), res);
}

TEST(LC, _0326_PowerOfThree) {
    LC::_0326_PowerOfThree obj;
    EXPECT_TRUE(obj.isPowerOfThree(27));
    EXPECT_FALSE(obj.isPowerOfThree(0));
    EXPECT_TRUE(obj.isPowerOfThree(1));
    EXPECT_FALSE(obj.isPowerOfThree(2345341));
}

TEST(LC, _0342_PowerOfFour) {
    LC::_0342_PowerOfFour obj;
    EXPECT_TRUE(obj.isPowerOfFour(1));
    EXPECT_TRUE(obj.isPowerOfFour(4));
    EXPECT_TRUE(obj.isPowerOfFour(4 * 4 * 4 * 4 * 4));
    EXPECT_FALSE(obj.isPowerOfFour(0));
    EXPECT_FALSE(obj.isPowerOfFour(2));
}

TEST(LC, _0367_) {
    LC::_0367_ValidPerfectSquare obj;
    EXPECT_TRUE(obj.isPerfectSquare(16));
    EXPECT_FALSE(obj.isPerfectSquare(32));
    EXPECT_FALSE(obj.isPerfectSquare(14));
    EXPECT_TRUE(obj.isPerfectSquare(9));
}