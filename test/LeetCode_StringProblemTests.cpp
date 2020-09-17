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

TEST(LC, _0058_LengthOfLastWord) {
    LC::_0058_LengthOfLastWord obj;
    EXPECT_EQ(obj.lengthOfLastWord("Hello World"), 5);
}

TEST(LC, _0544_OutputContestMatches) {
    LC::_0544_OutputContestMatches obj;
    std::string base="((((1,16),(8,9)),((4,13),(5,12))),(((2,15),(7,10)),((3,14),(6,11))))";
    EXPECT_EQ(base, obj.findContestMatch(16));
}


TEST(LC, _0816_AmbiguousCoordinates) {
    LC::_0816_AmbiguousCoordinates obj;
    std::vector<std::string> base1{"(0, 123)","(0, 1.23)","(0, 12.3)","(0.1, 23)","(0.1, 2.3)","(0.12, 3)"};
    EXPECT_EQ(obj.ambiguousCoordinates("(0123)"), base1);

    std::vector<std::string> base2{"(0, 0.011)", "(0.001, 1)"};
    EXPECT_EQ(obj.ambiguousCoordinates("(00011)"), base2);

    std::vector<std::string> base3{"(10, 0)"};
    EXPECT_EQ(obj.ambiguousCoordinates("(100)"), base3);
}

TEST(LC, _0179_LargestNumber) {
    LC::_0179_LargestNumber obj;
    std::vector<int> v{10, 2};
    EXPECT_EQ(obj.largestNumber(v), "210");
}