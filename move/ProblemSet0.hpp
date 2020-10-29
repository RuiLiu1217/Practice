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
Given a collection of numbers that might contain 
duplicates, return all possible unique permutations.

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
!这道题一直没有搞明白到底是用引用还是copy by value, 而且在递归调用完后，是否要swap回原先的结果.
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


}

#endif