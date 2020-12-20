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
Tag: string, stringstream operation
Todo: familar with stringstream
Given an absolute path for a file (Unix-style), simplify it. Or in other words, 
convert it to the canonical path. In a UNIX-style file system, a period . refers to 
the current directory. Furthermore, a double period .. moves the directory up a 
level. For more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and there 
must be only a single slash / between two directory names. The last directory name 
(if it exists) must not end with a trailing /. Also, the canonical path must be 
the shortest string representing the absolute path. 

Input: "/home/"                :           Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Input: "/../"                  :           Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the 
root level is the highest level you can go.

Input: "/home//foo/"           :           Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced 
by a single one.

Input: "/a/./b/../../c/"       :           Output: "/c"

Input: "/a/../../b/../c//.//"  :           Output: "/c"

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
*/
class _0071_SimplifyPath{
public:
    std::string simplifyPath(std::string path) {
        std::stringstream iss(path);
        std::string token;
        std::stack<std::string> tokens;
        while(getline(iss, token, '/')) {
            if(!token.empty()) {
                if(token == "..") {
                    if(!tokens.empty()) {
                        tokens.pop();
                    }
                } else if(token != ".") {
                    tokens.push(token);
                }
            }
        }
        std::string res;
        while(!tokens.empty()){
            res = tokens.top() + res;
            tokens.pop();
            res = "/" + res;
        }
        if(res.empty()) {
            res = "/";
        }
        return res;
    }
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
Given two strings s and t, determine if they are both one edit distance apart.

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.

*/
class _0161_OneEditDistance {
public:
    bool isOneEditDistance(std::string s, std::string t) {
        const int ns = s.length();
        const int nt = t.length();
        
        if(ns > nt) { // ! 总是计算s较小的情况比较容易。
            return isOneEditDistance(t, s);
        }
        
        if(nt - ns > 1) {
            return false;
        }
        
        for(int i = 0; i < ns; ++i) {
            if(s[i] != t[i]) {
                if(ns == nt) {
                    return s.substr(i+1) == t.substr(i+1);
                } else {
                    return s.substr(i) == t.substr(i+1);
                }
            } 
        }
        return (ns + 1 == nt);
    }
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
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output: 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/
class _0249_GroupShiftedStrings {
public:
    std::vector<std::vector<std::string>> groupStrings(std::vector<std::string>& strings) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for(std::string& s : strings) {
            std::string ts = transback(s); // Create a virtual base that all strings transback to the base, this base is used as a key
            map[ts].push_back(s);
        }
        std::vector<std::vector<std::string>> res;
        for(auto& m : map) {
            res.push_back(m.second);
        }
        return res;
    }
    std::string transback(std::string& s) {
        int l = s[0] - 'a';
        std::string res;
        for(auto& c : s) {
            res += static_cast<char>((c - l + 26) % 26);
        }
        return res;
    }
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
Given a string array words, find the maximum value of 
length(word[i]) * length(word[j]) where the two words do not share common letters. 
You may assume that each word will contain only lower case letters. 
If no such two words exist, return 0.

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16 
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4 
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0 
Explanation: No such pair of words.
*/
class _0318_MaximumProductOfWordLengths {
public:
    int maxProduct(std::vector<std::string>& words);
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

/*
You are given a string s, return the number of segments in the string. 

A segment is defined to be a contiguous sequence of non-space characters.

Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]

Input: s = "Hello"
Output: 1

Input: s = "love live! mu'sic forever"
Output: 4

Input: s = ""
Output: 0
Constraints:

0 <= s.length <= 300
s consists of lower-case and upper-case English letters, digits or one of the following characters "!@#$%^&*()_+-=',.:".
The only space character in s is ' '.
*/
class _0434_NumberOfSegmentsInAString {
public:
    int countSegments(std::string s) {
        int segments = 0;
        bool canset = true;
        for(auto& c : s) {
            if(c != ' ') {
                if(canset == true) {
                    ++segments;
                }
                canset = false; // 当前这个字符不是空格，直到遇到下一个空格前，我们都认为是一个单词
                continue;
            } else {
                canset = true;
                continue;
            }
        }
        return segments;
    }
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
Given a string, sort it in decreasing order based on the frequency of characters.

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/
class _0451_SortCharactersByFrequency {
public:
    std::string frequencySort(std::string s) {
        std::unordered_map<char, int> f;
        for(char c : s) {
            ++f[c];
        }
        std::vector<std::pair<char,int>> st(begin(f), end(f));

        std::sort(st.begin(), st.end(), [&](auto& v1, auto& v2){return v1.second > v2.second;});

        std::string res;
        for(auto& s : st) {
            res += std::string(s.second, s.first);
        }
        return res;
    }
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
Given two strings representing two complex numbers.
You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
*/
class _0537_ComplexNumberMultiplication {
public:
    std::string complexNumberMultiply(std::string a, std::string b) {
        int ra, ia, rb, ib;
        char buff;
        std::stringstream aa(a), bb(b), ans; // Use of string stream
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
        return ans.str();
    }
};

/*
Given a string and an integer k, you need to reverse the first k 
characters for every 2k characters counting from the start of the string. 
If there are less than k characters left, reverse all of them. If there 
are less than 2k but greater than or equal to k characters, then reverse 
the first k characters and left the other as original.

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
*/
class _0541_ReverseStringII {
public:
    std::string reverseStr(std::string s, int k) {
        std::vector<std::string> svec;
        split(s, k, svec);
        int cnt = 0;
        std::string res;
        for(int i = 0; i < svec.size(); ++i) {
            if(cnt % 2 == 0) {
                std::reverse(svec[i].begin(), svec[i].end());
            }
            cnt++;
            res += svec[i];
        }
        return res;
    }
private:
    void split(std::string s, int k, std::vector<std::string>& res) {
        if(s.empty()) {
            return;
        }
        if(s.size() <= k) {
            res.push_back(s);
            return;
        }
        std::string head = s.substr(0, k);
        res.push_back(head);
        split(s.substr(k), k, res);
    }
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
Given a string, you need to reverse the order of characters in each word 
within a sentence while still preserving whitespace and initial word order.

Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will 
not be any extra space in the string.
*/
class _0557_ReverseWordsInAStringIII {
public:
    std::string reverseWords(std::string s) {
        int left = 0;
        int right = 0;
        s += ' ';
        while(right < s.size()) {
            if(s[right] == ' ') {
                int i = left;
                int j = right - 1;
                while(i < j) {
                    std::swap(s[i], s[j]);
                    ++i;
                    --j;
                }
                left = right + 1;
                right = left;
            } else {
                ++right;
            }
        }
        return s.substr(0, s.size() - 1);
    }
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
Given two strings A and B, find the minimum number of times A has to be 
repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".
Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring 
of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
!不要把问题想复杂
*/
class _0686_RepeatedStringMatch {
public:
    int repeatedStringMatch(std::string A, std::string B) {
        std::string res = A;
        for(int rep = 1; rep <= B.length() / A.length() + 2; rep++, res += A) {
            if(res.find(B) != std::string::npos) {
                return rep;
            }
        }
        return -1;
    }
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
Given two sentences words1, words2 (each represented as an array of strings), and a list of 
similar word pairs pairs, determine if two sentences are similar. For example, 
      "great acting skills" 
and 
      "fine drama talent" 
are similar, if the similar word pairs are 
pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].
Note that the similarity relation is not transitive. For example, if "great" and "fine" are 
similar, and "fine" and "good" are similar, "great" and "good" are not necessarily similar.
However, similarity is symmetric. For example, "great" and "fine" being similar is the same 
as "fine" and "great" being similar. Also, a word is always similar with itself. For example, 
the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though 
there are no specified similar word pairs.
Finally, sentences can only be similar if they have the same number of words. So a sentence 
like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].
Note:

The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].
*/
class _0734_SentenceSimilarity {
public:
    bool areSentencesSimilar(std::vector<std::string>& words1, std::vector<std::string>& words2,
    std::vector<std::vector<std::string>>& pairs) {
        if(words1.size() != words2.size()) {
            return false;
        }
        std::unordered_set<std::string> pairSet;
        for(auto& pair : pairs) {
            pairSet.insert(pair[0] + "_" + pair[1]);
            pairSet.insert(pair[1] + "_" + pair[0]);
        }
        const int N = words1.size();
        for(int i = 0; i < N; ++i) {
            if(words1[i] != words2[i]) {
                if (pairSet.count(words1[i] + "_" + words2[i]) == 0 &&
                    pairSet.count(words2[i] + "_" + words1[i]) == 0) {
                        return false;
                }
            }
        }
        return true;
    }
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
    A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have 
    "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When 
    we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and 
    "com" implicitly.
    Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), 
    followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".
    We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, 
    (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.

    Example 1:
    Input: 
    ["9001 discuss.leetcode.com"]
    Output: 
    ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
    Explanation: 
    We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and 
    "com" will also be visited. So they will all be visited 9001 times.

    Input: 
    ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
    Output: 
    ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
    Explanation: 
    We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. 
    For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.

    Notes:
    The length of cpdomains will not exceed 100. 
    The length of each domain name will not exceed 100.
    Each address will have either 1 or 2 "." characters.
    The input count in any count-paired domain will not exceed 10000.
    The answer output can be returned in any order.
*/
class _0811_SubdomainVisitCount {
public:
    std::vector<std::string> subdomainVisits(std::vector<std::string>& cpdomains);
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
! 这道题是一道edge driven 的题目
*/
class _0816_AmbiguousCoordinates {
public:
    std::vector<std::string> ambiguousCoordinates(std::string S);
};


/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

 

Example:

Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
 

Note:

1 <= paragraph.length <= 1000.
0 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.
*/
class _0819_MostCommonWord {
public:
    std::string  mostCommonWord(std::string paragraph, std::vector<std::string>& banned) {
        std::string tmp;
        std::unordered_set<std::string> bannedSet(begin(banned), end(banned));
        std::unordered_map<std::string, int> freq;
        paragraph += ' ';
        for(int i = 0; i < paragraph.size(); ++i) {
            if(paragraph[i] >= 'a' && paragraph[i] <= 'z') {
                tmp += paragraph[i];
            } else if(paragraph[i] >= 'A' && paragraph[i] <= 'Z') {
                tmp += (paragraph[i] - 'A') + 'a';
            } else {
                if(!tmp.empty()) {
                    if(bannedSet.count(tmp)) {
                        freq[tmp] = INT_MIN;
                    } else {
                        ++freq[tmp];
                    }
                    tmp = "";
                }
            }
        }
        
        auto comp = [](std::pair<std::string, int> a, std::pair<std::string, int> b) {
            return a.second < b.second;
        };
        std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(comp)> pq{comp};
        for(auto& f : freq) {
            pq.push(f);
        }
        return pq.top().first;
    }
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
Given a string s of '(' , ')' and lowercase English characters. 
Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) 
so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:
It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Input: s = "a)b(c)d"
Output: "ab(c)d"

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

Input: s = "(a(b(c)d)"
Output: "a(b(c)d)"

Constraints:
1 <= s.length <= 10^5
s[i] is one of  '(' , ')' and lowercase English letters.
!非常重要的一道题目
*/
class _1249_MinimumRemoveToMakeValidParentheses {
public:
    std::string minRemoveToMakeValid(std::string s) {
        std::stack<int> leftP;
        std::unordered_set<int> toBeRemoved; // 用两个变量避免出现 先有)后有(, 可最后都没被销毁的情况.
        for(int i = 0; i < s.size(); ++i) { 
            if(s[i] == '(') {
                leftP.push(i);
            } else if (s[i] == ')') {
                if(leftP.empty()) {
                    toBeRemoved.insert(i); // 在出现"("之前出现")",这个符号一定不合法.
                } else {
                    leftP.pop();
                }
            }
        }
        while(!leftP.empty()) {
            toBeRemoved.insert(leftP.top());
            leftP.pop();
        }
        std::string res;
        for(int i = 0; i < s.size(); ++i) {
            if(toBeRemoved.find(i) == toBeRemoved.end()) {
                res += s[i];
            }
        }
        return res;
    }
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
            if(i < s.size() - 2 && s[i+2] == '#') { // 向后看两个位置，如果看到一个'#', 就说明当前这个数字开头为一个j-z的字母
                res += 'j' + (s[i] - '1') * 10 + (s[i+1] - '0');
                i += 2;
                continue;
            } else {
                res += 'a' + (s[i] - '1');//否则是一个从a-i的字母
            }
        }
        return res;
    }
};


/*
Given an integer n. No-Zero integer is a positive integer 
which doesn't contain any 0 in its decimal representation.
Return a list of two integers [A, B] where:

A and B are No-Zero integers.
A + B = n
It's guarateed that there is at least one valid solution. 
If there are many valid solutions you can return any of them.

Input: n = 2            Output: [1,1]
Explanation: A = 1, B = 1. A + B = n and both A and B don't 
contain any 0 in their decimal representation.

Input: n = 11           Output: [2,9]
Input: n = 10000        Output: [1,9999]
Input: n = 69           Output: [1,68]
Input: n = 1010         Output: [11,999]

Constraints:

2 <= n <= 10^4
! 这道题就是硬试出来
*/
class _1317_ConvertIntegerToTheSumOfTwoNonZeroIntegers {
public:
    std::vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n - a;
        while(true) {
            b = n - a;
            auto sa = std::to_string(a);
            auto sb = std::to_string(b);
            if((sa.find("0") == std::string::npos) && (sb.find("0") == std::string::npos)) {
                return {a,b};
            }
            ++a;
        }
        return {};
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
    Given a string s, the power of the string is the maximum length of a 
    non-empty substring that contains only one unique character.
    Return the power of the string.
    
    Input: s = "leetcode"
    Output: 2
    Explanation: The substring "ee" is of length 2 with the character 'e' only.
    
    Input: s = "abbcccddddeeeeedcba"
    Output: 5
    Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
    
    Input: s = "triplepillooooow"
    Output: 5
    
    Input: s = "hooraaaaaaaaaaay"
    Output: 11
    
    Input: s = "tourist"
    Output: 1
    
    Constraints:  1 <= s.length <= 500
    s contains only lowercase English letters.
    */
    class _1446_ConsecutiveCharacters {
    public:
        int maxPower(std::string s) {
            if(s.empty()) {return 0;}
            char c = s[0];
            int count = 0;
            int maxCount = INT_MIN;
            for(int i = 0; i < s.size(); ++i) {
                if(c == s[i]) {
                    ++count;
                } else {
                    maxCount = std::max(count, maxCount);
                    count = 1;
                    c = s[i];
                }
            }
            maxCount = std::max(count, maxCount);
            return maxCount;
        }
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