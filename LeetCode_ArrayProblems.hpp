#ifndef LEETCODE_ARRAYPROBLEMS_HPP
#define LEETCODE_ARRAYPROBLEMS_HPP
#include <vector>
#include <string>
namespace LC {
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


/* Tag : Binary Search, array
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
    bool isValidSudoku(std::vector<std::vector<char>>& board);
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

/* Tag: matrix operation
Given a positive integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class _0059_SpiralMatrixII {
public:
    std::vector<std::vector<int>> generateMatrix(int n);
};



}
#endif