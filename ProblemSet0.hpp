#ifndef PROBLEM_SET0_HPP
#define PROBLEM_SET0_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <functional>
#include "Tree.hpp"
#include "LinkList.hpp"

// Problem 1 - 100

namespace LeetCode
{
/*  Tag: array, Hash
    Given an array of integers, return indices of the two 
    numbers such that they add up to a specific target.
    You may assume that each input would have exactly one 
    solution, and you may not use the same element twice.
    Example:
        Given nums = [2, 7, 11, 15], target = 9,
        Because nums[0] + nums[1] = 2 + 7 = 9,
    Return [0, 1].
    */
class _0001_TwoSum {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target);
};

/* Tag: single link list
    You are given two non-empty linked lists representing 
    two non-negative integers. The digits are stored in 
    reverse order and each of their nodes contain a single digit. 
    Add the two numbers and return it as a linked list.
    You may assume the two numbers do not contain any leading zero,
    except the number 0 itself.
    
    Example:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
    */
class _0002_AddTwoNumbers {
public:
    ListNode<int> *addTwoNumbers(ListNode<int> *l1, ListNode<int> *l2);

private:
    ListNode<int> *AddTwoNodes(ListNode<int> *l1, ListNode<int> *l2, int wi);
};

/*  TODO 
Tag : sliding Window, hash, string
Given a string, find the length of the longest substring without repeating characters.

Input: "abcabcbb"     :      Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Input: "bbbbb"        :      Output: 1
Explanation: The answer is "b", with the length of 1.
Input: "pwwkew"       :      Output: 3
Explanation: The answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class _0003_LongestSubstringWithoutRepeatingCharacters {
public:
    int lengthOfLongestSubstring(std::string s);
};

/* TODO :
Tag : Binary Search, array
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
*/
class _0004_MedianOfTwoSortedArrays {
    public:
        double findMedianOfSortedArrays(
            std::vector<int>& nums1,
            std::vector<int>& nums2);
};


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
private:
    int expandAroundCenter(std::string &s, int i, int j);
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
Tag: stack, numeric
Given a 32-bit signed integer, reverse digits of an integer.

Input: 123       :       Output: 321
Input: -123      :       Output: -321
Input: 120       :       Output: 21
*/
class _0007_ReverseInteger {
public:
    int reverse(int x);
};


/* TODO, Like: 1273, Dislike: 7740
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


/* Tag: string, palindrome
Determine whether an integer is a palindrome. An integer is a 
palindrome when it reads the same backward as forward.

Input: 121             Output: true
Input: -121            Output: false
Explanation: From left to right, it reads -121. From right to left, 
it becomes 121-. Therefore it is not a palindrome.

Input: 10              Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/
class _0009_PalindromeNumber {
public:
    bool isPalindrome(int x);
};

/*
Tag: dynamic programming, string matching
TODO: Copy from the answer
Given an input string (s) and a pattern (p), implement 
regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not 
partial).

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, 
and characters like . or *.

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/
class _0010_RegularExpressionMatching {
public:
    bool isMatch(std::string s, std::string p);
};

/* TODO
Tag: greedy algorithm
Given n non-negative integers a1, a2, ..., an , where each represents a point 
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints 
of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this 
case, the max area of water (blue section) the container can contain is 49. 

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
class _0011_ContainerWithMostWater {
public:
    int maxArea(std::vector<int>& height);
};

/* TODO
Tag: greedy algorithm, hash
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together.
Twelve is written as, XII, which is simply X + II. The number twenty seven is 
written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written 
as IV. Because the one is before the five we subtract it making four. The same 
principle applies to the number nine, which is written as IX. There are six 
instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Input: 3
Output: "III"

Input: 4
Output: "IV"

Input: 9
Output: "IX"

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
class _0012_IntegerToRoman {
public:
    std::string intToRoman(int num);
};

/*
Tag: numeric, string
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    For example, two is written as II in Roman numeral, just two one's added together. Twelve 
    is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, 
    which is XX + V + II.
    Roman numerals are usually written largest to smallest from left to right. However, the 
    numeral for four is not IIII. Instead, the number four is written as IV. Because the one 
    is before the five we subtract it making four. The same principle applies to the number 
    nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range 
    from 1 to 3999.

    Example:
    Input: "III"     :      Output: 3
    Input: "IV"      :      Output: 4
    Input: "IX"      :      Output: 9
    Input: "LVIII"   :      Output: 58     (Explanation: L = 50, V= 5, III = 3)
    Input: "MCMXCIV" :      Output: 1994   (Explanation: M = 1000, CM = 900, XC = 90 and IV = 4)
*/
class _0013_RomanToInteger {
public:
    int romainToInt(std::string &s);
private:
    int charToInt(char c);
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
Classical Problem
Tag: binary search, hash, 
Given an array nums of n integers, are there elements a, b, c in nums such 
that a + b + c = 0? Find all unique triplets in the array which gives the 
sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
class _0015_3Sum {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums);
};


/* Todo
Tag: Binary search, hash
Given an array nums of n integers and an integer target, find three 
integers in nums such that the sum is closest to target. Return the 
sum of the three integers. You may assume that each input would have 
exactly one solution.
Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class _0016_3SumCloset {
    public:
        int threeSumCloset(std::vector<int>& nums, int target);
};
 
/*
Tag: recursive
Given a string containing digits from 2-9 inclusive, return all possible 
letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is 
given below. Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could 
be in any order you want.
*/
class _0017_LetterCombinationsOfAPhoneNumber {
public:
    std::vector<std::string> letterCombinations(std::string &digits);
private:
    void letterCombination(const std::string &digits, int i, int N, std::string tmp, std::vector<std::string> &res);
};


/* Todo
Tag: Binary search, hash
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
The solution set must not contain duplicate quadruplets.
Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
class _0018_4Sum {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);
};

/* 
Tag: single link list
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note: Given n will always be valid.
Follow up: Could you do this in one pass?
*/
class _0019_RemoveNthNodeFromEndToList {
public:
    ListNode<int> *removeNthFromEnd(ListNode<int> *head, int n);
};

/*
Tag: parenthesis, stack
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Input: "()"         :     Output: true
Input: "()[]{}"     :     Output: true
Input: "(]"         :     Output: false
Input: "([)]"       :     Output: false
Input: "{[]}"       :     Output: true
*/
class _0020_ValidParentheses {
public:
    bool isValid(std::string &s);
};

/*
Tag: single link list, recursive
Merge two sorted linked lists and return it as a new list. The new list 
should be made by splicing together the nodes of the first two lists.
Example:
Input:  1->2->4, 
        1->3->4
Output: 1->1->2->3->4->4
*/
class _0021_MergeTwoSortedLists {
public:
    ListNode<int> *mergeTwoLists(ListNode<int> *l1, ListNode<int> *l2);
};

/*
Tag: recursive, parenthesis, permutation, combination
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class _0022_GenerateParentheses {
public:
    std::vector<std::string> generateParenthesis(int n);
private:
    void generateParenthesis(int l, int r, std::string v, std::vector<std::string> &res);
};

/*

Google

Tag: single link list
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
class _0023_MergeKeSortedLists {
private:
    ListNode<int>* p;
    ListNode<int>* fh;
public:
    ListNode<int> *mergeKLists(std::vector<ListNode<int> *> &lists);
    bool finishSorting(std::vector<bool> notChoose);
};

/*
Tag: single link list, recursive
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
*/
class _0024_SwapNodesInPairs {
public:
    ListNode<int> *swapPairs(ListNode<int> *head);
};

/*
Tag: single link list, recursive
Given a linked list, reverse the nodes of a linked list k at a time and return 
its modified list.
k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should 
remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
Note:
Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/
class _0025_ReverseNodeInKGroup {
public:
    ListNode<int>* reverseGroup(ListNode<int>* head, int k);
private:
    ListNode<int>* reverse(ListNode<int>* head);
};

/*
Tag: array, slow-fast pointer
Given a sorted array nums, remove the duplicates in-place such that each element 
appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the 
input array in-place with O(1) extra memory.

Example 1:
Given nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums 
being 1 and 2 respectively. It doesn't matter what you leave beyond the returned 
length.

Example 2:
Given nums = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of nums 
being modified to 0, 1, 2, 3, and 4 respectively.
It doesn't matter what values are set beyond the returned length.
Clarification:
Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to 
the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/
class _0026_RemoveDuplicatesFromSortedArray {
public:
    int removeDuplicates(std::vector<int> &nums);
};

/*
Tag: array, slow-fast pointers
Given an array nums and a value val, remove all instances of that value in-place 
and return the new length. Do not allocate extra space for another array, you must 
do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond 
the new length.

Example 1:
Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,1,2,2,3,0,4,2], val = 2,
Your function should return length = 5, with the first five elements of nums 
containing 0, 1, 3, 0, and 4. Note that the order of those five elements can be 
arbitrary. It doesn't matter what values are set beyond the returned length.

Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means modification 
to the input array will be known to the caller as well.

Internally you can think of this:
// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);
// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/
class _0027_RemoveElement {
public:
    int removeElement(std::vector<int> &nums, int val);
};

/*
Tag: string match, KMP (it is actually a hard question, 
but you can use brute force, which makes it easy)

Implement strStr().
Return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string? This is a 
great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is 
an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
class _0028_ImplementStrStr {
public:
    int strStr(std::string &haystack, std::string &needle);
};

/*
TODO
Tag: Binary search, math
Given two integers dividend and divisor, divide two integers without 
using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.

Input: dividend = 10, divisor = 3
Output: 3

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store 
integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. 
For the purpose of this problem, assume that your function returns 
2^31 − 1 when the division result overflows.
*/
class _0029_DivideTwoIntegers {
public:
    int divide(int dividend, int divisor);
};


/* 
You are given a string, s, and a list of words, words, that are all of 
the same length. Find all starting indices of substring(s) in s that is 
a concatenation of each word in words exactly once and without any 
intervening characters.

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" 
respectively. The output order does not matter, returning [9,0] is fine too.

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []
*/
class _0030_SubstringWithConcatenationOfAllWords {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words);
};

/*
TODO: Permutation, array boundary
Implement next permutation, which rearranges numbers into the lexicographically 
next greater permutation of numbers. If such arrangement is not possible, it 
must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its 
corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
class _0031_NextPermutation {
public:
    void nextPermutation(std::vector<int> &nums);
private:
    void reverse(std::vector<int> &nums, int start, int end);
};

/*
Given a string containing just the characters '(' and ')', find the length of the 
longest valid (well-formed) parentheses substring.

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
class _0032_LongestValidParentheses {
public:
    int longestValidParentheses(std::string s);
};


/*
Tag: Binary search
TODO

discuss two cases that num[mid] > num[start] and 
num[mid] < num[start]
Note: it is hard for the edge cases:
1. empty vector
2. one value, find the exist
3. one value, find the non-exist
4. two value, find the exist
4. two value, find the non-exist
5. 3 values, find the exist (mid, mid at left, mid at right)
6. 3 values, find the non exist (mid, mid at left, mid at right)
7. 4 values...
...

Suppose an array sorted in ascending order is rotated at some pivot 
unknown to you beforehand. 
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return 
its index, otherwise return -1. You may assume no duplicate exists 
in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
class _0033_SearchInRotatedSortedArray {
public:
    int search(std::vector<int> &nums, int target);
};

/*
Facebook

!!!Copy from the solution, need to be reviewed again!!!

Tag: binary search
    TODO: Modification of the binary search
Given an array of integers nums sorted in ascending order, find the 
starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
class _0034_FindFirstAndLastPositionOfElementInSortedArray {
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target);
};


/* 
Tag: Binary Search

Given a sorted array and a target value, return the index if the target 
is found. If not, return the index where it would be if it were inserted 
in order.
You may assume no duplicates in the array.

Example 
Input: [1,3,5,6], 5         :   Output: 2
Input: [1,3,5,6], 2         :   Output: 1
Input: [1,3,5,6], 7         :   Output: 4
Input: [1,3,5,6], 0         :   Output: 0
*/
class _0035_SearchInsertPosition {
public:
    int searchInsert(std::vector<int>& nums, int target);
};


/*
Tag: simulate according to the condition
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be 
validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/
class _0036_ValidSudoku{
public:
    std::function<bool(char, std::vector<int>&)> containDup = [](char tmp,  std::vector<int>& ext){
        if(tmp >= '1' && tmp <= '9') {
            if(ext[tmp-'1'] == 0) {
                ext[tmp - '1'] = 1;
            } else {
                return true;
            }
        }
        return false;
    };
    bool isValidSudoku(std::vector<std::vector<char>>& board);

private:
    bool existDuplicatePerSquare(std::vector<std::vector<char>>& board, int i, int j);
    bool existDuplicatePerRow(std::vector<std::vector<char>>& board, int i);
    bool existDuplicatePerColumn(std::vector<std::vector<char>>& board, int j);
};

/*
TODO: Review it again
Tag: backtracking, recursive.
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.
*/
class _0037_SudokuSolver {
public:
    // Backtracing problem, but the issue is how to make the backtracing fast !!!!
    void solveSudoku(std::vector<std::vector<char>>& board);
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
private:
    std::string countOnce(std::string &s);
};

/*  
Tag: backtracking
Given a set of candidate numbers (candidates without duplicates) 
and a target number (target), find all unique combinations in 
candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.
Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.
Example 1:
    Input: candidates = [2,3,6,7], target = 7,
A solution set is:
    [  [7],  [2,2,3] ]
Example 2:
    Input: candidates = [2,3,5], target = 8, 
A solution set is:
    [  [2,2,2,2],  [2,3,3],  [3,5] ]
*/
class _0039_CombinationSum
{
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target);

private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<int> &tmp, std::vector<std::vector<int>> &res);
};

/*
Tag: backtracking
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
[1,2,2],
[5]
]
*/
class _0040_CombinationSumII {
private:
    std::vector<std::vector<int>> res;
    std::vector<int> temp;
public:
    void choose(std::vector<int>& candidates, int target, int begin);
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);
};

/*
TODO
Tag: array, I don't know how to categorize.
Given an unsorted integer array, find the smallest missing positive integer.
Example 1:
    Input: [1,2,0]         :         Output: 3
    Input: [3,4,-1,1]      :         Output: 2
    Input: [7,8,9,11,12]   :         Output: 1

Your algorithm should run in O(n) time and uses constant extra space.
*/
class _0041_FirstMissingPositive{
public:
    int firstMissingPositive(std::vector<int>& nums);
};

/*
Tag: dynamic programming, two pointers
Google
TODO: Review the left,right maximum height and its application

Given n non-negative integers representing an elevation map where the width 
of each bar is 1, compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped. Thanks 
Marcos for contributing this image!

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
class _0042_TrappingRainWater {
public:
    int trap(std::vector<int>& height);
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

/*
TODO
Tag: BFS
Note: be careful of boundary conditions

Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

Input: [2,3,1,1,4]
Output: 2
The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 
3 steps to the last index.

You can assume that you can always reach the last index.
*/
class _0045_JumpGameII {
public:
    int jump(std::vector<int>& nums);
};

/*
Given a collection of [distinct] integers, return all 
possible permutations
Example:
Input: [1,2,3]
Output:[[1,2,3], [1,3,2], [2,1,3], 
        [2,3,1], [3,1,2], [3,2,1]]
*/
class _0046_Permutations {
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums);
private:
    void permuteRecursive(std::vector<int> &nums, int begin, std::vector<std::vector<int>> &result);
};

/*
Given a collection of numbers that might contain 
duplicates, return all possible unique permutations.

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
class _0047_PermutationsII {
public:
    std::vector<std::vector<int>> permuteUnique(
        std::vector<int>& nums);
    void genPermute(std::vector<int> nums, 
        int start, int end, 
        std::vector<std::vector<int>>& res);

    void genPermute(std::unordered_map<int, int>& Map, 
        int N, std::vector<int>& tmp,
        std::vector<std::vector<int>>& res);
};

/* 
Tag: matrix operation
You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).
Note: You have to rotate the image in-place, which means you have to modify the input 2D matrix 
directly. DO NOT allocate another 2D matrix and do the rotation.
*/
class _0048_RotateImage {
public:
    void rotate(std::vector<std::vector<int>> &matrix);
};


/*
Tag: hash
Group Anagrams :  Given an array of strings, group anagrams together.

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/
class _0049_GroupAnagrams { 
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);
};

/*
Tag: recursive
Note: integer data overflow if n < 0 --> -n but 
      if n is INT_MIN, then...
Implement pow(x, n), which calculates x raised to the power n (x^n).

Input: 2.00000, 10       :           Output: 1024.00000
Input: 2.10000, 3        :           Output: 9.26100
Input: 2.00000, -2       :           Output: 0.25000

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/
class _0050_PowXN {
public:
    double myPow(double x, int n);
};

/*
Tag: backtracking
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no 
two queens attack each other. Given an integer n, return all distinct solutions to the 
n-queens puzzle. Each solution contains a distinct board configuration of the n-queens' 
placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/
class _0051_NQueens {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n);
    void solve(std::vector<std::string>& tmp, int curN, int n, std::vector<std::vector<std::string>>& res);
    std::vector<int> availableQ(std::vector<std::string> tmp, int curN, int n);
};

/*
Tag: backtracking
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no 
two queens attack each other. Given an integer n, return all distinct solutions to the 
n-queens puzzle. Each solution contains a distinct board configuration of the n-queens' 
placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/
class _0052_NQueensII {
public:
    int totalNQueens(int n);
private:
    void totalNQueens(std::vector<std::vector<int>>& board, int nIdx, const int totalRows, int& totalSolution);
    void updateBoard(std::vector<std::vector<int>>& board, int i, int j);
    void dedateBoard(std::vector<std::vector<int>>& board, int i, int j);
};

/*
Tag: dynamic programming or conqor and merge
TODO: Classical problem

Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Input: [-2,1,-3,4,-1,2,1,-5,4],        :           Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
class _0053_MaximumSubarray {
public:
    int maxSubArray(std::vector<int>& nums);
private:
    int maxSubArrayHelp(std::vector<int>& nums, int start, int end);
    int includeMid(std::vector<int>& nums, int start, int end, int mid);
};

/*
Tag: matrix operations
Note: edge condition
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
class _0054_SpiralMatrix{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix);
};


/*
Todo: The code is hard to think of. But the idea is not hard.
Try to write it again and again.

Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
Example 1:

Input: [2,3,1,1,4]           :          Output: true
Input: [3,2,1,0,4]           :          Output: false
*/
class _0055_JumpGame {
public:
    bool canJump(std::vector<int>& nums);
};

/*
Todo: interval 
Given a collection of intervals, merge all overlapping intervals.

Input: [[1,3],[2,6],[8,10],[15,18]]            :           Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Input: [[1,4],[4,5]]                           :           Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/
class _0056_MergeIntervals {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals);
};

/*
Tag: Intervals
Given a set of non-overlapping intervals, insert a new interval into the 
intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their
start times.

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/
class _0057_InsertInterval {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals,
    std::vector<int>& newInterval);
    bool newIntervalSmaller(const std::vector<int>& a, const std::vector<int>& b);
    bool intersect(const std::vector<int>& a,const std::vector<int>& b);
};


/*
Tag: string
58. Length of Last Word
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
Tag: matrix operation
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class _0059_SpiralMatrixII{
public:
    std::vector<std::vector<int>> generateMatrix(int n);
};


/*
Tag: Permutation, Priority Queue, String
TODO
Note: The same, how to generate next permuation

The set [1,2,3,...,n] contains a total of n! unique 
permutations.
By listing and labeling all of the permutations in 
order, we get the following sequence for n = 3:

"123" "132" "213" "231" "312" "321"
Given n and k, return the kth permutation sequence.

Note:
Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

Input: n = 3, k = 3
Output: "213"

Input: n = 4, k = 9
Output: "2314"
*/
class _0060_PermutationSequence {
public:
    std::string getPermutation(int n, int k);
    std::string getNext(std::string S);
};


/*
Tag: Single Linked List

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/
class _0061_RotateList{
public:
    ListNode<int>* rotateRight(ListNode<int>* head, int k);
};

/*
Tag: Dynamic Programming

62. Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
*/
class _0062_UniquePaths{
private:
    std::vector<std::vector<int>> TABLE;
public:
    int uniquePaths(int m, int n);
    int uniquePaths_impl(int m, int n);
};


/*
Tag: Dynamic Programming

A robot is located at the top-left corner of a m x n 
grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any 
point in time. The robot is trying to reach the 
bottom-right corner of the grid (marked 'Finish' in 
the diagram below).

Now consider if some obstacles are added to the grids. 
How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 
respectively in the grid.

Note: m and n will be at most 100.

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/
class _0063_UniquePathsII{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);
};

/*
Tag: dynamic programming
64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from 
top left to bottom right which minimizes the sum of all numbers along 
its path.
Note: You can only move either down or right at any point in time.

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class _0064_MinimumPathSum {
public:
    int minPathSum(std::vector<std::vector<int>>& grid);
};

/*
Facebook
        !!! Copy from Solution !!!

Tag: String, DFA, NFA
Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You 
should gather all requirements up front before implementing one. 
However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your 
function signature accepts a const char * argument, please click the reload 
button to reset your code definition. */
class _0065_ValidNumber {
public:
    bool isNumber(std::string str);
};


/*
Tag: array operation
Given a non-empty array of digits representing a non-negative integer, 
plus one to the integer. The digits are stored such that the most significant 
digit is at the head of the list, and each element in the array contain 
a single digit.
You may assume the integer does not contain any leading zero, except 
the number 0 itself.

Input: [1,2,3]             :     Output: [1,2,4]
Input: [4,3,2,1]           :     Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/
class _0066_PlusOne {
public:
    std::vector<int> plusOne(std::vector<int>& digits);
};

/*
Facebook

Tag: Array operation
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

Input: a = "11", b = "1"           :        Output: "100"
Input: a = "1010", b = "1011"      :        Output: "10101"
*/
class _0067_AddBinary {
public:
    std::string addBinary(std::string a, std::string b);
};

/*
Given an array of words and a width maxWidth, format the text such that each 
line has exactly maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words 
as you can in each line. Pad extra spaces ' ' when necessary so that each 
line has exactly maxWidthcharacters.

Extra spaces between words should be distributed as evenly as possible. If the 
number of spaces on a line do not divide evenly between words, the empty slots
on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extraspace is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.
Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/
class _0068_TextJustification {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int L);
};

/*
Tag: Binary search.
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer 
part of the result is returned.

Input: 4           :          Output: 2
Input: 8           :          Output: 2

Explanation: The square root of 8 is 2.82842..., and since
the decimal part is truncated, 2 is returned.
*/
class _0069_SqrtX {
public:
    int mySqrt(int x);
};

/*
Tag: dynamic programming, fibnacci
You are climbing a stair case. It takes n steps to reach to the top. Each time you can either climb 1 or 2 
steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Input: 2            :            Output: 2
1. 1 step + 1 step
2. 2 steps

Input: 3            :            Output: 3
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
class _0070_ClimbingStairs {
public:
    int climbStairs(int n);
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
    std::string simplifyPath(std::string path);
};

/*
Tag: Dynamic Programming
Given two words word1 and word2, find the minimum number 
of operations required to convert word1 to word2.
You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
class _0072_EditDistance{
public:
    int minDistance(std::string word1, std::string word2);
};

/*
Tag: Matrix operation, tricks
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class _0073_SetMatrixZeros {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix);
};

/*
Tag: binary search
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
Integers in each row are sorted from left to right. The first integer of 
each row is greater than the last integer of the previous row.

Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/
class _0074_SearchA2DMatrix {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);
};


/*
Tag: array
Given an array with n objects colored red, white or blue, sort them 
in-place so that objects of the same color are adjacent, with the colors 
in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, 
and blue respectively.
Note: You are not suppose to use the library's sort function for this problem.
Example:
Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite 
array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/
class _0075_SortColors {
public:
    void sortColors(std::vector<int>& nums);
};

/*
Tag: Sliding Windows
Google, Facebook
TODO: ending edge cases, which is not easy to debug

Given a string S and a string T, find the minimum window in S which will 
contain all the characters in T in complexity O(n).

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
class _0076_MinimumWindowSubstring {
public:
    std::string minWindow(std::string s, std::string t);
};

/*
Tag: backtracking, combination
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
Example:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class _0077_Combinations {
public:
    std::vector<std::vector<int>> combine(int n, int k);
    void combine(std::vector<int>& nums, std::vector<int>& used, int s, int k, std::vector<int>& tmp, std::vector<std::vector<int>>& res);
};

/*
Tag: backtracking, combination
Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class _0078_Subsets{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums);
    std::vector<std::vector<int>> subsets(std::vector<int>& nums, int beg, int end);
};

/*
Tag: backtracking
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent 
cell, where "adjacent" cells are those horizontally or vertically 
neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
class _0079_WordSearch{
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word);
    void exist(std::vector<std::vector<char>>& board, int i, int j, std::string& word, int start, int end, bool& res);
};


/*
Tag: array
TODO
80. Remove Duplicates from Sorted Array II
Given a sorted array nums, remove the duplicates in-place such that 
duplicates appeared at most twice and return the new length.
Do not allocate extra space for another array, you must do this by
modifying the input array in-place with O(1) extra memory.

Given nums = [1,1,1,2,2,3],
Your function should return length = 5, with the first five elements
of nums being 1, 1, 2, 2 and 3 respectively. It doesn't matter what 
you leave beyond the returned length.

Given nums = [0,0,1,1,1,1,2,3,3],
Your function should return length = 7, with the first seven elements
of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
It doesn't matter what values are set beyond the returned length.

Clarification:
Confused why the returned value is an integer but your answer is an array?
Note that the input array is passed in by reference, which means 
modification to the input array will be known to the caller as well.

Internally you can think of this:
// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);
*/
class _0080_RemoveDuplicatesFromSortedArrayII {
public:
    int removeDuplicates(std::vector<int>& nums);
};

/*
Tag: Binary Search
Suppose an array sorted in ascending order is rotated at some pivot 
unknown to you beforehand. (i.e., [0,0,1,2,2,5,6] might become 
[2,5,6,0,0,1,2]). You are given a target value to search. If found 
in the array return true, otherwise return false.

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:
This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/
class _0081_SearchInRotatedSortedArrayII {
public:
    bool search(std::vector<int>& nums, int target);
};


/*
Tag: Single Linked List operation
82. Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

Input: 1->2->3->3->4->4->5
Output: 1->2->5

Input: 1->1->1->2->3
Output: 2->3
*/
class _0082_RemoveDuplicatesFromSortedListII{
public:
    ListNode<int>* deleteDuplicates(ListNode<int>* head);
};

/*
Tag: Single Linked List Operation
Given a sorted linked list, delete all duplicates such that each element 
appear only once.

Input: 1->1->2
Output: 1->2

Input: 1->1->2->3->3
Output: 1->2->3
*/
class _0083_RemoveDuplicatesFromSortedList{
public:
    ListNode<int>* deleteDuplicates(ListNode<int>* head);
};

/*
Tag: increasing stack
TODO:
Given n non-negative integers representing the histogram's bar height where 
the width of each bar is 1, find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.

Input: [2,1,5,6,2,3]
Output: 10
*/
class _0084_LargestRectangleInHistogram {
public:
    int largestRectangleArea(std::vector<int>& heights);
};

/*
Tag: dynamic programming
TODO
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/
class _0085_MaximalRectangle {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix);
};

/*
Tag: single linked list operation
Given a linked list and a value x, partition it such that all nodes less 
than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of 
the two partitions.

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/
class _0086_PartitionList {
    public:
        ListNode<int>* partition(ListNode<int>* head, int x);
};

/*
Facebook 

Tag: array operation, from back to front
Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/
class _0088_MergeSortedArray {
public: 
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
};


/*
Tag: recursive
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the 
sequence of gray code. A gray code sequence must begin with 0.


Input: 2   Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

Example 2:
Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0. A gray code sequence of n has 
size = 2n, which for n = 0 the size is 20 = 1. Therefore, for n = 0 the gray code sequence is [0].
*/
class _0089_GrayCode{
public:
    std::vector<int> grayCode(int n);
};

/*
Tag: combination
Given a collection of integers that might contain duplicates, nums, return all possible subsets 
(the power set).
Note: The solution set must not contain duplicate subsets.
Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class _0090_SubsetII {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums);
    
    void generateAllSubsets(std::vector<int>& nums, std::vector<int>& subset,
                           int index, std::vector<std::vector<int>>& res);
};

/*
Tag: dyanmic programming
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
class _0091_DecodeWays{
public:
    int numDecodings(std::string s);
};

/*
Tag: single linked list
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 ≤ m ≤ n ≤ length of list.

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/
class _0092_ReverseLinkedListII {
public:
    ListNode<int>* reverseBetween(ListNode<int>* head, int m, int n);
};

/*
Tag: backtracking
93. Restore IP Addresses
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:
Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/
class _0093_RestoreIPAddress{
public:
    std::vector<std::string> restoreIPAddress(std::string s);
private:
    void restoreIpAddress(std::string s, int level, std::string out, std::vector<std::string>& res);
    bool isValid(std::string s);
};

/*
Tag: recursive, hash
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class _0095_UniqueBinarySearchTreeII {
public:
    std::vector<TreeNode<int>*> generateTrees(int n);
    std::vector<TreeNode<int>*> generateTreeHelper(int l, int r);
};

/*
Tag: recursive, hash
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class _0096_UniqueBinarySearchTree {
private:
    std::vector<int> DP;
public:
    int numTrees(int n);
    int numTreesN(int n);
};


/*
Tag: dynamic programming, string
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/
class _0097_InterleavingString {
public:
    bool isInterleav(std::string s1, std::string s2, std::string s3);
};

/*
Facebook


Tag: Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/
class _0098_ValidateBinarySearchTree {
public:
    bool isValidBST(TreeNode<int> *root);
};

/*
Tag: Morris Traversal, Tree

Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2
Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
Follow up:

A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
*/
class _0099_RecoverBinarySearchTree {
public:
    void recoverTree(TreeNode<int>* root);
};

/*
Tag: Tree
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical 
and the nodes have the same value.

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
*/
class _0100_SameTree {
public:
    bool isSameTree(TreeNode<int>* p, TreeNode<int>* q);
};

}

#endif