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