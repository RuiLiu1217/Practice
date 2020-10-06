#ifndef LEETCODE_ARRAYPROBLEMS_HPP
#define LEETCODE_ARRAYPROBLEMS_HPP
#include <vector>
#include <string>
#include <stack>
#include <queue>
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

/*
Given an array of integers that is already sorted in ascending order, find two numbers such
that they add up to a specific target number. The function twoSum should return indices of 
the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same
element twice.

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/
class _0167_TwoSumII_InputArrayIsSorted {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target);
};


/*
Tag: Sliding windows
Google
TODO: edge cases and edge condition

Given an array of n positive integers and a positive integer s, find the minimal length 
of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/
class _0209_MinimumSizeSubarraySum {
public:
    int minSubArrayLen(int s, std::vector<int>& nums);
    int minSubArrayNlogN(int s, std::vector<int>& nums);
};


/*
Facebook

Find the kth largest element in an unsorted array. Note that it is the kth largest 
element in the sorted order, not the kth distinct element.

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
class _0215_KthLargestElementInAnArray {
public:
    int findKthLargest(std::vector<int>& nums, int k);
};

/*
217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in 
the array, and it should return false if every element is distinct.
Input: [1,2,3,1]
Output: true

Input: [1,2,3,4]
Output: false

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/
class _0217_ContainsDuplicate {
public:
    bool containsDuplicate(std::vector<int>& nums);
};


/*
Given an array of integers and an integer k, find out whether there are
two distinct indices i and j in the array such that nums[i] = nums[j]
and the absolute difference between i and j is at most k.

Input: nums = [1,2,3,1], k = 3
Output: true

Input: nums = [1,0,1,1], k = 1
Output: true

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/
class _0219_ContainsDuplicateII {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k);
};



/*
225. Implement Stack using Queues
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
Notes:

You must use only standard operations of a queue -- which means only 
push to back, peek/pop from front, size, and is empty operations are valid.

Depending on your language, queue may not be supported natively. You may 
simulate a queue by using a list or deque (double-ended queue), as long 
as you use only standard operations of a queue. You may assume that all 
operations are valid (for example, no pop or top operations will be 
called on an empty stack).
*/
class _0225_ImplementStackUsingQueues {
public:
    _0225_ImplementStackUsingQueues();

    void push(int x);

    int pop();

    int top();

    bool empty();

private:
    std::queue<int> nums;
};



/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
*/
class _0228_SummaryRange {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums);
};


/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop
from top, size, and is empty operations are valid. Depending on your language, stack may 
not be supported natively. You may simulate a stack by using a list or deque (double-ended 
queue), as long as you use only standard operations of a stack. You may assume that all 
operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/
class _0232_ImplementQueueUsingStacks {
private:
    std::stack<int> left;
    std::stack<int> right;
public:
    _0232_ImplementQueueUsingStacks();
    void push(int x);
    int pop();
    int peek();
    bool empty();
};


/*
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal 
to the product of all the elements of nums except nums[i].

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space 
for the purpose of space complexity analysis.)
*/
class _0238_ProductOfArrayExceptSelf {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums);
};

/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/
class _0243_ShortestWordDistance {
public:
    int shortestDistance(std::vector<std::string>& words, std::string word1, std::string word2);
};


/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1
Input: word1 = "makes", word2 = "makes"
Output: 3
Note:
You may assume word1 and word2 are both in the list.
*/
class _0245_ShortestWordDistanceIII {
public:
    int shortestWordDistance(std::vector<std::string>& words, std::string word1, std::string word2);
};


/*
Design and implement an iterator to flatten a 2d vector. It should support the following operations: next and hasNext.

Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

iterator.next(); // return 1
iterator.next(); // return 2
iterator.next(); // return 3
iterator.hasNext(); // return true
iterator.hasNext(); // return true
iterator.next(); // return 4
iterator.hasNext(); // return false

Notes:

Please remember to RESET your class variables declared in Vector2D, as static/class variables are persisted across multiple test cases. Please see here for more details.
You may assume that next() call will always be valid, that is, there will be at least a next element in the 2d vector when next() is called.

Follow up:

As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/
class _0251_Flatten2DVector {
private:
    std::vector<std::vector<int>>::iterator i, iEnd;
    int j = 0;
public:
    _0251_Flatten2DVector(std::vector<std::vector<int>>& v);
    int next();
    bool hasNext();
};

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
class _0283_MoveZeros {
public:
    void moveZeroes(std::vector<int>& nums);
};


/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using 
the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current 
state. The next state is created by applying the above rules simultaneously to every cell in
the current state, where births and deaths occur simultaneously.

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:
1. Could you solve it in-place? Remember that the board needs to be updated at the same time: 
You cannot update some cells first and then use their updated values to update other cells.
2. In this question, we represent the board using a 2D array. In principle, the board is infinite, 
which would cause problems when the active area encroaches the border of the array. 
How would you address these problems?
*/
class _0289_GameOfLife {
public:
    void gameOfLife(std::vector<std::vector<int>>& board);
};

/*
Given an integer array nums, find the sum of the elements 
between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change. There are 
many calls to sumRange function.
*/
class _0303_RangeSumQuery_Immutable {
public:
    _0303_RangeSumQuery_Immutable(std::vector<int>& nums);
    int sumRange(int i, int j);
private:
    std::vector<int> mSum;
};

/*
Given a 2D matrix matrix, find the sum of the elements inside 
the rectangle defined by its upper left corner (row1, col1) 
and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, 
col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/
class _0304_RangeSumQuery2D_Immutable {
public:
    _0304_RangeSumQuery2D_Immutable(std::vector<std::vector<int>>& matrix);    
    int sumRegion(int row1, int col1, int row2, int col2);
private:
    std::vector<std::vector<int>> prefixSum;
};

/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
class _0347_TopKFrequentElements {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k);
};

/*
Given a sorted array of integers nums and integer values a, b and c. 
Apply a quadratic function of the form f(x) = ax2 + bx + c to each 
element x in the array.

The returned array must be in sorted order.
Expected time complexity: O(n)

Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]

Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]
*/
class _0360_SortTransformedArray {
public:
    std::vector<int> sortTransformedArray(std::vector<int>& nums, int a, int b, int c);
};


/*
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or 
empty '0' (the number zero), return the maximum enemies you can 
kill using one bomb. The bomb kills all the enemies in the same 
row and column from the planted point until it hits the wall since 
the wall is too strong to be destroyed.
Note: You can only put the bomb at an empty cell.

Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3 
Explanation: For the given grid,

0 E 0 0 
E 0 W E 
0 E 0 0

Placing a bomb at (1,1) kills 3 enemies.
*/
class _0361_BombEnemy {
public:
    int maxkilledEnemies(std::vector<std::vector<char>>& grid);
};



/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
class _0406_QueueReconstructionByHeight {
public:
    std::vector<std::pair<int, int>> reconstructQueue(std::vector<std::pair<int, int>>& people);
};


/* Given a non-empty array of integers, return the third maximum number in this array. 
If it does not exist, return the maximum number. The time complexity must be in O(n).

Input: [3, 2, 1]              :              Output: 1
Explanation: The third maximum is 1.

Input: [1, 2]                 :              Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Input: [2, 2, 3, 1]           :              Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
*/
class _0414_ThirdMaximumNumber {
public:
    int thirdMax(std::vector<int>& nums);
};

/*
498. Diagonal Traverse
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]
The total number of elements of the given matrix will not exceed 10,000.
*/
class _0498_DiagonalTraverse {
    public:
        std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& matrix);
};

/*
Given an array of integers and an integer k, you need to find the number of unique 
k - diff pairs in the array.Here a k - diff pair is defined as an integer pair(i, j), 
where i and j are both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output : 2
Explanation : There are two 2 - diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2 :
Input : [1, 2, 3, 4, 5], k = 1
Output : 4
Explanation : There are four 1 - diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3 :
Input : [1, 3, 1, 5, 4], k = 0
Output : 1
Explanation : There is one 0 - diff pair in the array, (1, 1).
Note :
The pairs(i, j) and (j, i) count as the same pair.
The length of the array won't exceed 10,000.
All the integers in the given input belong to the range : [-1e7, 1e7].
这道题给了我们一个含有重复数字的无序数组，还有一个整数k，让我们找出有多少对不重复的数对(i, j)
使得i和j的差刚好为k。由于k有可能为0，而只有含有至少两个相同的数字才能形成数对，那么就是说我们
需要统计数组中每个数字的个数。我们可以建立每个数字和其出现次数之间的映射，然后遍历哈希表中的数
字，如果k为0且该数字出现的次数大于1，则结果res自增1；如果k不为0，且用当前数字加上k后得到的新
数字也在数组中存在，则结果res自增1，参见代码如下：
*/
class _0532_KdiffPairsInAnArray {
public:
    int findPairs(std::vector<int>& nums, int k);
};


/*
Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:

Row R and column C both contain exactly N black pixels.
For all rows that have a black pixel at column C, they should be exactly the same as row R
The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

Example:
Input:                                            
[['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'B', 'W', 'B', 'B', 'W'],    
 ['W', 'W', 'B', 'W', 'B', 'W']] 

N = 3
Output: 6
Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
        0    1    2    3    4    5         column index                                            
0    [['W', 'B', 'W', 'B', 'B', 'W'],    
1     ['W', 'B', 'W', 'B', 'B', 'W'],    
2     ['W', 'B', 'W', 'B', 'B', 'W'],    
3     ['W', 'W', 'B', 'W', 'B', 'W']]    
row index

Take 'B' at row R = 0 and column C = 1 as an example:
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.

Solution:  给了一个整数N，说对于均含有N个个黑像素的某行某列，如果该列中所有的黑像素所在的行都相同的话，该列的
    所有黑像素均为孤独的像素，让我们统计所有的这样的孤独的像素的个数。那么跟之前那题类似，我们还是要
    统计每一行每一列的黑像素的个数，而且由于条件二中要比较各行之间是否相等，如果一个字符一个字符的比
    较写起来比较麻烦，我们可以用个trick，把每行的字符连起来，形成一个字符串，然后直接比较两个字符串
    是否相等会简单很多。然后我们遍历每一行和每一列, 如果某行和某列的黑像素刚好均为N，我们遍历该列的所
    有黑像素，如果其所在行均相等，则说明该列的所有黑像素均为孤独的像素，将个数加入结果res中，然后将该
    行的黑像素统计个数清零，以免重复运算，这样我们就可以求出所有的孤独的像素了.
*/
class _0533_LonelyPixelII {
public:
    int findBlackPixel(std::vector<std::vector<char>>& picture, int N);
};

/*
Given a 2D integer matrix M representing the gray scale of an image, 
you need to design a smoother to make the gray scale of each cell 
becomes the average gray scale (rounding down) of all the 8 surrounding 
cells and itself. If a cell has less than 8 surrounding cells, then 
use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].
*/
class _0661_ImageSmoother {
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& M);
};


/*
Given a non-empty list of words, return the k most frequent elements.
Your answer should be sorted by frequency from highest to lowest. If 
two words have the same frequency, then the word with the lower 
alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/
class _0692_TopKFrequentWords {
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k);
};

/*
In a 2 dimensional array grid, each value grid[i][j] represents the height of a building 
located there. We are allowed to increase the height of any number of buildings, by any 
amount (the amounts can be different for different buildings). Height 0 is considered to 
be a building as well. 
At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, 
bottom, left, and right, must be the same as the skyline of the original grid. A city's 
skyline is the outer contour of the rectangles formed by all the buildings when viewed 
from a distance. See the following example.

What is the maximum total sum that the height of the buildings can be increased?

Example:
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: 
The grid is:
[ [3, 0, 8, 4], 
  [2, 4, 5, 7],
  [9, 2, 6, 3],
  [0, 3, 1, 0] ]

The skyline viewed from top or bottom is: [9, 4, 8, 7]
The skyline viewed from left or right is: [8, 7, 9, 3]

The grid after increasing the height of buildings without affecting skylines is:

gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]

Notes:
1 < grid.length = grid[0].length <= 50.
All heights grid[i][j] are in the range [0, 100].
All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.
*/
class _0807_MaxIncreaseToKeepCitySkyline {
private:
    int rowNum;
    int colNum;
public:
    int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
        rowNum = grid.size();
        if(rowNum == 0) { return 0; }
        colNum = grid[0].size();
        if(colNum == 0) { return 0; }
        
        auto [rowMax, colMax] = getRowAndColMax(grid);
        int sum = 0;
        for(int rowIdx = 0; rowIdx != rowNum; ++rowIdx) {
            for(int colIdx = 0; colIdx != colNum; ++colIdx) {
                sum += (std::min(rowMax[rowIdx], colMax[colIdx]) - grid[rowIdx][colIdx]);
            }
        }
        return sum;
        
    }
    std::pair<std::vector<int>, std::vector<int>> getRowAndColMax(const std::vector<std::vector<int>>& grid) {
        std::vector<int> rowMax(rowNum, 0);
        std::vector<int> colMax(colNum, 0);
        for(int r = 0; r < rowNum; ++r) {
            for(int c = 0; c < colNum; ++c) {
                rowMax[r] = std::max(rowMax[r], grid[r][c]);
                colMax[c] = std::max(colMax[c], grid[r][c]);
            }
        }
        return {rowMax, colMax};
    }
};

/*
In a string S of lowercase letters, these letters form consecutive groups of the same character.
For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.
The final answer should be in lexicographic order.

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
*/
class _0830_PositionsOfLargeGroups {
public:
    std::vector<std::vector<int>> largeGroupPositions(std::string S);
};

/*
Given a binary matrix A, we want to flip the image horizontally, 
then invert it, and return the resulting image.
To flip an image horizontally means that each row of the image is 
reversed. For example, flipping [1, 1, 0] horizontally results in 
[0, 1, 1].
To invert an image means that each 0 is replaced by 1, and each 1 
is replaced by 0. For example, inverting [0, 1, 1] results in 
[1, 0, 0].

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1
*/
class _0832_FlippingAnImage {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A);
};



/*
 838 Push Dominoes
There are N dominoes in a line, and we place each domino vertically upright.
In the beginning, we simultaneously push some of the dominoes either to the 
left or to the right. After each second, each domino that is falling to the 
left pushes the adjacent domino on the left. Similarly, the dominoes falling 
to the right push their adjacent dominoes standing on the right.
When a vertical domino has dominoes falling on it from both sides, it stays 
still due to the balance of the forces. For the purposes of this question, 
we will consider that a falling domino expends no additional force to a 
falling or already fallen domino.
Given a string "S" representing the initial state. S[i] = 'L', if the i-th 
domino has been pushed to the left; S[i] = 'R', if the i-th domino has been 
pushed to the right; S[i] = '.', if the i-th domino has not been pushed.

Return a string representing the final state. 

Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."

Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Note:
    0 <= N <= 10^5
    String dominoes contains only 'L', 'R' and '.'
*/
class _0838_PushDominoes {
  public:
    std::string pushDominoes(std::string dominoes);
};


/*
Let's call an array A a mountain if the following properties hold:

A.length >= 3
There exists some 0 < i < A.length - 1 such that 
A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
Given an array that is definitely a mountain, return any i such that 
A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Input: [0,1,0]
Output: 1

Input: [0,2,1,0]
Output: 1
Note:

3 <= A.length <= 10000
0 <= A[i] <= 10^6
A is a mountain, as defined above.
*/
class _0852_PeakIndexInAMountainArray {
public:
    int peakIndexInMountainArray(std::vector<int>& A);
};


/*
We have a two dimensional matrix A where each value is 0 or 1.
A move consists of choosing any row or column, and toggling each 
value in that row or column: changing all 0s to 1s, and all 1s to 0s.
After making any number of moves, every row of this matrix is 
interpreted as a binary number, and the score of the matrix is the 
sum of these numbers.
Return the highest possible score.

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

Note:
1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] is 0 or 1.
*/
class _0861_ScoreAfterFlippingMatrix {
public:
    int matrixScore(std::vector<std::vector<int>>& A);
};

/*
A robot on an infinite grid starts at point (0, 0) and faces 
north. The robot can receive one of three possible types of 
commands:

-2: turn left 90 degrees
-1: turn right 90 degrees
1 <= x <= 9: move forward x units
Some of the grid squares are obstacles. 

The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])
If the robot would try to move onto them, the robot stays on the 
previous grid square instead (but still continues following the 
rest of the route.)
Return the square of the maximum Euclidean distance that the robot 
will be from the origin.

Input: commands = [4,-1,3], obstacles = []    :    Output: 25
Explanation: robot will go to (3, 4)

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]    :   Output: 65
Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)
*/
class _0874_WalkingRobotSimulation {
public:
    int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles);
};

/*
The i-th person has weight people[i], and each boat can carry a 
maximum weight of limit. Each boat carries at most 2 people at the 
same time, provided the sum of the weight of those people is at 
most limit.
Return the minimum number of boats to carry every given person. 
(It is guaranteed each person can be carried by a boat.)

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
Note:

1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000
*/
class _0881_BoatsToSavePeople {
public:
    int numResculeBoats(std::vector<int>& people, int limit);
};

/*
On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the 
x, y, and z axes. Each value v = grid[i][j] represents a tower of v cubes 
placed on top of grid cell (i, j). Now we view the projection of these 
cubes onto the xy, yz, and zx planes. 
A projection is like a shadow, that maps our 3 dimensional figure to a 2 
dimensional plane. Here, we are viewing the "shadow" when looking at the 
cubes from the top, the front, and the side.
Return the total area of all three projections.

Input: [[2]]
Output: 5

Input: [[1,2],[3,4]]
Output: 17
Explanation: 
Here are the three projections ("shadows") of the shape made with each axis-aligned plane.
*/
class _0883_ProjectionAreaOf3DShapes {
public:
    int projectionArea(std::vector<std::vector<int>>& grid);
};

/*
Write a class RecentCounter to count recent requests.
It has only one method: ping(int t), where t represents some 
time in milliseconds.
Return the number of pings that have been made from 3000 
milliseconds ago until now.
Any ping with time in [t - 3000, t] will count, including 
the current ping.
It is guaranteed that every call to ping uses a strictly larger 
value of t than before.

Input: inputs = ["RecentCounter","ping","ping","ping","ping"], 
inputs = [[],[1],[100],[3001],[3002]]
Output: [null,1,2,3,3]

Each test case will have at most 10000 calls to ping.
Each test case will call ping with strictly increasing values of t.
Each call to ping will have 1 <= t <= 10^9.
*/
class _0933_NumberOfRecentCalls {
private:
    std::queue<int> q;
public:
    _0933_NumberOfRecentCalls();
    int ping(int t);
};

/*
Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.

An array A is a zigzag array if either:

Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
Return the minimum number of moves to transform the given array nums into a zigzag array.

Input: nums = [1,2,3]
Output: 2
Explanation: We can decrease 2 to 0 or 3 to 1.

Input: nums = [9,6,1,6,2]
Output: 4

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 1000
*/
class _1144_DecreaseElementsToMakeArrayZigzag {
public:
    int movesToMakeZigzag(std::vector<int>& nums);
};

/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor 
and divide all the array by it and sum the result of the division. Find the smallest divisor such 
that the result mentioned above is less than or equal to threshold.

Each result of division is rounded to the nearest integer greater than or equal to that element. 
(For example: 7/3 = 3 and 10/2 = 5).
It is guaranteed that there will be an answer.


Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum to 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

Input: nums = [2,3,5,7,11], threshold = 11
Output: 3

Input: nums = [19], threshold = 5
Output: 4

Constraints:

1 <= nums.length <= 5 * 10^4
1 <= nums[i] <= 10^6
nums.length <= threshold <= 10^6
*/
class _1283_FindTheSmallestDivisorGivenAThreshold {
public:
    int smallestDivisor(std::vector<int>& nums, int threshold);
};

/*
Given a rows x cols matrix mat, where mat[i][j] is either 0 or 1, return the number of special positions in mat.
A position (i,j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and 
columns are 0-indexed).

Input: mat = [[1,0,0],
              [0,0,1],
              [1,0,0]]
Output: 1
Explanation: (1,2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.

Input: mat = [[1,0,0],
              [0,1,0],
              [0,0,1]]
Output: 3
Explanation: (0,0), (1,1) and (2,2) are special positions. 

Input: mat = [[0,0,0,1],
              [1,0,0,0],
              [0,1,1,0],
              [0,0,0,0]]
Output: 2

Input: mat = [[0,0,0,0,0],
              [1,0,0,0,0],
              [0,1,0,0,0],
              [0,0,1,0,0],
              [0,0,0,1,1]]
Output: 3

Constraints:

rows == mat.length
cols == mat[i].length
1 <= rows, cols <= 100
mat[i][j] is 0 or 1.
*/
class _1582_SpecialPositionsInABinaryMatrix {
public:
    int numSpecial(std::vector<std::vector<int>>& mat);
};

}
#endif