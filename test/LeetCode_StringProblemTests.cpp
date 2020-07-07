#include <gtest/gtest.h>
#include "../LeetCode_StringProblems.hpp"

TEST(LC, _0005_LongestPalindromicSubstring) {
    LC::_0005_LongestPalindromicSubstring obj;
    std::string groundTruth1 = "aba";
    EXPECT_EQ(obj.longestPalidrome("babad"), groundTruth1);
    std::string groundTruth2 = "bb";
    EXPECT_EQ(obj.longestPalidrome("cbbd"), groundTruth2);
}

TEST(LC, _0006_ZigZagConversion) {
    LC::_0006_ZigZagConversion obj;
    EXPECT_EQ(obj.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
    EXPECT_EQ(obj.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}

TEST(LC, _0008_StringToInteger) {
    LC::_0008_StringToInteger obj;
    EXPECT_EQ(obj.myAtoi("42"), 42);
    EXPECT_EQ(obj.myAtoi("   -42"), -42);
    EXPECT_EQ(obj.myAtoi("4193 with words"), 4193);
    EXPECT_EQ(obj.myAtoi("words and 987"),  0);
    EXPECT_EQ(obj.myAtoi("-91283472332"), -2147483648);
}

TEST(LC, _0038_CountAndSay) {
    LC::_0038_CountAndSay obj;
    EXPECT_EQ(obj.countAndSay(0), "1");
    EXPECT_EQ(obj.countAndSay(1), "11");
    EXPECT_EQ(obj.countAndSay(2), "21");
    EXPECT_EQ(obj.countAndSay(3), "1211");
    EXPECT_EQ(obj.countAndSay(4), "111221");
}

TEST(LC, _0043_MultiplyStrings) {
    LC::_0043_MultiplyStrings obj;
    std::string a = "11";
    std::string b = "13";
    std::string g = "143";
    EXPECT_EQ(obj.multiply(a, b), g);
}

TEST(LC, _0058_) {
    LC::_0058_LengthOfLastWord obj;
    EXPECT_EQ(obj.lengthOfLastWord("Hello World"), 5);
}
    