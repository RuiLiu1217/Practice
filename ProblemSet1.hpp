#ifndef PROBLEM_SET1_HPP
#define PROBLEM_SET1_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"

// Problem 1 - 60

namespace LeetCode
{
/* TOPIC: HASH MAP
    Given an array of integers, return indices of the two 
    numbers such that they add up to a specific target.
    You may assume that each input would have exactly one 
    solution, and you may not use the same element twice.
    Example:
        Given nums = [2, 7, 11, 15], target = 9,
        Because nums[0] + nums[1] = 2 + 7 = 9,
    Return [0, 1].
    */
class _0001_TwoSum
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target);
};

/* TOPIC: LINK LIST
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
class _0002_AddTwoNumbers
{
public:
    ListNode<int> *addTwoNumbers(ListNode<int> *l1, ListNode<int> *l2);

private:
    ListNode<int> *AddTwoNodes(ListNode<int> *l1, ListNode<int> *l2, int wi);
};

/* TOPIC : SLIDING WINDOW
    Given a string, find the length of the longest substring without repeating characters.
    
    Example 1:
    Input: "abcabcbb"
    Output: 3 
    Explanation: The answer is "abc", with the length of 3. 
    
    Example 2:
    Input: "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    
    Example 3:
    Input: "pwwkew"
    Output: 3
    
    Explanation: The answer is "wke", with the length of 3. 
    Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
    */
// TODO: Copy the solution. Need to understand it better
// HashTable + Sliding Window:
// Using a hashtable to remember the last index of every char, And keep tracking the starting
// point of a valid substring
class _0003_LongestSubstringWithoutRepeatingCharacters
{
public:
    int lengthOfLongestSubstring(std::string s);
};

// class _0004_MedianOfTwoSortedArrays {
//     public:
//         double findMedianOfSortedArrays(
//             std::vector<int>& nums1,
//             std::vector<int>& nums2);

// };



/*
Given a string s, find the longest palindromic substring in s. You may assume that 
the maximum length of s is 1000.

Example 1:
Input: "babad"          :         Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"           :         Output: "bb"
*/
class _0005_LongestPalindromicSubstring
{
public:
    std::string longestPalidrome(std::string s);

private:
    int expandAroundCenter(std::string &s, int i, int j);
};

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows 
like this: (you may want to display this pattern in a fixed font for better legibility)

        P   A   H   N
        A P L S I I G
        Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

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
Given a 32-bit signed integer, reverse digits of an integer.
Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21
*/
class _0007_ReverseInteger
{
public:
    int reverse(int x);
};


// Totally COPY FROM A SOLUTION
/*
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
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/
class _0008_StringToInteger {
public:
    int myAtoi(std::string str);
};


/* TOPIC: Palindrome
Determine whether an integer is a palindrome. An integer is a 
palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, 
it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/
class _0009_PalindromeNumber
{
public:
    bool isPalindrome(int x);
};

/* TOPIC: Greedy Algorithm
Given n non-negative integers a1, a2, ..., an , where each represents a point 
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints 
of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis 
forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this 
case, the max area of water (blue section) the container can contain is 49. 

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
class _0011_ContainerWithMostWater {
public:
    int maxArea(std::vector<int>& height);
};


class _0012_IntegerToRoman{
public:
    std::string intToRoman(int num);
}

/*
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
class _0013_RomanToInteger
{
public:
    int romainToInt(std::string &s);

private:
    int charToInt(char c);
};

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""

Explanation: There is no common prefix among the input strings.
*/
class _0014_LongestCommonPrefix
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs);
};

/*
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
TODO: Binary search based algorithm
*/
class _0015_3Sum
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums);
};


/*
Given an array nums of n integers and an integer target, find three 
integers in nums such that the sum is closest to target. Return the 
sum of the three integers. You may assume that each input would have 
exactly one solution.
Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class _0016_3SumCloset{
    public:
        int threeSumCloset(std::vector<int>& nums, int target);
};

/*
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
class _0017_LetterCombinationsOfAPhoneNumber
{
public:
    std::vector<std::string> letterCombinations(std::string &digits);

private:
    void letterCombination(const std::string &digits, int i, int N, std::string tmp, std::vector<std::string> &res);
};

/*
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note: Given n will always be valid.
Follow up: Could you do this in one pass?
*/
class _0019_RemoveNthNodeFromEndToList
{
public:
    ListNode<int> *removeNthFromEnd(ListNode<int> *head, int n);
};

/*
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
class _0020_ValidParentheses
{
public:
    bool isValid(std::string &s);
};

/*
Merge two sorted linked lists and return it as a new list. The new list 
should be made by splicing together the nodes of the first two lists.
Example:
Input:  1->2->4, 
        1->3->4
Output: 1->1->2->3->4->4
*/
class _0021_MergeTwoSortedLists
{
public:
    ListNode<int> *mergeTwoLists(ListNode<int> *l1, ListNode<int> *l2);
};

/*
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
class _0022_GenerateParentheses
{
public:
    std::vector<std::string> generateParenthesis(int n);

private:
    void generateParenthesis(int l, int r, std::string v, std::vector<std::string> &res);
};

/*
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
class _0023_MergeKeSortedLists
{
public:
    ListNode<int> *mergeKLists(std::vector<ListNode<int> *> &lists);
    bool finishSorting(std::vector<bool> notChoose);
};

/*
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
*/
class _0024_SwapNodesInPairs
{
public:
    ListNode<int> *swapPairs(ListNode<int> *head);
};

/*
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
class _0025_ReverseNodeInKGroup{
public:
    ListNode<int>* reverseGroup(ListNode<int>* head, int k);
private:
    ListNode<int>* reverse(ListNode<int>* head);
};

/*
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
class _0026_RemoveDuplicatesFromSortedArray
{
public:
    int removeDuplicates(std::vector<int> &nums);
};

/*
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
class _0027_RemoveElement
{
public:
    int removeElement(std::vector<int> &nums, int val);
};

/*
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
class _0028_ImplementStrStr
{
public:
    int strStr(std::string &haystack, std::string &needle);
};

/*
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
class _0031_NextPermutation
{
public:
    void nextPermutation(std::vector<int> &nums);

private:
    void reverse(std::vector<int> &nums, int start, int end);
};

/*
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
// TODO: Modification of the binary search. Needs remember.
class _0033_SearchInRotatedSortedArray
{
public:
    int search(std::vector<int> &nums, int target);
};

/*
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
class _0034_FindFirstAndLastPositionOfElementInSortedArray
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target);
};


/* TOPIC: Binary Search
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
    bool isValidSudoku(std::vector<std::vector<<char>>& board);

private:
    bool existDuplicatePerSquare(std::vector<std::vector<char>>& board, int i, int j);
    bool existDuplicatePerRow(std::vector<std::vector<char>>& board, int i);
    bool existDuplicatePerColumn(std::vector<std::vector<char>>& board, int j);
};

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.
*/
class _0037_SudokuSolver {
public:
    // void solveSudoku(vector<vector<char>>& board) {
    //     const int M = unfilled(board);
    //     std::vector<int> rowMask(9, 0);
    //     std::vector<int> colMask(9, 0);
    //     std::vector<int> blkMask(9, 0);
    //     calcualteMasks(board, rowMask, colMask, blkMask);
    //     solveSudoku(board, 0, M, rowMask, colMask, blkMask);
    // }
    // void calcualteMasks(std::vector<std::vector<char>>& board, 
    //                     std::vector<int>& rowMask,
    //                    std::vector<int>& colMask,
    //                    std::vector<int>& blkMask) {
    //     const int M = 0x000003FF;
        
    //     for(int i = 0; i < 9; ++i) {
    //         int v = 0;
    //         for(int j = 0; j < 9; ++j) {
    //             if(board[i][j] != '.') {
    //                  v |= 1<<(board[i][j] - '0');
    //             }
    //         }
    //         rowMask[i] = M ^ v;
    //     }
        
    //     for(int j = 0; j < 9; ++j) {
    //         int v = 0;
    //         for(int i = 0; i < 9; ++i) {
    //             if(board[i][j] != '.') {
    //                 v |= 1<<(board[i][j] - '0');
    //             }
    //         }
    //         colMask[j] = M ^ v;
    //     }
        
    //     for(int i = 0; i < 3; ++i) {
    //         for(int j = 0; j < 3; ++j) {
    //             int v = 0;
    //             for(int k1 = 0; k1 < 3; ++k1) {
    //                 for(int k2 = 0; k2 < 3; ++k2) {
    //                     if(board[i * 3 + k1][j * 3 + k2] != '.') {
    //                         v |= 1 << (board[i * 3 + k1][j * 3 + k2] - '0');
    //                     }
    //                 }
    //             }
    //             blkMask[i * 3 + j] = M ^ v;
    //         }
    //     }
    // }
    
    // std::vector<char> getSolutionSpace(std::vector<int>& rowMask, std::vector<int>& colMask, std::vector<int>& blkMask, int i, int j) {
    //     int I = i / 3;
    //     int J = j / 3;
    //     int rm = rowMask[i];
    //     int cm = colMask[j];
    //     int bm = blkMask[I * 3 + J];
    //     int s = (rm & cm & bm);
    //     if(s == 0) {
    //         return {};
    //     } else {
    //         int i = 0;
    //         std::vector<char> res;
    //         while(s) {
    //             if(s & 1) {
    //                 res.push_back('0' + i);
    //             }
    //             s = s >> 1;
    //             ++i;
    //         }
    //         return res;
    //     }
    // }
    
    
    // void solveSudoku(std::vector<std::vector<char>>& board, int k, int M, std::vector<int>& rowMask,
    //                 std::vector<int>& colMask, std::vector<int>& blkMask) {
    //     if(k == M) {
    //         return;
    //     }
    //     const int Ms = 0x000003FF;
    //     for(int i = 0; i < 9; ++i) {
    //         for(int j = 0; j < 9; ++j) {
    //             if(board[i][j] == '.') {
    //                 std::vector<char> solvable = getSolutionSpace(rowMask, colMask, blkMask, i, j);
    //                 if(solvable.size() > 0) {
    //                     for(auto c : solvable) {
    //                         board[i][j] = c;
    //                         rowMask[i] &= ((1 << (c - '0')) ^ Ms);
    //                         colMask[j] &= ((1 << (c - '0')) ^ Ms);
    //                         blkMask[(i / 3) * 3 + j / 3] = blkMask[(i / 3) * 3 + j / 3] & ((1 << (c - '0')) ^ Ms);
    //                         solveSudoku(board, k + 1, M, rowMask, colMask, blkMask);
    //                         board[i][j] = '.';
    //                         rowMask[i] |= (1 << (c - '0'));
    //                         colMask[j] |= (1 << (c - '0'));
    //                         blkMask[(i / 3) * 3 + j / 3] |= (1 << (c - '0'));
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    // int unfilled(std::vector<std::vector<char>>& board) {
    //     int res = 0;
    //     for(int i = 0; i < 9; ++i) {
    //         for(int j = 0; j < 9; ++j) {
    //             if(board[i][j] == '.') {
    //                 ++res;
    //             }
    //         }
    //     }
    //     return res;
    // }
    
    
    
    // std::vector<char> getPotentialValues(std::vector<std::vector<char>>& board, int i, int j) {
    //     std::vector<bool> used(9, false);
    //     for(int k = 0; k < 9; ++k) {
    //         if(board[i][k] != '.') {
    //             used[board[i][k] - '0'] = true;
    //         }
    //     }
        
    //     for(int k = 0; k < 9; ++k) {
    //         if(board[k][j] != '.') {
    //             used[board[k][j] - '0'] = true;
    //         }
    //     }
        
    //     int I = i / 3;
    //     int J = j / 3;
    //     for(int k1 = 0; k1 < 3; ++k1) {
    //         for(int k2 = 0; k2 < 3; ++k2) {
    //             if(board[I + k1][J + k2] != '.') {
    //                 used[board[I+k1][J+k2] - '0'] = true;
    //             }
    //         }
    //     }
        
    //     std::vector<char> res;
    //     for(int i = 0; i < 9; ++i) {
    //         if(used[i] == false) {
    //             res.push_back(static_cast<char>('0' + i));
    //         }
    //     }
    //     return res;
    // }
};


/*
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
class _0038_CountAndSay
{
public:
    std::string countAndSay(int n);

private:
    std::string countOnce(std::string &s);
};

/*  
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
class _0040_CombinationSumII{
    private:
        std::vector<std::vector<int>> res;
        std::vector<int> temp;
    public:
        void choose(std::vector<int>& candidates, int target, int begin);
        std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);
};

/*
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
        Given a collection of [distinct] integers, return all possible permutations
    Example:
        Input: [1,2,3]
        Output: [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
    */
class _0046_Permutations
{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums);

private:
    void permuteRecursive(std::vector<int> &nums, int begin, std::vector<std::vector<int>> &result);
};

/* 
        You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).
        Note: You have to rotate the image in-place, which means you have to modify the input 2D matrix 
        directly. DO NOT allocate another 2D matrix and do the rotation.
    */
class _0048_RotateImage
{
public:
    void rotate(std::vector<std::vector<int>> &matrix);
};

/*
58. Length of Last Word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/
class _0058_LengthOfLastWord{
public:
    int lengthOfLastWord(std::string s);
};


/*
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
}

#endif