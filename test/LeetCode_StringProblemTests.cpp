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