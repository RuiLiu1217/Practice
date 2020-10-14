#ifndef LEETCODE_STRINGPROBLEMS_HPP
#define LEETCODE_STRINGPROBLEMS_HPP
#include "HeaderFiles.hpp"
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


/*
Tag: string
The count-and-say sequence is the sequence of integers with the first five 
terms as following:
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
Note: Each term of the sequence of integers will be represented as a string.
*/
class _0038_CountAndSay {
public:
    std::string countAndSay(int n);
};

/*
Tag: string operation, basic arithmetic operation
Given two non-negative integers num1 and num2 represented as strings, return the product 
of num1 and num2, also represented as a string.
Example 1:
Input: num1 = "2", num2 = "3"          :         Output: "6"
Input: num1 = "123", num2 = "456"      :         Output: "56088"

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class _0043_MultiplyStrings {
public:
    std::string multiply(std::string num1, std::string num2);
private:
    std::string multiply(const std::string& num1, const std::string& num2, int idx);
    std::string add(std::string num1, std::string num2);
};


/*  Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
return the length of last word in the string. If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.

Input: "Hello World"
Output: 5
*/
class _0058_LengthOfLastWord{
public:
    int lengthOfLastWord(std::string s);
};


/*

Facebook
Tag: palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters 
and ignoring cases. 
Note: For the purpose of this problem, we define empty string as valid palindrome.

Input: "A man, a plan, a canal: Panama"     :      Output: true
Input: "race a car"                         :      Output: false
*/
class _0125_ValidPalindrome {
public:
    bool isPalindrome(std::string s);
};



/*
Tag: Stack
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a 
result and there won't be any divide by zero operation.


Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/
class _0150_EvaluateReversePolishNotation {
public:
    int evalRPN(std::vector<std::string>& tokens);
};



/*
TAG: string, stringstream
TODO: Operation on stirng is very tricky and important
Given an input string, reverse the string word by word.

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
*/
class _0151_ReverseWordsInAString {
public:
    std::string reverseWords(std::string s);
    std::string reverseWords_O1(std::string s);
};


/*
Tag: string,
TODO: Too much details need to be considered

Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth 
second-level revision of the second first-level revision.
You may assume the default revision number for each level of a version number to be 0. 
For example, version number 3.4 has a revision number of 3 and 4 for its first and second 
level revision number. Its third and fourth level revision number are both 0.

Input: version1 = "0.1", version2 = "1.1"             :          Output: -1
Input: version1 = "1.0.1", version2 = "1"             :          Output: 1
Input: version1 = "7.5.2.4", version2 = "7.5.3"       :          Output: -1
Input: version1 = "1.01", version2 = "1.001"          :          Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a 
third level revision number, which means its third level 
revision number is default to "0"

Note:

Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
Version strings do not start or end with dots, and they will not be two consecutive dots.
*/
class _0165_CompareVersionNumbers {
private:
    int findDot(const std::string& v);
    std::string removeHeadingZeros(const std::string& v);
public:
    int compareVersion(std::string version1, std::string version2);

};

/*
Given a list of non negative integers, arrange them such that they 
form the largest number.

Input: [10,2]
Output: "210"

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/
class _0179_LargestNumber {
public:
    std::string largestNumber(std::vector<int>& nums);
};



/*
Given an input string , reverse the string word by word. 

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note: 

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?
*/
class _0186_ReverseWordsInAStringII {
public:
    void reverseWords(std::vector<char>& s);
};

/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to 
identify repeated sequences within the DNA.
Write a function to find all the 10-letter-long sequences (substrings) that 
occur more than once in a DNA molecule.

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/
class _0187_RepeatedDNASequences {
public:
    std::vector<std::string> findRepeatedDNASequences(std::string s);
    std::vector<std::string> findRepeatedDNASequence_NoMap(std::string s);
};


/*
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while 
preserving the order of characters. No two characters may map to the same 
character but a character may map to itself.

Input: s = "egg", t = "add"
Output: true

Input: s = "foo", t = "bar"
Output: false

Input: s = "paper", t = "title"
Output: true
*/
class _0205_IsomorphicStrings {
public:
    bool isIsomorphic(std::string s, std::string t);
};




/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
class _0208_ImplementTrie {
public:
     /** Initialize your data structure here. */
    _0208_ImplementTrie();
    
    /** Inserts a word into the trie. */
    void insert(std::string word);
    
    /** Returns if the word is in the trie. */
    bool search(std::string word);

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix);
private:
    std::unordered_map<char, _0208_ImplementTrie*> children;
    bool isWord = false;
};



/*
Facebook
!!! Copy from solution !!!
Design a data structure that supports the following two operations:
void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string 
containing only letters a-z or .. A . means it can represent any one letter.

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z. */
class _0211_AddAndSearchWordDataStructureDesign {
    class TrieNode {
    public:
        bool word;
        TrieNode* children[26];
        TrieNode() {
            word = false;
            for(int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };
public:
    _0211_AddAndSearchWordDataStructureDesign() {}
    void addWord(std::string word);
    bool search(std::string word);
private:
    TrieNode* root = new TrieNode();
    bool search(const char* word, TrieNode* node);
};



/* Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), 
the plus + or minus sign -, non-negative integers and empty spaces .

Input: "1 + 1"                  :    Output: 2
Input: " 2-1 + 2 "              :    Output: 3
Input: "(1+(4+5+2)-3)+(6+8)"    :    Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
class _0224_BasicCalculator {
public:
    int calculate(std::string s);
private:
    void pushNum(std::stack<double>& numStack, std::string& tmp);
    void cal(std::stack<double>& numStack, char op);
    int priority(char op);
};


/*
Given a string of numbers and operators, return all possible results from computing 
all the different possible ways to group numbers and operators. The valid operators 
are +, - and *.

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/
class _0241_DifferentWaysToAddParentheses {
private:
    std::unordered_map<std::string, std::vector<int>> map;
public:
    std::vector<int> diffWaysToCompute(std::string input);
    std::vector<int> diffWaysToComp(const std::string& input, int start, int end);
};



/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
class _0242_ValidAnagram {
public:
    bool isAnagram(std::string s, std::string t);
};


/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true
Example 2:

Input:  "88"
Output: true
Example 3:

Input:  "962"
Output: false
*/
class _0246_StrobogrammaticNumber {
public:
    bool isStrobogrammatic(std::string num);
};


/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
Find all strobogrammatic numbers that are of length = n.

Example:

Input:  n = 2
Output: ["11","69","88","96"]
*/
class _0247_StrobogrammaticNumberII {
public:
    std::vector<std::string> findStrobogrammatic(int n);
private:
    void DFS(std::unordered_set<char> set, int curLen, int n, std::string tmp, std::vector<std::string>& res);
};


/*
Given a string, determine if a permutation of the string could form a palindrome.
Input: "code"       :      Output: false
Input: "aab"        :      Output: true
Input: "carerac"    :      Output: true
*/
class _0266_PalinndromePermutation {
public:
    bool canPermutePalindrome(std::string s);
};


/*
You are playing the following Flip Game with your friend: Given a string that contains 
only these two characters: + and -, you and your friend take turns to flip two consecutive
"++" into "--". The game ends when a person can no longer make a move and therefore the 
other person will be the winner.
Write a function to compute all possible states of the string after one valid move.

Input: s = "++++"
Output: 
[
  "--++",
  "+--+",
  "++--"
]
Note: If there is no valid move, return an empty list [].
*/
class _0293_FlipGame {
public:
    std::vector<std::string> generatePossibleNextMoves(std::string s);
};


/*
Write a function that reverses a string. The input string is given as 
an array of characters char[].
Do not allocate extra space for another array, you must do this by 
modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/
class _0344_ReverseString {
public:
    void reverseString(std::vector<char>& s);
};


/*
Write a function that takes a string as input and reverse only the vowels of a string.

Input: "hello"
Output: "holle"

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*/
class _0345_ReverseVowelsOfAString {
public:
    std::string reverseVowels(std::string s);
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};


/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function 
that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/
class _0383_RansomNote {
public:
    bool canConstruct(std::string ransomNote, std::string magazine);
};

/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
s = "leetcode"              :        return 0.
s = "loveleetcode",         :        return 2.
*/
class _0387_FirstUniqueCharacterInAString {
public:
    int firstUniqChar(std::string s);
};


/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

Input: s = "a"
Output: 1

Input: s = "bb"
Output: 2

Constraints:

1 <= s.length <= 2000
s consits of lower-case and/or upper-case English letters only.
*/
class _0409_LongestPalindrome {
public:
    int longestPalindrome(std::string s);
};

/*
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for 
the multiples of five output “Buzz”. For numbers which are multiples of both 
three and five output “FizzBuzz”.

n = 15,
Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/
class _0412_FizzBuzz {
public:
    std::vector<std::string> fizzBuzz(int n);
};

/*
Facebook
Tag: string operation, math
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class _0415_AddStrings {
public:
    std::string addStrings(std::string num1, std::string num2);
};


/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.

Input: "owoztneoer"
Output: "012"

Input: "fviefuro"
Output: "45"
*/
class _0423_ReconstructOriginalDigitFromEnglish {
public:
    std::string originalDigits(std::string s);
};

/* Facebook

Tag: hash, string

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p 
will not be larger than 20,100. The order of output does not matter.

Input: s: "cbaebabacd" p: "abc"            :              Output: [0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".


Input: s: "abab" p: "ab"                   :              Output: [0, 1, 2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
class _0438_FindAllAnagramsInAString {
public:
    std::vector<int> findAnagrams(std::string s, std::string p);
};


/*
Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", 
so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
Now we have another string p. Your job is to find out how many unique non-empty substrings of 
p are present in s. In particular, your input is the string p and you need to output the number 
of different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.

Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.

Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
*/
class _0467_UniqueSubstringsInWraparoundString {
public:
    int findSubstringInWraproundString(std::string p);
};

/*
You are given a license key represented as a string S which consists only alphanumeric character and dashes. 
The string is separated into N+1 groups by N dashes.
Given a number K, we would want to reformat the strings such that each group contains exactly K characters, 
except for the first group which could be shorter than K, but still must contain at least one character. 
Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.

Given a non-empty string S and a number K, format the string according to the rules described above.

Example 1:
Input: S = "5F3Z-2e-9-w", K = 4
Output: "5F3Z-2E9W"

Explanation: The string S has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.
Example 2:
Input: S = "2-5g-3-J", K = 2
Output: "2-5G-3J"

Explanation: The string S has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
Note:
The length of string S will not exceed 12,000, and K is a positive integer.
String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
String S is non-empty.
*/
class _0482_LicenseKeyFormatting {
public:
    std::string licenseKeyFormatting(std::string S, int K);
};

/*
During the NBA playoffs, we always arrange the rather strong team to play with the rather weak team, like make the rank 1 team play with the rank nth team, which is a good strategy to make the contest more interesting. Now, you're given n teams, you need to output their final contest matches in the form of a string.

The n teams are given in the form of positive integers from 1 to n, which represents their initial rank. (Rank 1 is the strongest team and Rank n is the weakest team.) We'll use parentheses('(', ')') and commas(',') to represent the contest team pairing - parentheses('(' , ')') for pairing and commas(',') for partition. During the pairing process in each round, you always need to follow the strategy of making the rather strong one pair with the rather weak one.

Example 1:
Input: 2
Output: (1,2)
Explanation: 
Initially, we have the team 1 and the team 2, placed like: 1,2.
Then we pair the team (1,2) together with '(', ')' and ',', which is the final answer.
Example 2:
Input: 4
Output: ((1,4),(2,3))
Explanation: 
In the first round, we pair the team 1 and 4, the team 2 and 3 together, as we need to make the strong team and weak team together.
And we got (1,4),(2,3).
In the second round, the winners of (1,4) and (2,3) need to play again to generate the final winner, so you need to add the paratheses outside them.
And we got the final answer ((1,4),(2,3)).
Example 3:
Input: 8
Output: (((1,8),(4,5)),((2,7),(3,6)))
Explanation: 
First round: (1,8),(2,7),(3,6),(4,5)
Second round: ((1,8),(4,5)),((2,7),(3,6))
Third round: (((1,8),(4,5)),((2,7),(3,6)))
Since the third round will generate the final winner, you need to output the answer (((1,8),(4,5)),((2,7),(3,6))).
Note:
The n is in range [2, 212].
We ensure that the input n can be converted into the form 2k, where k is a positive integer.
*/
class _0544_OutputContestMatches {
public:
    std::string findContestMatch(int n);
};


/*
Given two strings s1 and s2, write a function to return true if s2 
contains the permutation of s1. In other words, one of the first 
string's permutations is the substring of the second string.

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Input:s1= "ab" s2 = "eidboaoo"
Output: False

Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/
class _0567_PermutationInString {
public:
    bool checkInclusion(std::string s1, std::string s2);
};

/*
Given a string representing an expression of fraction addition and subtraction, 
you need to return the calculation result in string format. The final result should 
be irreducible fraction. If your final result is an integer, say 2, you need to change 
it to the format of fraction that has denominator 1. So in this case, 2 should be 
converted to 2/1.

Input:"-1/2+1/2"
Output: "0/1"

Input:"-1/2+1/2+1/3"
Output: "1/3"

Input:"1/3-1/2"
Output: "-1/6"

Input:"5/3+1/3"
Output: "2/1"
Note:
The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has format ±numerator/denominator. If the first input 
fraction or the output is positive, then '+' will be omitted. The input only contains valid 
irreducible fractions, where the numerator and denominator of each fraction will always 
be in the range [1,10]. If the denominator is 1, it means this fraction is actually an 
integer in a fraction format defined above.
The number of given fractions will be in the range [1,10].
The numerator and denominator of the final result are guaranteed to be valid and in the 
range of 32-bit int.
*/
class _0592_FractionAdditionAndSubtraction {
public:
    std::string fractionAddition(std::string expression);
};

/*
    Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings 
    in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. 
    Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

    Input: 
    s = "abcxyz123"
    dict = ["abc","123"]
    Output:
    "<b>abc</b>xyz<b>123</b>"

    Input: 
    s = "aaabbcc"
    dict = ["aaa","aab","bc"]
    Output:
    "<b>aaabbc</b>c"
    
    Constraints:
    The given dict won't contain duplicates, and its length won't exceed 100.
    All the strings in input have length in range [1, 1000].
*/
class _0616_AddBoldTagInString {
public:
    std::string addBoldTag(std::string s, std::vector<std::string>& dict);
private:
    std::vector<std::vector<int>> mergeIntervals(std::vector<std::vector<int>>& intervals) {
        std::sort(begin(intervals), end(intervals), [](std::vector<int> a, std::vector<int> b){
            return (a[0] < b[0]) || (a[0] == b[0]) && (a[1] < b[1]);
        });

        std::vector<std::vector<int>> res;
        if(intervals.size() > 0) {
            res.push_back(intervals.front());
        }

        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] <= res.back()[1]) { // "=" means  [1, 2] [2, 3] will be merged to [1, 3] to avoid <b>a</b><b>c</b> case happens
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }

    std::vector<std::vector<int>> generateIntervals(const std::string& s, const std::vector<std::string>& dict) {
        std::vector<std::vector<int>> intervals;
        for(const std::string& word : dict) {
            for(int i = 0; (i = s.find(word, i)) != std::string::npos; ++i) {
                intervals.push_back({i, i + static_cast<int>(word.size())});
            }
        }
        return intervals;
    }
};

/*
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Input: "aba"
Output: True

Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*/
class _0680_ValidPalindromeII {
public:
    bool validPalindrome(std::string s);
};

/*
709. To Lower Case
Implement function ToLowerCase() that has a string parameter 
str, and returns the same string in lowercase.

Input: "Hello"
Output: "hello"

Input: "here"
Output: "here"

Input: "LOVELY"
Output: "lovely"
*/
class _0709_ToLowerCase {
public:
    std::string toLowerCase(std::string str);
};

/*
Given a set of keywords words and a string S, make all appearances of all keywords in S bold. 
Any letters between <b> and </b> tags become bold.
The returned string should use the least number of tags possible, and of course the tags should 
form a valid combination.
For example, given that words = ["ab", "bc"] and S = "aabcd", we should return "a<b>abc</b>d". 
Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.

Constraints:

words has length in range [0, 50].
words[i] has length in range [1, 10].
S has length in range [0, 500].
All characters in words[i] and S are lowercase letters.
*/
class _0758_BoldWordsInString {
public:
    std::string boldWords(std::vector<std::string>& words, std::string S);
    void setBold(std::vector<bool>& isBold, int i, int wl);
};

    /*
International Morse Code defines a standard encoding where each letter is 
mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" 
maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet 
is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
"--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
"-.--","--.."]

Now, given a list of words, each word can be written as a concatenation of 
the Morse code of each letter. For example, "cba" can be written as "-.-..--...", 
(which is the concatenation "-.-." + "-..." + ".-"). We'll call such a 
concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation: 
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
Note:

The length of words will be at most 100.
Each words[i] will have length in range [1, 12].
words[i] will only consist of lowercase letters.
*/
class _0804_UniqueMorseCodeWords {
public:
    int uniqueMorseRepresentations(std::vector<std::string>& words);
};


/*
We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  Then, we removed all commas, decimal points, 
and spaces, and ended up with the string S.  Return a list of strings representing all possibilities for what our 
original coordinates could have been.
Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", 
"1.0", "001", "00.01", or any other number that can be represented with less digits. Also, a decimal point within 
a number never occurs without at least one digit occuring before it, so we never started with numbers like ".1".
The final answer list can be returned in any order.  Also note that all coordinates in the final answer have 
exactly one space between them (occurring after the comma.)

Input: "(123)"
Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]

Input: "(00011)"
Output:  ["(0.001, 1)", "(0, 0.011)"]
Explanation: 
0.0, 00, 0001 or 00.01 are not allowed.

Input: "(0123)"
Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]

Input: "(100)"
Output: [(10, 0)]
Explanation: 
1.0 is not allowed.

Note:

4 <= S.length <= 12.
S[0] = "(", S[S.length - 1] = ")", and the other elements in S are digits.
*/
class _0816_AmbiguousCoordinates {
public:
    std::vector<std::string> ambiguousCoordinates(std::string S);
};

/*
A sentence S is given, composed of words separated by spaces. 
Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)
The rules of Goat Latin are as follows:
If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.
If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".
Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin. 

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 

Notes:

S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.
*/
class _0824_GoatLatin {
public:
    std::string toGoatLatin(std::string S);
};

/*
Every email consists of a local name and a domain name, separated by the @ sign.
For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.
Besides lowercase letters, these emails may contain '.'s or '+'s.
If you add periods ('.') between some characters in the local name part of an email address, mail 
sent there will be forwarded to the same address without dots in the local name. 
For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address. 
(Note that this rule does not apply for domain names.)
If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. 
This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to
my@email.com.  (Again, this rule does not apply for domain names.)
It is possible to use both of these rules at the same time.
Given a list of emails, we send one email to each address in the list. 
How many different addresses actually receive mails? 

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
 
Note:

1 <= emails[i].length <= 100
1 <= emails.length <= 100
Each emails[i] contains exactly one '@' character.
All local and domain names are non-empty.
Local names do not start with a '+' character.
*/
class _0929_UniqueEmailAddress {
public:
    int numUniqueEmails(std::vector<std::string>& emails);
};

/*
In an alien language, surprisingly they also use english lowercase 
letters, but possibly in a different order. The order of the alphabet 
is some permutation of lowercase letters. Given a sequence of words 
written in the alien language, and the order of the alphabet, return 
true if and only if the given words are sorted lexicographicaly in 
this alien language.

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
All characters in words[i] and order are English lowercase letters.
*/
class _0953_VerifyingAnAlienDictionary {
public:
    bool isAlienSorted(std::vector<std::string>& words, std::string order) {
        int mapping[26];
        for(int i = 0 ; i < 26; ++i) {
            mapping[order[i] - 'a'] = i; // map "cab" --> "abc" which is the correct order
        }
        for(std::string& w : words) {
            for(char& c : w) {
                c = mapping[c - 'a']; // map the normal word to mapped character word with mapping
            }
        }
        return std::is_sorted(begin(words), end(words)); //! The function that I didn't know that can judge whether an array is sorted.
    }
};

/*
Given an array A of strings made only from lowercase letters, return a list 
of all characters that show up in all strings within the list (including 
duplicates). For example, if a character occurs 3 times in all strings but 
not 4 times, you need to include that character three times in the final 
answer.
You may return the answer in any order.

Input: ["bella","label","roller"]
Output: ["e","l","l"]

Input: ["cool","lock","cook"]
Output: ["c","o"]
Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
*/
class _1002_FindCommonCharacters {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& A);
};

/*
Given a binary string S (a string consisting only of '0' and '1's) and a positive integer N, 
return true if and only if for every integer X from 1 to N, the binary representation of X 
is a substring of S.

Input: S = "0110", N = 3
Output: true

Input: S = "0110", N = 4
Output: false

Note:

1 <= S.length <= 1000
1 <= N <= 10^9
*/
class _1016_BinaryStringWithSubstringsRepresenting1ToN {
public:
    bool queryString(std::string S, int N);
};

/*
A string S represents a list of words.
Each letter in the word has 1 or more options.  If there is 
one option, the letter is represented as is.  If there is 
more than one option, then curly braces delimit the options. 
For example, "{a,b,c}" represents options ["a", "b", "c"].

For example, "{a,b,c}d{e,f}" represents the list 
["ade", "adf", "bde", "bdf", "cde", "cdf"].

Return all words that can be formed in this manner, 
in lexicographical order.

Input: "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]

Input: "abcd"
Output: ["abcd"]

Note:

1 <= S.length <= 50
There are no nested curly brackets.
All characters inside a pair of consecutive opening and ending curly brackets are different.
*/
class _1087_BraceExpansion {
public:
    std::vector<std::string> expand(std::string S) {
        return expandHelp(S);
    }
    std::vector<std::string> expandHelp(std::string S) {
        std::string prefix;
        int i = 0;
        while(i < S.size() && S[i] != '{') {
            prefix += S[i++];
        }
        if(i < S.size()) {
            int j = i + 1;
            while(j < S.size() && S[j] != '}') {
                ++j;
            }
            std::string toSplit = S.substr(i+1, j-i-1);
            std::stringstream iss(toSplit);
            std::vector<std::string> tokens;
            std::string token;
            while(getline(iss, token, ',')) {
                tokens.push_back(token);
            }
            std::sort(begin(tokens), end(tokens));
            std::vector<std::string> suffix = expandHelp(S.substr(j+1));
            std::vector<std::string> res;
            for(auto& tok : tokens) {
                for(auto& suf: suffix) {
                    res.push_back(prefix + tok + suf);
                }
            }
            return res;            
        } else {
            return {prefix};
        }
    }
};



/*
Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.

Input: "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"

Input: "aeiou"
Output: ""

Note:

S consists of lowercase English letters only.
1 <= S.length <= 1000
*/
class _1119_RemoveVowelsFromAString {
private:
    bool isVowels(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    std::string removeVowels(std::string S) {
        int slow = 0;
        std::for_each(begin(S), end(S), [&](char c) {
            if(!isVowels(c)) {
                S[slow++] = c;
            }
        });        
        S.resize(slow);
        return S;
    }
};

/*
There is a special keyboard with all keys in a single row.

Given a string keyboard of length 26 indicating the layout of the keyboard (indexed from 0 to 25), initially your finger is at index 0. To type a character, you have to move your finger to the index of the desired character. The time taken to move your finger from index i to index j is |i - j|.

You want to type a string word. Write a function to calculate how much time it takes to type it with one finger.

 

Example 1:

Input: keyboard = "abcdefghijklmnopqrstuvwxyz", word = "cba"
Output: 4
Explanation: The index moves from 0 to 2 to write 'c' then to 1 to write 'b' then to 0 again to write 'a'.
Total time = 2 + 1 + 1 = 4. 
Example 2:

Input: keyboard = "pqrstuvwxyzabcdefghijklmno", word = "leetcode"
Output: 73
 

Constraints:

keyboard.length == 26
keyboard contains each English lowercase letter exactly once in some order.
1 <= word.length <= 10^4
word[i] is an English lowercase letter.
*/
class _1165_SingleRowKeyboard {
public:
    int calculateTime(std::string keyboard, std::string word) {
        auto iter = begin(keyboard);
        int dis = 0;
        for(int i = 0; i < word.size(); ++i) {
            auto newIter = std::find(begin(keyboard), end(keyboard), word[i]);
            dis += std::abs(std::distance(newIter, iter));
            iter = newIter;
        }
        return dis;
    }
};

/*
Split a String in Balanced Strings
Balanced strings are those who have equal quantity of 'L' and 'R' characters.
Given a balanced string s split it in the maximum amount of balanced strings.
Return the maximum amount of splitted balanced strings.

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

Input: s = "RLLLLRRRLR"
Output: 3
Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'

Constraints:
1 <= s.length <= 1000
s[i] = 'L' or 'R'
*/
class _1221_SplitAStringInBalancedStrings {
public:
    int balancedStringSplit(std::string s);
};

/*
Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English 
lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.
It's guaranteed that a unique mapping will always exist.

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

Input: s = "1326#"
Output: "acz"

Input: s = "25#"
Output: "y"

Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
Output: "abcdefghijklmnopqrstuvwxyz"

Constraints:
1 <= s.length <= 1000
s[i] only contains digits letters ('0'-'9') and '#' letter.
s will be valid string such that mapping is always possible.
*/
class _1309_DecryptStringFromAlphabetToIngeterMapping {
public:
    std::string freqAlphabets(std::string s) {
        std::string res;
        for(int i = 0; i < s.size(); ++i) {
            if(i < s.size() - 2 && s[i+2] == '#') {
                res += 'j' + (s[i] - '1') * 10 + (s[i+1] - '0');
                i += 2;
                continue;
            } else {
                res += 'a' + (s[i] - '1');
            }
        }
        return res;
    }
};


/*
Given a string s. Return all the words vertically in the same order in which they appear in s.
Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
Each word would be put on only one column and that in one column there will be only one word.

Input: s = "HOW ARE YOU"
Output: ["HAY","ORO","WEU"]
Explanation: Each word is printed vertically. 
 "HAY"
 "ORO"
 "WEU"

Input: s = "TO BE OR NOT TO BE"
Output: ["TBONTB","OEROOE","   T"]
Explanation: Trailing spaces is not allowed. 
"TBONTB"
"OEROOE"
"   T"

Input: s = "CONTEST IS COMING"
Output: ["CIC","OSO","N M","T I","E N","S G","T"]

Constraints:

1 <= s.length <= 200
s contains only upper case English letters.
It's guaranteed that there is only one space between 2 words.
*/
class _1324_PrintWordsVertically {
public:
    std::vector<std::string> printVertically(std::string s) {
        std::istringstream iss(s);
        std::string token;
        std::vector<std::string> tokens;
        int maxLen = 0;
        while(getline(iss, token, ' ')) {
            if(!token.empty()) {
                if(token.size() > maxLen) {
                    maxLen = token.size();
                }
                tokens.push_back(token);
            }            
        }
        std::vector<std::string> res(maxLen, std::string(tokens.size(), ' '));
        for(int i = 0; i < tokens.size(); ++i) {
            for(int j = 0; j < tokens[i].size(); ++j) {
                res[j][i] = tokens[i][j];
            }
        }
        for(auto& r : res) {
            int j = r.size()-1;
            while(j >= 0 && r[j] == ' ') {
                --j;
            }
            r = r.substr(0, j+1);
        }
        return res;
    }
};

/*
Given a string s. You should re-order the string using the following algorithm:

Pick the smallest character from s and append it to the result.
Pick the smallest character from s which is greater than the last appended character to the result and append it.
Repeat step 2 until you cannot pick more characters.
Pick the largest character from s and append it to the result.
Pick the largest character from s which is smaller than the last appended character to the result and append it.
Repeat step 5 until you cannot pick more characters.
Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.

Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
Example 2:

Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.

Input: s = "leetcode"
Output: "cdelotee"

Input: s = "ggggggg"
Output: "ggggggg"

Input: s = "spo"
Output: "ops"
 

Constraints:

1 <= s.length <= 500
s contains only lower-case English letters.
*/
class _1370_IncreasingDecreasingString {
public:
    std::string sortString(std::string s);
};


    /*
    Given a string s of zeros and ones, return the maximum score after splitting the string into two 
    non-empty substrings (i.e. left substring and right substring).
    The score after splitting a string is the number of zeros in the left substring plus the number 
    of ones in the right substring.
    
    Input: s = "011101"
    Output: 5 
    Explanation: 
    
    All possible ways of splitting s into two non-empty substrings are:
    left = "0" and right = "11101", score = 1 + 4 = 5 
    left = "01" and right = "1101", score = 1 + 3 = 4 
    left = "011" and right = "101", score = 1 + 2 = 3 
    left = "0111" and right = "01", score = 1 + 1 = 2 
    left = "01110" and right = "1", score = 2 + 1 = 3
    
    Example 2:
    Input: s = "00111"
    Output: 5
    Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
    
    Input: s = "1111"
    Output: 3
    
    Constraints:
        2 <= s.length <= 500
        The string s consists of characters '0' and '1' only.
    */
    class _1422_MaximumScoreAfterSplittingAString {
        public:
            int maxScore(std::string s);
    };

/*
    Given a sentence text (A sentence is a string of space-separated words) in the following format:

    First letter is in upper case.
    Each word in text are separated by a single space.
    Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.

    Return the new text following the format shown above.
    Input: text = "Leetcode is cool"
    Output: "Is cool leetcode"
    Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
    Output is ordered by length and the new first word starts with capital letter.

    Input: text = "Keep calm and code on"
    Output: "On and keep calm code"
    Explanation: Output is ordered as follows:
    "On" 2 letters.
    "and" 3 letters.
    "keep" 4 letters in case of tie order by position in original text.
    "calm" 4 letters.
    "code" 4 letters.

    Input: text = "To be or not to be"
    Output: "To be or to be not"
    

    Constraints:

    text begins with a capital letter and then contains lowercase letters and single space between words.
    1 <= text.length <= 10^5
    */
    class _1451_RearrangeWordsInASentence {
        public:
            std::string arrangeWords(std::string text);
    };
    
/*
Given a binary string s and an integer k.

Return True if all binary codes of length k is a substring of s. Otherwise, return False.

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indicies 0, 1, 3 and 2 respectively.

Input: s = "00110", k = 2
Output: true

Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 

Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and doesn't exist in the array.

Input: s = "0000000001011100", k = 4
Output: false

Constraints:

1 <= s.length <= 5 * 10^5
s consists of 0's and 1's only.
1 <= k <= 20
    */
class _1461_CheckIfAStringContainsAllBinaryCodesofSizeK {
    public:
        bool hasAllCodes(std::string s, int k);
};


/*
Given a string s and an integer array indices of the same length.

The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.

Input: s = "aiohn", indices = [3,1,4,2,0]
Output: "nihao"

Input: s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
Output: "arigatou"

Input: s = "art", indices = [1,0,2]
Output: "rat"
 

Constraints:

s.length == indices.length == n
1 <= n <= 100
s contains only lower-case English letters.
0 <= indices[i] < n
All values of indices are unique (i.e. indices is a permutation of the integers from 0 to n - 1).
*/
class _1528_ShuffleString {
public:
    std::string restoreString(std::string s, std::vector<int>& indices) {
        std::string res = s;
        for(int i = 0; i < indices.size(); ++i) {
            res[indices[i]] = s[i];
        }
        return res;
    }
};

}
#endif