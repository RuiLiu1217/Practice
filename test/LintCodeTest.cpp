#include <gtest/gtest.h>
#include "../LintCode.hpp"

TEST(LINTCODE, _0001_APlusBProblem) {
    LintCode::_0001_APlusBProblem obj;
    
    EXPECT_EQ(obj.aplusb(0, 0), 0);
    EXPECT_EQ(obj.aplusb(1, 1), 2);
    EXPECT_EQ(obj.aplusb(-1, -1), -2);
    EXPECT_EQ(obj.aplusb(1, -1), 0);
    EXPECT_EQ(obj.aplusb(100, 200), 300);
}

TEST(LINTCODE, _0002_TrailingZeros) {
    LintCode::_0002_TrailingZeros obj;
    EXPECT_EQ(obj.trailingZeros(1), 0);
    EXPECT_EQ(obj.trailingZeros(5), 1);
    EXPECT_EQ(obj.trailingZeros(11), 2);
    EXPECT_EQ(obj.trailingZeros(25), 6);
}


TEST(LINTCODE, _0004_UglyNumberII) {
    LintCode::_0004_UglyNumberII obj;
    EXPECT_EQ(obj.nthUglyNumber(9), 10);
    EXPECT_EQ(obj.nthUglyNumber(1), 1);
}

TEST(LINTCODE, _0006_MergeTwoSortedArrays) {
    LintCode::_0006_MergeTwoSortedArrays obj;
    std::vector<int> A {0,3,5,7,9};
    std::vector<int> B {1,3,4,6,7,8,9,10};
    std::vector<int> res = obj.mergeSortedArray(A, B);
    std::vector<int> base{0,1,3,3,4,5,6,7,7,8,9,9,10};
    EXPECT_EQ(res, base);
}

TEST(LINTCODE, _0008_RotateString) {
    LintCode::_0008_RotateString obj;
    std::string testStr = "ABCDEFG";
    obj.rotateString(testStr, 1);
    EXPECT_EQ(testStr, "GABCDEF");
    testStr="abcdefg";
    obj.rotateString(testStr, 3);
    EXPECT_EQ(testStr, "efgabcd");
    testStr = "abcdefg";
    obj.rotateString(testStr, 0);
    EXPECT_EQ(testStr, "abcdefg");
    testStr = "abcdefg";
    obj.rotateString(testStr, 10);
    EXPECT_EQ(testStr, "efgabcd");
}

TEST(LINTCODE, _0009_FizzBuzz) {
    LintCode::_0009_FizzBuzz obj;
    std::vector<std::string> res = obj.fizzBuzz(15);
    std::vector<std::string> base{"1", "2", "fizz", 
    "4", "buzz", "fizz", "7", "8", "fizz", "buzz", "11", "fizz", "13", "14", "fizz buzz"};
    EXPECT_EQ(res, base);
}