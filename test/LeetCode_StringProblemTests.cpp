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

TEST(LC, _0224_BasicCalculator) {
    LC::_0224_BasicCalculator obj;
    std::string exp1{"1+2*2"};
    EXPECT_EQ(obj.calculate(exp1), 5);

    std::string exp2{"((1+1) * 3 - 2) / 2 + (((3*2-3/3)+(5) + 2) / 3)"};
    EXPECT_EQ(obj.calculate(exp2), 6);
}

TEST(LC, _0241_DifferentWaysToAddParentheses) {
    LC::_0241_DifferentWaysToAddParentheses obj;
    std::vector<int> base{2, 0};
    EXPECT_EQ(obj.diffWaysToCompute("2-1-1"), base);
    std::vector<int> base2{-34, -10, -14, -10, 10};
    EXPECT_EQ(obj.diffWaysToCompute("2*3-4*5"), base2);
}

TEST(LC, _0467_UniqueSubstringsInWraparoundString) {
    LC::_0467_UniqueSubstringsInWraparoundString obj;
    EXPECT_EQ(obj.findSubstringInWraproundString("cac"), 2);
    EXPECT_EQ(obj.findSubstringInWraproundString("cabcde"), 15);
    EXPECT_EQ(obj.findSubstringInWraproundString("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"), 36179);
}

TEST(LC, _0293_FlipGame) {
    LC::_0293_FlipGame obj;
    std::string s = "++++";
    std::vector<std::string> base{"--++", "+--+", "++--"};
    std::vector<std::string> res = obj.generatePossibleNextMoves(s);
    EXPECT_EQ(base, res);
}

TEST(LC, _0344_ReverseString) {
    LC::_0344_ReverseString obj;
    std::vector<char> a = {'a', 'b', 'c', 'd'};
    std::vector<char> b = {'d', 'c', 'b', 'a'};
    obj.reverseString(a);
    EXPECT_EQ(a, b);
}

TEST(LC, _0345_ReverseVowelsOfAString) {
    LC::_0345_ReverseVowelsOfAString obj;
    EXPECT_EQ(obj.reverseVowels("hello"), "holle");
}

TEST(LC, _0383_RansomNote) {
    LC::_0383_RansomNote obj;
    EXPECT_TRUE(obj.canConstruct("ab", "aab"));
    EXPECT_FALSE(obj.canConstruct("bab", "aab"));
}

TEST(LC, _0387_FirstUniqueCharacterInAString) {
    LC::_0387_FirstUniqueCharacterInAString obj;
    EXPECT_EQ(obj.firstUniqChar("leetcode"), 0);
}

TEST(LC, _0409_LongestPalindrome) {
    LC::_0409_LongestPalindrome obj;
    EXPECT_EQ(obj.longestPalindrome("abccccdd"), 7);
}

TEST(LC, _0412_FizzBuzz) {
    LC::_0412_FizzBuzz obj;
    std::vector<std::string> base {"1", "2", "Fizz", "4", "Buzz",
    "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"};
    EXPECT_EQ(obj.fizzBuzz(15), base);
}

TEST(LC, _0415_AddStrings) {
    LC::_0415_AddStrings obj;
    EXPECT_EQ(obj.addStrings("111", "345"), "456");   
}

TEST(LC, _0423_ReconstructOriginalDigitFromEnglish) {
    LC::_0423_ReconstructOriginalDigitFromEnglish obj;
    EXPECT_EQ(obj.originalDigits("onetowthreefour"), "1234");
}

TEST(LC, _0438_FindAllAnagramsInAString) {
    LC::_0438_FindAllAnagramsInAString obj;
    std::vector<int> base{0,6};
    EXPECT_EQ(obj.findAnagrams("cbaebabacd", "abc"), base);
}

TEST(LC, _0482_) {
    EXPECT_EQ(true, true);
}