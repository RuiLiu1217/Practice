#ifndef LEETCODE_STRINGPROBLEMS_HPP
#define LEETCODE_STRINGPROBLEMS_HPP
#include <vector>
#include <string>
namespace LC {
/*
    Tag: string, palindromic
    Given a string s, find the longest palindromic substring in s. You may assume that 
    the maximum length of s is 1000.

    Input: "babad"          :         Output: "bab"
    Note: "aba" is also a valid answer.

    Input: "cbbd"           :         Output: "bb"
*/
class _0005_LongestPalindromicSubstring {
public:
    std::string longestPalidrome(std::string s);
};


/*
Tag: string, mathematics, array
The string "PAYPALISHIRING" is written in a zigzag pattern 
on a given number of rows like this: (you may want to 
display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion 
given a number of rows:

string convert(string s, int numRows);

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

        P     I    N
        A   L S  I G
        Y A   H R
        P     I
*/
class _0006_ZigZagConversion {
public:
    std::string convert(std::string s, int numRows);
};


/* 
Tag: string, overflow consideration
Implement atoi which converts a string to an integer.
The function first discards as many whitespace characters as 
necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial 
plus or minus sign followed by as many numerical digits as 
possible, and interprets them as a numerical value.

The string can contain additional characters after those that form 
the integral number, which are ignored and have no effect on the 
behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
If no valid conversion could be performed, a zero value is returned.

Note:
Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Input: "42"        :        Output: 42
Input: "   -42"    :        Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Input: "4193 with words"     :      Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Input: "words and 987"       :      Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.

Input: "-91283472332"        :      Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
    Thefore INT_MIN (−231) is returned.
*/
class _0008_StringToInteger {
public:
    int myAtoi(std::string str);
};

/*
Tag: string
Write a function to find the longest common prefix string among an array of strings.
If there is no common prefix, return an empty string "".

Input: ["flower","flow","flight"]
Output: "fl"

Input: ["dog","racecar","car"]
Output: ""

Explanation: There is no common prefix among the input strings.
*/
class _0014_LongestCommonPrefix {
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs);
};

}
#endif