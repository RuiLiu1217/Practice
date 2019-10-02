#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"

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



class _0063_UniquePathsII{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);
};

/*
64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom 
right which minimizes the sum of all numbers along its path.
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

// Validate a binary tree is BST or not
class _0098_ValidateBinarySearchTree
{
public:
    bool isValidBST(TreeNode<int> *root);
};

/*
        Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
    For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :

          1
         / \
        2   2
       / \ / \
      3  4 4  3

    But the following[1, 2, 2, null, 3, null, 3] is not:
           1
          / \
         2   2
          \   \
           3   3
    Note:
    Bonus points if you could solve it both recursively and iteratively.

    Solution:  utilize the preorder framework
    */
class _0101_SymmetricTree
{
public:
    bool isSymmetric(TreeNode<int> *root);

private:
    bool preOrderIter(TreeNode<int> *root);
};

/* Binary Tree Level Order Traversal II
    Given a binary tree, return the bottom - up level order traversal of 
    its nodes' values. (ie, from left to right, level by level from leaf to root).
    
    For example :
    Given binary tree[3, 9, 20, null, null, 15, 7],
       3
      / \
     9  20
    / \
  15   7
    return its bottom - up level order traversal as :
    [
        [15, 7],
        [9, 20],
        [3]
    ]
    */
class _0107_BinaryTreeLevelOrderTraversalII
{
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode<int> *root);
};

/* Convert Sorted Array to Binary Search Tree
    Given an array where elements are sorted in ascending order, 
    convert it to a height balanced BST.
    
    For this problem, a height-balanced binary tree is defined as a binary tree in
    which the depth of the two subtrees of every node never differ by more than 1.
    
    Example:
    Given the sorted array: [-10,-3,0,5,9],
    One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
                 0
                / \
              -3   9
              /   /
            -10  5
    */
class _0108_ConvertSortedArrayToBinarySearchTree
{
public:
    TreeNode<int> *sortedArrayToBST(std::vector<int> &nums);

private:
    TreeNode<int> *bst(std::vector<int> &nums, int start, int end);
};

/*
    You are given a perfect binary tree where all leaves are on the same level, 
    and every parent has two children. The binary tree has the following definition:

    Populate each next pointer to point to its next right node. If there is no next 
    right node, the next pointer should be set to NULL.
    Initially, all next pointers are set to NULL.
    */
class _0116_PopulatingNextRightPointerInEachNode
{
public:
    class Node
    {
    public:
        int val;
        Node *left;
        Node *right;
        Node *next;
    };

    void connect(Node *root);
};

// Sort a linked list in O(NlogN) time using constant space complexity.
class _0148_SortList
{
public:
    ListNode<int> *sortList(ListNode<int> *head);

private:
    ListNode<int> *merge(ListNode<int> *head1, ListNode<int> *head2);
    void splitList(ListNode<int> *&head, ListNode<int> *&left, ListNode<int> *&right);
};

/*
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
        push(x) -- Push element x onto stack.
        pop() -- Removes the element on top of the stack.
        top() -- Get the top element.
        getMin() -- Retrieve the minimum element in the stack.
    Example:
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        minStack.getMin();   --> Returns -3.
        minStack.pop();
        minStack.top();      --> Returns 0.
        minStack.getMin();   --> Returns -2.
    */
class _0155_MinStack
{
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    /** initialize your data structure here. */
    _0155_MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();
};

class _0190_ReverseBits
{
    /*
            Reverse bits of a given 32 bits unsigned integer.
            Example 1:
            Input: 00000010100101000001111010011100
            Output : 00111001011110000010100101000000
            Explanation : The input binary string 00000010100101000001111010011100 
            represents the unsigned integer 43261596, so return 964176192 which 
            its binary representation is 00111001011110000010100101000000.
            Example 2 :
            Input : 11111111111111111111111111111101
            Output : 10111111111111111111111111111111
            Explanation : The input binary string 11111111111111111111111111111101 
            represents the unsigned integer 4294967293, so return 3221225471 which 
            its binary representation is 10101111110010110010011101101001.

            Note :
            Note that in some languages such as Java, there is no unsigned integer 
            type. In this case, both input and output will be given as signed integer 
            type and should not affect your implementation, as the internal binary 
            representation of the integer is the same whether it is signed or unsigned.
            In Java, the compiler represents the signed integers using 2's complement 
            notation. Therefore, in Example 2 above the input represents the signed 
            integer -3 and the output represents the signed integer -1073741825.
        */
public:
    uint32_t reverseBits(uint32_t n);
};

class _0235_LowestCommonAncestor
{
    /*
            Given a binary search tree (BST), find the lowest common 
            ancestor (LCA) of two given nodes in the BST.
            
            According to the definition of LCA on Wikipedia: The lowest 
            common ancestor is defined between two nodes p and q as the 
            lowest node in T that has both p and q as descendants (where 
            we allow a node to be a descendant of itself).
            
            Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
                _______6______
               /              \
            ___2__          ___8__
           /      \        /      \
           0       4       7       9
         /  \
        3   5

        Example 1:
            Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
            Output: 6
            Explanation: The LCA of nodes 2 and 8 is 6.
        Example 2:
            Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
            Output: 2
            Explanation: The LCA of nodes 2 and 4 is 2, since a node 
            can be a descendant of itself according to the LCA definition.
        Note:
            All of the nodes' values will be unique. p and q are different 
            and both values will exist in the BST.
        Challenge: 
            Think about the case that the tree is not a binary search tree?
        */
public:
    TreeNode<int> *lowestCommonAncestorRecursive(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q);
    TreeNode<int> *lowestCommonAncestorIterative(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q);
};

/*
Write an efficient algorithm that searches for a value 
in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

    Consider the following matrix:
    [
        [1,   4,  7, 11, 15],
        [2,   5,  8, 12, 19],
        [3,   6,  9, 16, 22],
        [10, 13, 14, 17, 24],
        [18, 21, 23, 26, 30]
    ]
    Given target = 5, return true.
    Given target = 20, return false.
*/
class _0240_SearchA2DMatrix_II
{
public:
    bool searchMatrix(const std::vector<std::vector<int>> &matrix, int target);
};

class _0260_SingleNumberII
{
    /*
        Given an array of numbers nums, in which exactly two elements 
        appear only once and all the other elements appear exactly twice.
        Find the two elements that appear only once.
        
        Example:
            Input:  [1,2,1,3,2,5]
            Output: [3,5]
        Note:
        The order of the result is not important. So in the above example, 
        [5, 3] is also correct. Your algorithm should run in linear runtime 
        complexity. Could you implement it using only constant space 
        complexity?
        
        Solution
            1. assume that A and B are the two elements which we want to find;
            2. use XOR for all elements,the result is : r = A^B,we just need 
            to distinguish A from B next step;
            3. if we can find a bit '1' in r,then the bit in corresponding 
                position in A and B must be different.We can use 
                {last = r & (~(r-1))} to get the last bit 1 int r;
            4. we use last to divide all numbers into two groups,then A and B 
                must fall into the two distrinct groups. XOR elements in eash 
                group,get the A and B.
    */
public:
    std::vector<int> singleNumber(const std::vector<int> &nums);
};

/*
        Given a pattern and a string str, find if str follows the same pattern.
        Here follow means a full match, such that there is a bijection between a 
        letter in pattern and a non - empty word in str.
        
        Example 1:
            Input: pattern = "abba", str = "dog cat cat dog"
            Output : true
        Example 2 :
            Input : pattern = "abba", str = "dog cat cat fish"
            Output : false
        Example 3 :
            Input : pattern = "aaaa", str = "dog cat cat dog"
            Output : false
        Example 4 :
            Input : pattern = "abba", str = "dog dog dog dog"
            Output : false
        Notes :
            You may assume pattern contains only lowercase letters, and str 
            contains lowercase letters separated by a single space.
    */
class _0290_WordPattern
{
public:
    bool wordPattern(std::string pattern, std::string str);
};

/*
    Given a nested list of integers, implement an iterator to flatten it.
    Each element is either an integer, or a list -- whose elements may 
    also be integers or other lists.

    Example 1:
    Input: [[1,1],2,[1,1]]
    Output: [1,1,2,1,1]
    Explanation: By calling next repeatedly until hasNext returns false, 
    the order of elements returned by next should be: [1,1,2,1,1].

    Example 2:
    Input: [1,[4,[6]]]
    Output: [1,4,6]
    Explanation: By calling next repeatedly until hasNext returns false, 
    the order of elements returned by next should be: [1,4,6].
*/

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const;
};
// TODO: COPY FROM A SOLUTION
class _0341_FlattenNestedListIterator
{
private:
    std::vector<NestedInteger> nl;
    _0341_FlattenNestedListIterator *itr = nullptr;
    int index = -1;

public:
    _0341_FlattenNestedListIterator(std::vector<NestedInteger> &nestedList);

    int next();
    bool hasNext();
    bool hasContent(std::vector<NestedInteger> V);
    void increaseIndex();
};

/*
    Given an integer (signed 32 bits), write a function 
    to check whether it is a power of 4.
    
    Example 1:
        Input: 16
        Output: true
    Example 2:
        Input: 5
        Output: false
    Follow up: Could you solve it without loops/recursion?
    */
class _0342_PowerOfFour
{
public:
    bool isPowerOfFour(int num);
};

/*
        Given a non-negative integer n, count all numbers with unique 
        digits, x, where 0 ≤ x < pow(10, n).
        
        Example:
        Input: 2
        Output: 91 
        Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
                     excluding 11,22,33,44,55,66,77,88,99
    */
class _0357_CountNumbersWithUniqueDigits
{
public:
    int countNumbersWithUniqueDigits(int n);

private:
    // For n-digits, it is a simple combination problem
    // The first digit has 9 choices.
    // From the second digits, 9 , 8, 7 ... selections until 1
    int countExactDigit(int n);
};

/*
Calculate the sum of two integers a and b, but you 
are not allowed to use the operator + and -.

Example 1:
    Input: a = 1, b = 2
    Output: 3
Example 2:
    Input: a = -2, b = 3
    Output: 1
*/
class _0371_SumOfTwoIntegers
{
public:
    int getSum(int a, int b);
};

/*
    Given a n x n matrix where each of the rows and columns 
    are sorted in ascending order, find the kth smallest element 
    in the matrix.
    
    Note that it is the kth smallest element in the sorted order, 
    not the kth distinct element.
    
    Example:
    matrix = [
            [ 1,  5,  9],
            [10, 11, 13],
            [12, 13, 15]
    ], k = 8, 
    
    return 13.
*/
class _0378_KthSmallestElementInASortedMatrix
{
public:
    int kthSmallest(std::vector<std::vector<int>> &matrix, int k);

private:
    int search_less_equal(std::vector<std::vector<int>> &matrix, int target);
};

/*
A binary watch has 4 LEDs on the top which represent
the hours (0-11), and the 6 LEDs on the bottom represent
the minutes (0-59).

Each LED represents a zero or one, with the least significant
bit on the right.

For example, the above binary watch reads "3:25".
Given a non-negative integer n which represents the number of
LEDs that are currently on, return all possible times the watch
could represent.

Example:
    Input: n = 1
    Return: ["1:00", "2:00", "4:00", "8:00", "0:01", 
            "0:02", "0:04", "0:08", "0:16", "0:32"]

Note:
    The order of output does not matter.
    The hour must not contain a leading zero, for example "01:00"
    is not valid, it should be "1:00". The minute must be consist 
    of two digits and may contain a leading zero, for example 
    "10:2" is not valid, it should be "10:02".

Solution: 
    Thinking about it in the forward way is difficult, it is better 
    to think about it in an inverse way:
    There are total 12 * 60 combinations, why not enum them one by one 
    and pick up all satisfied items:
*/
class _0401_BinaryWatch
{
public:
    std::vector<std::string> readBinaryWatch(int num);
};

class _0404_SumOfLeftLeaves
{
public:
    int sumOfLeftLeaves(TreeNode<int> *root);
};

// We want to use quad trees to store an N x N boolean grid. Each cell in the
// grid can only be true or false. The root node represents the whole grid. For
// each node, it will be subdivided into four children nodes until the values in
// the region it represents are all the same.
// Each node has another two boolean attributes : isLeaf and val. isLeaf is true
// if and only if the node is a leaf node. The valattribute for a leaf node contains
// the value of the region it represents.
// Your task is to use a quad tree to represent a given grid.

// 这是一道比较简单的题目，主要注意点就是先判断一个矩阵中的值是否一致，在看分隔中是否一致
class _0427_ConstructQuadTree
{
public:
    QuadTreeNode *construct(std::vector<std::vector<int>> &grid);
    QuadTreeNode *construct(std::vector<std::vector<int>> &grid,
                            int rowStart, int rowEnd, int colStart, int colEnd);

private:
    bool areConsistent(std::vector<std::vector<int>> &grid);
    bool areConsistent(std::vector<std::vector<int>> &grid,
                       int rowStart, int rowEnd, int colStart, int colEnd);

    std::vector<std::vector<std::vector<int>>> divideGrid(std::vector<std::vector<int>> &grid);
};

/*
Given an n-ary tree, return the level order traversal 
of its nodes' values. (ie, from left to right, level by level).

For example, given a 3-ary tree:
    We should return its level order traversal:
    [
        [1],
        [3,2,4],
        [5,6]
    ]
Note:
    The depth of the tree is at most 1000.
    The total number of nodes is at most 5000.
*/
class _0429_NaryTreelevelOrderTraversal
{
public:
    std::vector<std::vector<int>> levelOrder(NaryTreeNode<int> *root);
};

/*
Given scores of N athletes, find their relative 
ranks and the people with the top three highest scores, 
who will be awarded medals: "Gold Medal", "Silver Medal" 
and "Bronze Medal".

Example 1:
    Input: [5, 4, 3, 2, 1]
    Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
    Explanation: The first three athletes got the top three 
    highest scores, so they got "Gold Medal", "Silver Medal" and 
    "Bronze Medal".
    For the left two athletes, you just need to output their relative 
    ranks according to their scores.
Note:
    N is a positive integer and won't exceed 10,000.
    All the scores of athletes are guaranteed to be unique.
*/
class _0506_RelativeRanks
{
public:
    std::vector<std::string> findRelativeRanks(std::vector<int> &nums);
};

/*
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number N on the chalkboard.  On each player's turn, 
that player makes a move consisting of:
Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.

Return True if and only if Alice wins the game, assuming both players play optimally.
Example 1:
Input: 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.

Example 2:
Input: 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.

Note:
    1 <= N <= 1000
*/
class _1025_DivisorGame
{
public:
    bool divisorGame(int N);
};

} // namespace LeetCode