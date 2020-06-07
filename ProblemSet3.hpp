#ifndef PROBLEM_SET3_HPP
#define PROBLEM_SET3_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"
namespace LeetCode {

    
/*
Remove the minimum number of invalid parentheses in order to make the input string valid. 
Return all possible results. Note: The input string may contain letters other than the 
parentheses ( and ).

Input: "()())()"
Output: ["()()()", "(())()"]

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]

Input: ")("
Output: [""]
*/
class _0301_RemoveInvalidParentheses {
public:
    std::vector<std::string> removeInvalidParentheses(const std::string& parentheses);
private:
    bool isValid(const std::string& s);
    void DFS(const std::string& s, int start, int l, int r, std::vector<std::string>& ans);
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
Additive number is a string whose digits can form additive sequence.
A valid additive sequence should contain at least three numbers. Except 
for the first two numbers, each subsequent number in the sequence must 
be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to 
determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so 
sequence 1, 2, 03 or 1, 02, 3 is invalid.

Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

Input: "199100199"
Output: true
Explanation: The additive sequence is: 1, 99, 100, 199. 
    1 + 99 = 100, 99 + 100 = 199

Constraints:
num consists only of digits '0'-'9'.
1 <= num.length <= 35
Follow up:
How would you handle overflow for very large input integers?
*/
class _0306_AdditiveNumber {
public:
    bool isAdditiveNumber(std::string num);
    bool isAdditiveNumber(std::string& num, int start1, int start2, int start3);
    std::string add(std::string a, std::string b);
};

/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/
class _0307_RangeSumQuery_Mutable {
private:
    std::vector<int> data;
    int arrayLength;
public:
    _0307_RangeSumQuery_Mutable(std::vector<int>& nums);
    void update(int i, int val);
    int sumRange(int i, int j);
};

/*
For an undirected graph with tree characteristics, we can choose any node as 
the root. The result graph is then a rooted tree. Among all possible rooted 
trees, those with minimum height are called minimum height trees (MHTs). Given 
such a graph, write a function to find all the MHTs and return a list of their 
root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given 
the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are
undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

Output: [1]

Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

Output: [3, 4]
*/
class _0310_MinimumHeightTrees {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges);
};


/*
Given two sparse matrices A and B, return the result of AB.
You may assume that A's column number is equal to B's row number.

Input:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/
class _0311_SparseMatrixMultiplication {
public:
    std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B);

};


/*
Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all prime factors are in the given 
prime list primes of size k.

Input: n = 12, primes = [2,7,13,19]
Output: 32 
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 
    super ugly numbers given primes = [2,7,13,19] of size 4.
Note:

1 is a super ugly number for any given primes.
The given numbers in primes are in ascending order.
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
*/
class _0313_SuperUglyNumber {
public:
    int nthSuperUglyNumber(int n, std::vector<int>& primes);
private:
    int _min(std::vector<int>& res, std::vector<int>& idx, std::vector<int>& primes);
};


/*
You are given an integer array nums and you have to return a new counts array. The 
counts array has the property where counts[i] is the number of smaller elements to 
the right of nums[i].

Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/
class _0315_CountOfSmallerNumberAfterSelf {
public:
    std::vector<int> countSmaller(std::vector<int>& nums);
};

/*
Given a string which contains only lowercase letters, remove duplicate letters 
so that every letter appears once and only once. You must make sure your result 
is the smallest in lexicographical order among all possible results.

Input: "bcabc"          :           Output: "abc"
Input: "cbacdcbc"       :           Output: "acdb"

// https://www.youtube.com/watch?v=SrlvMmfG8sA
// 分别用两个数组来记录，第一个数组统计各个字母出现的次数
// 第二个数组用于记录这个字符是否用过了
*/
class _0316_RemoveDuplicateLetters {
public:   
    std::string removeDuplicateLetters(std::string s);
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
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you 
turn off every second bulb. On the third round, you toggle every third bulb (turning 
on if it's off or turning off if it's on). For the i-th round, you toggle every i bulb. 
For the n-th round, you only toggle the last bulb. Find how many bulbs are on after 
n rounds.

Example:

Input: 3
Output: 1 
Explanation: 
At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
*/
class _0319_BulbSwitcher {
public:
    int bulbSwitch(int n);
};

/*
Tag: 

Google
   
Write a function to generate the generalized abbreviations of a word. 
Note: The order of the output does not matter.
Example:

Input: "word"
Output:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", 
"1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/
class _0320_GeneralizedAbbreviation {
public:
    std::vector<std::string> generalizeAbbreviations(std::string word);
};

/*
Given two arrays of length m and n with digits 0-9 representing two 
numbers. Create the maximum number of length k <= m + n from digits
of the two. The relative order of the digits from the same array 
must be preserved. Return an array of the k digits.

Note: You should try to optimize your time and space complexity.

Example 1:

Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:
[9, 8, 6, 5, 3]
Example 2:

Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
Output:
[6, 7, 6, 0, 4]
Example 3:

Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
Output:
[9, 8, 9]
// 经典题，必会的，DP + Greedy
//将问题拆分成两步，第一步两个数组合并，如果都用上，如何得到最大，第二步，在一个数组中拿k个数，怎么得到最大。
// 第三步，分别在两个数组中拿k1，k-k1 个元素，各自最大，然后合并出最大于当前的，直到遍历所有可能的k1
*/
class _0321_CreateMaximumNumber {
public:
    std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k);
private:
    std::vector<int> maxNumber(const std::vector<int>& nums1,const std::vector<int>& nums2);
    std::vector<int> maxNumber(const std::vector<int>& nums, int k);
};

/*
Tag: dynamic programming
You are given coins of different denominations and a total amount of 
money amount. Write a function to compute the fewest number of coins 
that you need to make up that amount. If that amount of money cannot 
be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
*/
class _0322_CoinChange {
public:
    int coinChange(std::vector<int>& coins, int amount);
private:
    int coinChange_Help(const std::vector<int>& coins, int amout);
    std::vector<int> DP;
};

/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
Follow Up:
Can you do it in O(n) time?
*/
class _0325_MaximumSizeSubarraySumEqualsK {
public:
    int maxSubArrayLen(std::vector<int>& nums, int k);
};

/*
Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
Follow up:
Could you do it without using any loop / recursion?
*/
class _0326_PowerOfThree{
public:
    bool isPowerOfThree(int n);
};

/*
328. Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by 
the even nodes. Please note here we are talking about the node number 
and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space 
complexity and O(nodes) time complexity.

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
*/
class _0328_OddEvenLinkedList {
public:
    ListNode<int>* oddEvenList(ListNode<int>* head);
};

/*
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. You may NOT 
move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/
class _0329_LongestIncreasingPathInAMatrix {
private:
    std::vector<std::vector<int>> DP;
    int mRow;
    int mCol;
    int DFS(const std::vector<std::vector<int>>& matrix, int I, int J);
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix);
};

/*
Given a sorted positive integer array nums and an integer n, add/patch elements to the array 
such that any number in range [1, n] inclusive can be formed by the sum of some elements in 
the array. Return the minimum number of patches required.

Input: nums = [1,3], n = 6
Output: 1 
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].
Example 3:

Input: nums = [1,2,2], n = 5
Output: 0
*/
class _0330_PatchingArray {
public:
    int minPatches(std::vector<int>& nums, int n);
};

/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a 
non-null node, we record the node's value. If it is a null node, we record using a 
sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", 
where # represents a null node.
Given a string of comma separated values, verify whether it is a correct preorder traversal 
serialization of a binary tree. Find an algorithm without reconstructing the tree.
Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
You may assume that the input format is always valid, for example it could never contain two 
consecutive commas such as "1,,3".

Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true

Input: "1,#"
Output: false

Input: "9,#,#,1"
Output: false
*/
class _0331_VerifyPreorderSerializationOfABinaryTree {
public:
    bool isValidSerialization(std::string preorder);
};

/*
The thief has found himself a new place for his thievery again. There is only one 
entrance to this area, called the "root." Besides the root, each house has one and 
only one parent house. After a tour, the smart thief realized that "all houses in 
this place forms a binary tree". It will automatically contact the police if two 
directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting 
the police.

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/
class _0337_HouseRobberIII {
private:
    std::unordered_map<TreeNode<int>*, int> Map;
public:
    int rob(TreeNode<int>* root);
private:
    int robHelper(TreeNode<int>* root);
};

/*
Given a non negative integer number num. For every numbers i in the range 
0 ≤ i ≤ num calculate the number of 1's in their binary representation and 
return them as an array.

Input: 2  :  Output: [0,1,1]

Input: 5  :  Output: [0,1,1,2,1,2]

It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like 
__builtin_popcount in c++ or in any other language.
*/
class _0338_CountingBits {
public:
    std::vector<int> countBits(int num);
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

/*
Given a nested list of integers, return the sum of all integers in the list weighted by 
their depth. Each element is either an integer, or a list -- whose elements may also be 
integers or other lists.

Input: [[1,1],2,[1,1]]
Output: 10 
Explanation: Four 1's at depth 2, one 2 at depth 1.

Input: [1,[4,[6]]]
Output: 27 
Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27.
*/
class _0339_NestedListWeightSum {
public:
    int depthSum(std::vector<NestedInteger>& nestedList);
private:
    int depthSum(std::vector<NestedInteger>& nestedList, int depth);
};

/*
Tag: Sliding Window

Facebook

Given a string, find the length of the longest substring T that contains at most k 
distinct characters.

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.
*/
class _0340_LongestSubstringWithAtMostKDistintCharacters {
public:
    int lengthOfLongestSubstringKDistinct(std::string s, int k);
};

// TODO: COPY FROM A SOLUTION
class _0341_FlattenNestedListIterator {
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
class _0342_PowerOfFour {
public:
    bool isPowerOfFour(int num);
};

/*
Given a positive integer n, break it into the sum of at least two 
positive integers and maximize the product of those integers. Return 
the maximum product you can get.

Input: 2      :       Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Input: 10     :       Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
Note: You may assume that n is not less than 2 and not larger than 58.
*/
class _0343_IntegerBreak {
public:
    int intergerBreak(int n);
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

Tag: hash

Facebook

Given two arrays, write a function to compute their intersection.

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:
Each element in the result must be unique.
The result can be in any order.
*/
class _0349_IntersectionOfTwoArrays {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2);
};

/*
Given two arrays, write a function to compute their intersection.

Input: nums1 = [1,2,2,1], nums2 = [2,2]           :          Output: [2,2]
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]       :          Output: [4,9]

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/
class _0350_IntersectionOfTwoArraysII {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);
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
Design a logger system that receive stream of messages along with 
its timestamps, each message should be printed if and only if it 
is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity), return 
true if the message should be printed in the given timestamp, 
otherwise returns false.

It is possible that several messages arrive roughly at the same time.

Logger logger = new Logger();

// logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true; 

// logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;

// logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;

// logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;

// logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;

// logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;
*/
class _0359_LoggerRateLimiter {
private:
    std::unordered_map<std::string, int> map;
public:
    _0359_LoggerRateLimiter() {}
    bool shouldPrintMessage(int timeStamp, std::string message);
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
Tag: Data Structure
Google

Design a hit counter which counts the number of hits received 
in the past 5 minutes.
Each function accepts a timestamp parameter (in seconds granularity) 
and you may assume that calls are being made to the system in 
chronological order (ie, the timestamp is monotonically increasing). 
You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 
Follow up:
What if the number of hits per second could be very large? Does your design scale?
*/
class _0362_DesignHitCounter {
    class Node {
    public:
        int timeStamp;
        int hitNum;
        Node* prev;
        Node* next;
    };
private:
    Node* head;
    Node* tail;
public:
    _0362_DesignHitCounter() {
        head = nullptr;
        tail = nullptr;
    }
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). 
    */
    void hit(int timestamp);

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). 
    */
    int getHits(int timestamp);
};

/*
Given a nested list of integers, return the sum of all integers in the list 
weighted by their depth. Each element is either an integer, or a list -- 
whose elements may also be integers or other lists. Different from the previous 
question where weight is increasing from root to leaf, now the weight is 
defined from bottom up. i.e., the leaf level integers have weight 1, and the 
root level integers have the largest weight.

Input: [[1,1],2,[1,1]]
Output: 8 
Explanation: Four 1's at depth 1, one 2 at depth 2.

Input: [1,[4,[6]]]
Output: 17 
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17.
*/
class NestedInteger;
class _0364_NestedListWeightSumII {
public:
    int depthSumInv(std::vector<NestedInteger>& nestedList, int level);;
};

/*
Given a positive integer num, write a function which returns True if num is a 
perfect square else False. Note: Do not use any built-in library function such 
as sqrt.

Input: 16
Returns: True

Input: 14
Returns: False
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/
class _0367_ValidPerfectSquare {
public:
    bool isPerfectSquare(int x);
};

/*
Given a set of distinct positive integers, find the largest subset such that every pair 
(Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)

Input: [1,2,4,8]
Output: [1,2,4,8]
*/
class _0368_LargestDivisibleSubset {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums);
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
Your task is to calculate ab mod 1337 where a is a positive integer 
and b is an extremely large positive integer given in the form of an array.

Input: a = 2, b = [3]
Output: 8

Input: a = 2, b = [1,0]
Output: 1024
*/
class _0372_SuperPow {
public:
    int superPow(int a, std::vector<int>& b);
};

/*
A sequence of numbers is called a wiggle sequence if the differences between 
successive numbers strictly alternate between positive and negative. The first 
difference (if one exists) may be either positive or negative. A sequence 
with fewer than two elements is trivially a wiggle sequence.
For example, [1,7,4,9,2,5] is a wiggle sequence because the differences 
(6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] 
and [1,7,4,5,5] are not wiggle sequences, the first because its first two 
differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that 
is a wiggle sequence. A subsequence is obtained by deleting some number of elements 
(eventually, also zero) from the original sequence, leaving the remaining elements 
in their original order.

Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.
Example 2:

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
Example 3:

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?
*/
class _0376_WiggleSubsequence {
public:
    int wiggleMaxLength(std::vector<int>& nums);
};

/*
Given an integer array with all positive numbers and no duplicates, find the number of possible 
combinations that add up to a positive integer target.

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
*/
class _0377_CombinationSumIV {
public:

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
Insert Delete GetRandom O(1) 
Design a data structure that supports all following operations in average O(1) time.
insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();
*/
class _0380_RandomizedSet {
private:
    std::unordered_map<int, int> valueIndex;
    std::vector<int> values;
public:
    /** Initialize your data structure here. */
    _0380_RandomizedSet();    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val);    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val);    
    /** Get a random element from the set. */
    int getRandom();
};

/*
Insert Delete GetRandom O(1) - Duplicates allowed
Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
*/
class _0381_RandomizedCollection {
private:
    std::vector<int> data;
    std::unordered_map<int, std::unordered_set<int>> map;
public:
    /** Initialize your data structure here. */
    _0381_RandomizedCollection();
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val);
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val);
    
    /** Get a random element from the collection. */
    int getRandom();
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
Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
 

Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
 

Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
*/
class _0385_MiniParser{
public:
class NestedInteger {
 public:
     // Constructor initializes an empty nested list.
     NestedInteger();
     // Constructor initializes a single integer.
     NestedInteger(int value) {}
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const { 
         return true; 
     }
     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const {
         return 0;
     }
      // Set this NestedInteger to hold a single integer.
     void setInteger(int value);
      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);
      // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const {
        return std::vector<NestedInteger>();
    }
 };

NestedInteger deserialize(std::string s);
};


/*
Given an integer n, return 1 - n in lexicographical order.
For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
Please optimize your algorithm to use less time and space. 
The input size may be as large as 5,000,000.
*/
class _0386_LexicographicalNumbers {
private:
    std::vector<int> res;
    void dfs(int cur, int n);
public:
    std::vector<int> lexicalOrder(int n);
};

/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
*/
class _0387_FirstUniqueCharacterInAString {
public:
    int firstUniqChar(std::string s);
};

/*
Tag: Stack, string
GOOGLE
TODO:
Suppose we abstract our file system by a string in the following manner:
The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory 
subdir2 containing a file file.ext.
The string 
"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" 
represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains 
a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains 
a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file 
within our file system. For example, in the second example above, the longest absolute 
path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the 
double quotes).

Given a string representing the file system in the above format, return the length 
of the longest absolute path to file in the abstracted file system. If there is no 
file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another 
path aaaaaaaaaaaaaaaaaaaaa/sth.png.
*/
class _0388_LongestAbsoluteFilePath {
public:
    int lengthLongestPath(std::string input);
};


/*
_390_ Elimination Game
There is a list of sorted integers from 1 to n. Starting from left to right,
remove the first number and every other number afterward until you reach the
end of the list.

Repeat the previous step again, but this time from right to left, remove the
right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left,
until a single number remains.

Find the last number that remains starting with a list of length n.

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
*/
class _0390_EliminationGame {
public:
    int lastRemaining(int n);
};


/*
A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed 
by n-1 bytes with most significant 2 bits being 10.
This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store 
the data. This means each integer represents only 1 byte of data.

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.
Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
*/
class _0393_UTF8Validation {
public:
    bool validUTF8(std::vector<int>& data);
};

/*
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string 
inside the square brackets is being repeated exactly k times. Note 
that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; No extra 
white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain 
any digits and that digits are only for those repeat numbers, k. 
For example, there won't be input like 3a or 2[4].

    s = "3[a]2[bc]", return "aaabcbc".
    s = "3[a2[c]]", return "accaccacc".
    s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
class _0394_DecodeString {
public:
    std::string decodeString(std::string s);
};

/*
Tag: hash

Facebook

Given an array of integers with possible duplicates, randomly output 
the index of a given target number. You can assume that the given 
target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra 
space will not pass the judge.

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index 
should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);
*/
class _0398_RandomPickIndex {
private:
    std::unordered_map<int, std::vector<int>> map;
public:
    _0398_RandomPickIndex(std::vector<int>& nums);
    int pick(int target);
};


/*
Equations are given in the format A / B = k, where A and B are variables represented 
as strings, and k is a real number (floating point number). Given some queries, 
return the answers. If the answer does not exist, return -1.0.

Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, 
vector<pair<string, string>> queries , where equations.size() == values.size(), and the 
values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
 
The input is always valid. You may assume that evaluating the queries will result 
in no division by zero and there is no contradiction.
*/
class _0399_EvaluateDivision {
private:
    // A hash function used to hash a pair of any kind 
    struct hash_pair { 
        template <class T1, class T2> 
        size_t operator()(const std::pair<T1, T2>& p) const
        { 
            auto hash1 = std::hash<T1>{}(p.first); 
            auto hash2 = std::hash<T2>{}(p.second); 
            return hash1 ^ hash2; 
        } 
    }; 
    std::unordered_set<std::string> node;
    std::unordered_map<std::pair<std::string, std::string>, double, hash_pair> edge;
    std::unordered_map<std::string, bool> visited;
    std::unordered_map<std::string, std::vector<std::string>> adjMap;
    void resetVisit();
    std::vector<std::string> getAdj(std::string a);
    
public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, 
    std::vector<double>& values, std::vector<std::vector<std::string>>& queries);    
    double calculate(std::string a, std::string b);
};

/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Input: 3      :     Output: 3
Input: 11     :     Output: 0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/
class _0400_NthDight {
public:
    int findNthDigit(int n);
};

}

#endif