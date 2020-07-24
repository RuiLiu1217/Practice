#ifndef LEETCODE_ARRAYPROBLEMS_HPP
#define LEETCODE_ARRAYPROBLEMS_HPP
#include <vector>
#include <string>
#include <stack>

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
Facebook
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
Facebook 

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
Tag: array operation
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class _0118_PascalTriangle {
public:
    std::vector<std::vector<int>> generate(int numRows);
};


/*
Tag: array operation
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
Note that the row index starts from 0.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:
Input: 3
Output: [1,3,3,1]
Follow up:
Could you optimize your algorithm to use only O(k) extra space?
*/
class _0119_PascalTriangleII {
public:
    std::vector<int> getRow(int rowIndex);
};

template<unsigned int n>
class _0119_Pascal_meta {
public:
    static std::vector<int> get() {
        auto las = _0119_Pascal_meta<n-1>::get();
        std::vector<int> res(las.size()+1, 0);
        res[0] = 1;
        for(int i = 0; i < las.size() - 1; ++i) {
            res[i+1] = las[i] + las[i+1];
        }
        res.back() = 1;
        return res;
    }
};

template<>
class _0119_Pascal_meta<1> {
public:
    static std::vector<int> get() {
        return {1};
    }
};




/*
Tag: dynamic programming.
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
class _0120_Triangle{
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle);
};



template<unsigned int i>
class _0120_Triangle_meta {
public:
    static std::vector<int> get(std::vector<std::vector<int>>& triangle) {
        std::vector<int> lasOpt = _0120_Triangle_meta<i-1>::get(triangle);
        std::vector<int> res(i + 1, 0);
        for(int j = 0; j <= i; ++j) {
            if(j == 0) {
                res[j] = lasOpt[j] + triangle[i][j];
            } else if(j == i) {
                res[j] = lasOpt[j-1] + triangle[i][j];
            } else {
                res[j] = std::min(lasOpt[j], lasOpt[j-1]) + triangle[i][j];
            }
        }
        return res;
    }

};

template<>
class _0120_Triangle_meta<0> {
public:
    static std::vector<int> get(std::vector<std::vector<int>>& triangle) {
        return triangle[0];
    }
};


/*
Tag: Stack
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


/*
A peak element is an element that is greater than its neighbors. Given an input array 
nums, where nums[i] ≠ nums[i+1], find a peak element and return its index. The array 
may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.
Example 1:

Input: nums = [1,2,3,1]          :         Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Input: nums = [1,2,1,3,5,6,4]    :         Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
or index number 5 where the peak element is 6.
*/
class _0162_FindPeakElement {
public:
    int findPeakElement(std::vector<int>& nums);
};


/*
Given an array of size n, find the majority element. The majority element is the 
element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist 
in the array.

Input: [3,2,3]            :            Output: 3
Input: [2,2,1,1,1,2,2]    :            Output: 2
*/
class _0169_MajorityElement {
public:
    int majorityElement(std::vector<int>& nums);
    int majorityElement_hash(std::vector<int>& nums);
    int majorityElement_Nth(std::vector<int>& nums);
    int majorityElement_Random(std::vector<int>& nums);
    int majorityElement_DivideAndConquer(std::vector<int>& nums, int l, int r);
    int majorityElement_MooreVoting(std::vector<int>& nums);
    int majorityElement_bit(std::vector<int>& nums);
};


/*
Tag: string like reverse
Given an array, rotate the array to the right by k steps, where k is non-negative.

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/
class _0189_RotateArray {
public:
    void rotate(std::vector<int>& nums, int k);
};



}
#endif