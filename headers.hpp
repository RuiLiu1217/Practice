#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include "Tree.hpp"
#include "LinkList.hpp"

#include "ProblemSet1.hpp" // Problem 1 - 100
#include "ProblemSet2.hpp"
#include "ProblemSet3.hpp"

namespace LeetCode
{

/*
You are a professional robber planning to rob houses along a street. Each house 
has a certain amount of money stashed. All houses at this place are arranged in 
a circle. That means the first house is the neighbor of the last one. Meanwhile, 
adjacent houses have security system connected and it will automatically contact 
the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each 
house, determine the maximum amount of money you can rob tonight without alerting 
the police.

Input: [2,3,2]            :            Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
because they are adjacent houses.

Input: [1,2,3,1]          :            Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
这道题也是一下子蒙住了，实际上很简单，因为第一个房子和最后一个房子不能都抢，因此分别算两次，
即排除第一个房子的情况，以及排除最后一个房子的情况。然后取大的。
*/
class _0213_HouseRobberII {
public:
    int rob(std::vector<int>& nums);
private:
    int robHelp(std::vector<int>& nums);
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
private:
    std::unordered_map<char, std::string> map;
    std::unordered_map<std::string, char> map2;
};


/*
Given an unsorted array of integers, find the length of longest increasing 
subsequence.
Example:
Input: [10,9,2,5,3,7,101,18]       :       Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:
There may be more than one LIS combination, it is only necessary for you to return 
the length. Your algorithm should run in O(n2) complexity. 
Follow up: Could you improve it to O(n log n) time complexity?
*/
class _0300_LongestIncreasingSubsequence {
public:
    int lengthOfLIS(std::vector<int>& nums);
private:
    int lengthOfLIS_N2(std::vector<int>& nums);
    int lengthOfLIS_NlogN(std::vector<int>& nums);
};

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


/*
Given an integer, write an algorithm to convert it to hexadecimal. For 
negative integer, two’s complement method is used.
All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is 
zero, it is represented by a single zero character '0'; otherwise, the first 
character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed 
integer.
You must not use any method provided by the library which converts/formats 
the number to hex directly.
Input:  26         Output:  "1a"
Input:  -1         Output:  "ffffffff"
*/
class _0405_ConvertANumberToHexadecimal{
public:
    std::string toHex(int num);
};

class _0406_QueueReconstructionByHeight {
    public:
        std::vector<std::pair<int, int>> reconstructQueue(std::vector<std::pair<int, int>>& people);
};

class _0409_LongestPalindrome {
public:
    int longestPalindrome(std::string s);
};

class _0412_FizzBuzz {
public:
    std::vector<std::string> fizzBuzz(int n);
};
 
class _0413_ArighmeticSlices {
public:
    int numberOfArithmeticSlices(std::vector<int>& A);
private:
    int numberOfSubArith(int N);
};
 
class _0414_ThirdMaximumNumber{
public:
    int thirdMax(std::vector<int>& nums);
};

class _0415_AddStrings {
public:
    std::string addStrings(std::string num1, std::string num2);
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
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"
*/
class _0423_ReconstructOriginalDigitFromEnglish {
public:
    std::string originalDigits(std::string s);
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

class _0434_NumberOfSegmentsInAString {
public:
    int countSegments(std::string s);
};

class _0441_ArrangingCoins {
public:
    int arrangeCoins(int n);
};

class _0442_FindAllDuplicatesInAnArray {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums);
};

/*
Given n points in the plane that are all pairwise distinct, a 
"boomerang" is a tuple of points (i, j, k) such that the distance between 
i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and 
coordinates of points are all in the range [-10000, 10000] (inclusive).
Example:

Input:
[[0,0],[1,0],[2,0]]

Output:
2
Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/
class _0447_NumberOfBoomerangs {
public:
    int numberOfBoomerangs(std::vector<std::vector<int>>& points);
};

/*
There are a number of spherical balloons spread in two-dimensional space. 
For each balloon, provided input is the start and end coordinates of the 
horizontal diameter. Since it's horizontal, y-coordinates don't matter 
and hence the x-coordinates of start and end of the diameter suffice. Start 
is always smaller than end. There will be at most 104 balloons.
An arrow can be shot up exactly vertically from different points along the 
x-axis. A balloon with xstart and xend bursts by an arrow shot at x if 
xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be 
shot. An arrow once shot keeps travelling up infinitely. The problem is to 
find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input: [[10,16], [2,8], [1,6], [7,12]] :   Output:  2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
*/
class _0452_MinimumNumberOfArrowsToBusrtBalloons {
    public:
        int findMinArrowShots(std::vector<std::vector<int>>& points);
};


/*
In the "100 game," two players take turns adding, to a running total, any 
integer from 1..10. The player who first causes the running total to reach 
or exceed 100 wins.
What if we change the game so that players cannot re-use integers?
For example, two players might take turns drawing from a common pool of 
numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, 
determine if the first player to move can force a win, assuming both 
players play optimally.

You can always assume that maxChoosableInteger will not be larger than 
20 and desiredTotal will not be larger than 300.

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers 
from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is 
>= desiredTotal. Same with other integers chosen by the first player, the 
second player will always win.
*/
class _0464_CanIWin {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal);
private:
    std::vector<char> m_; //
    bool canIWin(int M, int T, int state);
};



/*
A magical string S consists of only '1' and '2' and obeys the following rules:
The string S is magical because concatenating the number of contiguous occurrences 
of characters '1' and '2' generates the string S itself.
The first few elements of string S is the following: S = 
"1221121221221121122……"
If we group the consecutive '1's and '2's in S, it will be:
1 22 11 2 1 22 1 22 11 2 11 22 ......
and the occurrences of '1's or '2's in each group are:
1 2 2 1 1 2 1 2 2 1 2 2 ......
You can see that the occurrence sequence above is the S itself.
Given an integer N as input, return the number of '1's in the first N number in the magical string S.
Note: N will not exceed 100,000.
Example 1:
Input: 6
Output: 3
Explanation: The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.
*/
class _0481_MagicalString {
public:
    int magicalString(int n);
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
Given two non-empty binary trees s and t, check whether tree t has exactly 
the same structure and node values with a subtree of s. A subtree of s is 
a tree consists of a node in s and all of this node's descendants. The tree 
s could also be considered as a subtree of itself.
Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree 
of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
*/
class _0572_SubtreeOfAnotherTree {
public:
    bool isSubtree(TreeNode<int>* s, TreeNode<int>* t);
private:
    bool isSame(TreeNode<int>* s, TreeNode<int>* t);
};

/*
Design your implementation of the circular double-ended queue (deque).

Your implementation should support following operations:

MyCircularDeque(k): Constructor, set the size of the deque to be k.
insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
getRear(): Gets the last item from Deque. If the deque is empty, return -1.
isEmpty(): Checks whether Deque is empty or not. 
isFull(): Checks whether Deque is full or not.
 

Example:

MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
circularDeque.insertLast(1);			// return true
circularDeque.insertLast(2);			// return true
circularDeque.insertFront(3);			// return true
circularDeque.insertFront(4);			// return false, the queue is full
circularDeque.getRear();  			// return 2
circularDeque.isFull();				// return true
circularDeque.deleteLast();			// return true
circularDeque.insertFront(4);			// return true
circularDeque.getFront();			// return 4
 

Note:

All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Deque library.
*/
class _0641_DesignCircularDeque{
private:
    std::vector<int> q;
    int start;
    int end;
    int K;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    _0641_DesignCircularDeque(int k);
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value);

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value);
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront();
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast();
    
    /** Get the front item from the deque. */
    int getFront();
    
    /** Get the last item from the deque. */
    int getRear();

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty();
    
    /** Checks whether the circular deque is full or not. */
    bool isFull();
};


/*
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different 
substrings even they consist of same characters.

Input: "abc"        :        Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 
Input: "aaa"        :        Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/
class _0647_PalindromicSubstrings{
public:
    int countSubstrings(std::string s);
private:
    int sub(const std::string& s, int k);
};

/*
Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of 
the first row it can be put. The column and the row where the root node belongs 
will separate the rest space into two parts (left-bottom part and right-bottom 
part). You should print the left subtree in the left-bottom part and print the 
right subtree in the right-bottom part. The left-bottom part and the right-bottom 
part should have the same size. Even if one subtree is none while the other is 
not, you don't need to print anything for the none subtree but still need to 
leave the space as large as that for the other subtree. However, if two subtrees 
are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
Note: The height of binary tree is in the range of [1, 10].
这道题一下子蒙住了，实际上这道题很简单，还是一个递归调用，首先要建立起整个矩阵，用空字符串填满
这里就需要计算好本身这棵树有多高，那么有多宽就可以算出来，
每层都是在正中间填充数字，递归调用把左右两边的范围分别变成 [l mid-1]， [mid + 1, r] 就可以了
*/
class _0655_PrintBinaryTree {
public:
    std::vector<std::vector<std::string>> printTree(TreeNode<int>* root);
private:
    int getHeight(TreeNode<int>* root);
    void fill(TreeNode<int>* root, std::vector<std::vector<std::string>>& res, int h, int l, int r);
};

/*
You are given an integer array sorted in ascending order (may contain 
duplicates), you need to split them into several subsequences, where 
each subsequences consist of at least 3 consecutive integers. Return 
whether you can make such a split.

Example 1:

Input: [1,2,3,3,4,5] :  Output: True
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5

Example 2:
Input: [1,2,3,3,4,4,5,5] : Output: True
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
 

Example 3:
Input: [1,2,3,4,4,5]  :  Output: False

Note:
The length of the input is in range of [1, 10000]
*/
class _0659_SplitArrayIntoConsecutiveSubsequences {
public:
    bool isPossible(std::vector<int>& nums);
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
Given two integers n and k, you need to construct a list which contains 
n different positive integers ranging from 1 to n and obeys the following 
requirement:
Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, 
|a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.

If there are multiple answers, print any of them.

Input: n = 3, k = 1           :            Output: [1, 2, 3]
Input: n = 3, k = 2           :            Output: [1, 3, 2]
Note:
The n and k are in the range 1 <= k < n <= 104.
*/
class _0667_BeautifulArrangementII {
public:
    std::vector<int> constructArray(int n, int k);
};



/*
Implement a magic directory with buildDict, and search methods.
For the method buildDict, you'll be given a list of non-repetitive 
words to build a dictionary.
For the method search, you'll be given a word, and judge whether if you 
modify exactly one character into another character in this word, the 
modified word is in the dictionary you just built.

Example 1:
Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
Note:
You may assume that all the inputs are consist of lowercase letters a-z.
For contest purpose, the test data is rather small by now. You could think 
about highly efficient algorithm after the contest. Please remember to RESET 
your class variables declared in class MagicDictionary, as static/class 
variables are persisted across multiple test cases. Please see here for 
more details.
*/
class _0676_ImplementMagicDictionary {
public:
    _0676_ImplementMagicDictionary();
    void buildDict(std::vector<std::string> dict);
    bool search(std::string word);
private:
    std::unordered_map<int, std::unordered_set<std::string>> _dict;
};


/*
You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated 
through *, /, +, -, (, ) to get the value of 24.

Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24
Example 2:
Input: [1, 2, 1, 2]
Output: False
Note:
The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
*/
class _0679_24Games{
public:
    bool judgePoint24(std::vector<int>& nums);
private:
    bool valid(std::vector<int>& nums);
    bool valid(double a, double b, double c);
    bool valid(double a, double b); 
};

/*
Given two strings A and B, find the minimum number of times A has to be 
repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".
Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring 
of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/
class _0686_RepeatedStringMatch {
public:
    int repeatedStringMatch(std::string A, std::string B);
};

/*
Given a binary tree, find the length of the longest path where each 
node in the path has the same value. This path may or may not pass 
through the root.
The length of path between two nodes is represented by the number 
of edges between them.

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2
Note: The given binary tree has not more than 10000 nodes. The 
height of the tree is not more than 1000.
*/
class _0687_LongestUnivaluePath {
public:
    int longestUnivaluePath(TreeNode<int>* root);
private:
    int univaluePath(TreeNode<int>* root, int* ans);
};

/*
We have two special characters. The first character can be represented by 
one bit 0. The second character can be represented by two bits (10 or 11).
Now given a string represented by several bits. Return whether the last 
character must be a one-bit character or not. The given string will always 
end with a zero.


Input:  bits = [1, 0, 0]        :        Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.

Input:  bits = [1, 1, 1, 0]     :        Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
*/
class _0717_OneBitAndTwoBitsCharacters{
public:
    bool isOneBitCharacter(std::vector<int>& bits);
private:
    bool isOneBitCharacter(std::vector<int>& bits, int start, int end);
};

/*
Given a (singly) linked list with head node root, write a 
function to split the linked list into k consecutive linked 
list "parts".
The length of each part should be as equal as possible: no 
two parts should have a size differing by more than 1. This 
may lead to some parts being null.
The parts should be in order of occurrence in the input list, 
and parts occurring earlier should always have a size greater 
than or equal parts occurring later.
Return a List of ListNode's representing the linked list parts 
that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input:
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, 
root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation
 as a ListNode is [].
Example 2:
Input: 
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference
 at most 1, and earlier parts are a larger size than the later parts.
Note:

The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].
*/
class _0725_SplitLinkedListInParts {
public:
    std::vector<ListNode<int>*> splitListToParts(ListNode<int>* root, int k);
};


class _0729_MyCalendarI {
public:
    _0729_MyCalendarI();
    bool book(int start, int end);
private:
    std::vector<std::pair<int,int>> a;
    std::map<int, int> booked;              // use binary search:  |     [10        (20)]      |     [(15)    20]
    // floor:    largest entry whose key <= query key         |       [(12)   18]         |  [12    (18)]
    // ceiling:  smallest entry whose key > query key         |    floor.end > q.start    |     ceiling.start < q.end
    // Time complexity: O(nlogn)   Space complexity: O(n)
};

/*
We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents
its direction (positive meaning right, negative meaning left). Each asteroid moves
at the same speed. Find out the state of the asteroids after all collisions. If 
two asteroids meet, the smaller one will explode. If both are the same size, both 
will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input: asteroids = [5, 10, -5]           :      Output: [5, 10]

Example 2:
Input: asteroids = [8, -8]               :      Output: []

Example 3:
Input: asteroids = [10, 2, -5]           :      Output: [10]

Example 4:
Input: asteroids = [-2, -1, 1, 2]        :      Output: [-2, -1, 1, 2]
Explanation: 
The -2 and -1 are moving left, while the 1 and 2 are moving right.
Asteroids moving the same direction never meet, so no asteroids will meet each other.
*/
class _0735_AsteroidCollision {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids);
};

/*
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: 
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and 
wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move 
consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.
You are given a list of deadends dead ends, meaning if the lock displays any of these 
codes, the wheels of the lock will stop turning and you will be unable to open it.
Given a target representing the value of the wheels that will unlock the lock, return 
the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
Example 4:
Input: deadends = ["0000"], target = "8888"
Output: -1
*/

class _0752_OpenTheLock {
public:
    int openLock(std::vector<std::string>& deadends, std::string target);
    int bidirectionalBFS(std::vector<std::string>& deadends, std::string target);
private:
    std::vector<std::string> nextNeighborString(std::string& key);
};

/*
We are stacking blocks to form a pyramid. Each block has a color which is a 
one letter string. We are allowed to place any color block C on top of two 
adjacent blocks of colors A and B, if and only if ABC is an allowed triple.
We start with a bottom row of bottom, represented as a single string. We also
start with a list of allowed triples allowed. Each allowed triple is represented 
as a string of length 3. 

Return true if we can build the pyramid all the way to the top, otherwise false.

Input: bottom = "BCD", allowed = ["BCG", "CDE", "GEA", "FFF"]        :        Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  G   E
 / \ / \
B   C   D

We are allowed to place G on top of B and C because BCG is an allowed triple.
Similarly, we can place E on top of C and D, then A on top of G and E.

Input: bottom = "AABA", allowed = ["AAA", "AAB", "ABA", "ABB", "BAC"]       :      Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.

Note:

bottom will be a string with length in range [2, 8].
allowed will have length in range [0, 200].
Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
*/
class _0756_PyramidTransitionMatrix {
public:
    bool pyramidTransition(std::string bottom, std::vector<std::string>& allowed);
private:
    bool pyramidTransition(std::string bottom, int start, std::string res, std::unordered_map<std::string, std::unordered_set<char>>& Map);
};

/*
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move 
consists of either replacing one occurrence of "XL" with "LX", or replacing one 
occurrence of "RX" with "XR". Given the starting string start and the ending string 
end, return True if and only if there exists a sequence of moves to transform one
string to the other.

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
Note:

1 <= len(start) = len(end) <= 10000.
Both start and end will only consist of characters in {'L', 'R', 'X'}.
这道题由于理解错误，以为XL 和 LX 是可以互相变的， RX 和 XR 也是可以互相变的。
实际上，题目中给出的条件是 XL 只能单向变成 LX， 而 RX 只能单向变成 XR。
那么问题就变得简单了许多，这样想，如果只是单向变化，那么L在start中的位置相对于
end只能靠后，而 R 在start 中的位置相对于end只能靠前。换句话说，L 只能往前走，
而R 只能往后走。而且L, R 在两个字符串中的相对位置无法变化。
*/
class _0777_SwapAdjacentInLRString {
public:
    bool canTransform(const std::string& start, const std::string& end);
};


/*
Return the length of the shortest, non-empty, contiguous subarray of A 
with sum at least K.
If there is no non-empty subarray with sum at least K, return -1.

Input: A = [1], K = 1
Output: 1

Input: A = [1,2], K = 4
Output: -1

Input: A = [2,-1,2], K = 3
Output: 3

1 <= A.length <= 50000
-10 ^ 5 <= A[i] <= 10 ^ 5
1 <= K <= 10 ^ 9
这道题完全没有头绪，是抄答案的，关键点需要使用一个双向队列
*/
class _0862_ShortestSubarrayWithSumAtLeastK {
public:
    int shortestSubarray(std::vector<int>& A, int K);
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
Alex and Lee play a game with piles of stones. There are an even number 
of piles arranged in a row, and each pile has a positive integer number
of stones piles[i]. The objective of the game is to end with the most 
stones.  The total number of stones is odd, so there are no ties. Alex 
and Lee take turns, with Alex starting first.  Each turn, a player takes 
the entire pile of stones from either the beginning or the end of the row.  
This continues until there are no more piles left, at which point the 
person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex 
wins the game.

Input: [5,3,4,5]           :           Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
*/
class _0877_StoneGame {
private:
    std::vector<int> totStone;
    std::vector<std::vector<int>> alexMap;
    std::vector<std::vector<int>> leeMap;
public:
    bool stoneGame(std::vector<int>& piles);
    int AlexMax(std::vector<int>& piles, int start, int end);
    int LeeMax(std::vector<int>& piles, int start, int end);
};

/*
Implement FreqStack, a class which simulates the operation of a stack-like data structure.

FreqStack has two functions:

push(int x), which pushes an integer x onto the stack.
pop(), which removes and returns the most frequent element in the stack.
If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
 
Input: 
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
Output: [null,null,null,null,null,null,null,5,7,5,4]
Explanation:
After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].

pop() -> returns 4.
The stack becomes [5,7].
 

Note:

Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
The total number of FreqStack.push calls will not exceed 10000 in a single test case.
The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.
*/
class _0895_MaximumFrequencyStack {
private:
    // Copy inspired by the solution
    std::map<int, int> freq; // A Map from x to the number of frequency occurences of x
    std::map<int, std::stack<int>> group; // group data according to their frequency. If push 5, 5 -->  group[1]->5,  group[2]->5 respectively.
    int maxFreq; // Keep the maximum frequency
public:
    _0895_MaximumFrequencyStack();
    void push(int x);
    int pop();
};


/*
In an election, the i-th vote was cast for persons[i] at time times[i].
Now, we would like to implement the following query function: 
TopVotedCandidate.q(int t) will return the number of the person that was 
leading the election at time t.  
Votes cast at time t will count towards our query.  In the case of a 
tie, the most recent vote (among tied candidates) wins.

Input: ["TopVotedCandidate","q","q","q","q","q","q"], 
[[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
Output: [null,0,1,1,0,0,1]
Explanation: 
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.
 
1 <= persons.length = times.length <= 5000
0 <= persons[i] <= persons.length
times is a strictly increasing array with all elements in [0, 10^9].
TopVotedCandidate.q is called at most 10000 times per test case.
TopVotedCandidate.q(int t) is always called with t >= times[0].
*/
class _0911_OnlineElection {
public:
    _0911_OnlineElection(std::vector<int>& persons, std::vector<int>& times);
    int q(int t);
private:
    std::map<int, int> Map;
};

/*
Given an array of integers nums, sort the array in ascending order.
*/
class _0912_SortAnArray {
public:
    std::vector<int> sortArray(std::vector<int>& nums);
private:
    void sortArray(std::vector<int>& nums, int start, int end);
    void merge(std::vector<int>& nums, int start, int end, int mid);
};

/*
Given two sequences pushed and popped with distinct values, return true 
if and only if this could have been the result of a sequence of push and 
pop operations on an initially empty stack.

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
*/
class _0946_ValidateStackSequences {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped);
};


/*
You are installing a billboard and want it to have the largest 
height. The billboard will have two steel supports, one on each 
side. Each steel support must be an equal height. You have a 
collection of rods which can be welded together. For example, if 
you have rods of lengths 1, 2, and 3, you can weld them together
to make a support of length 6.

Return the largest possible height of your billboard installation.
If you cannot support the billboard, return 0.

Input: [1,2,3,6]             :            Output: 6
Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.

Input: [1,2,3,4,5,6]         :            Output: 10
Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.

Input: [1,2]                 :            Output: 0
Explanation: The billboard cannot be supported, so we return 0.

这道题如果用Backtracing 比较直观但是会超时，数据的大小是 0 <= rods.length <= 20
每个rod 有三个情况， 0， 不选， 1， 放左边， 2 放右边。

这道题的解法仍然是动态规划，不过状态转移还是很难想出来的。
DP[n][i] --> 表示当用到n个柱子的时候，两边的差为 i 可以达到的最大公共高度
因此状态转移方程就是：

DP[n][i + h] = max(DP[n][i], DP[n-1][i]);           当用到n个柱子时把柱子放在高的那一边，公共高度跟用n-1个柱子一样，可是高度差变成了 i + h
DP[n][|i-h|] = max(DP[n][|i-h|], DP[n-1][i] + min(h, i)); // 如果把第n个柱子放在矮的那边，公共高度一定是增长了 min(i, h), 高度差就变成了 |i-h| 
因为不知道h大还是原先的i大。
因此，解为 DP[N][0]
*/
class _0956_TallestBillboard {
public:
    int tallestBillboard(std::vector<int>& rods);
};


/*
Given a binary tree, determine if it is a complete binary tree.
Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely 
filled, and all nodes in the last level are as far left as possible. It can have 
between 1 and 2h nodes inclusive at the last level h.
*/
class _0958_CheckCompletenessOfABinaryTree {
public:
    bool siCompleteTree(TreeNode<int>* root);
};

/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in 
sorted order. Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with 
a <= x <= b. The intersection of two closed intervals is a set of real numbers that is 
either empty, or can be represented as a closed interval.  For example, the intersection 
of [1, 3] and [2, 4] is [2, 3].)

Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not 
arrays or lists.
*/
class _0986_IntervalListIntersections {
public:
    std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B);
};

/*
Given a 2D array A, each cell is 0 (representing sea) or 1 (representing 
land) A move consists of walking from one land square 4-directionally to 
another land square, or off the boundary of the grid. Return the number of 
land squares in the grid for which we cannot walk off the boundary of the 
grid in any number of moves. 

Example 1:

Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: 
There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed 
because its on the boundary.
Example 2:

Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: 
All 1s are either on the boundary or can reach the boundary.

Note:

1 <= A.length <= 500
1 <= A[i].length <= 500
0 <= A[i][j] <= 1
All rows have the same size.
*/
class _1020_NumberOfEnclaves {
public:
    int numEnclaves(std::vector<std::vector<int>>& A);

private:
    void DFS(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& visited, int i, int j);
};

/*
A query word matches a given pattern if we can insert lowercase letters to 
the pattern word so that it equals the query. (We may insert each character 
at any position, and may insert 0 characters.)
Given a list of queries, and a pattern, return an answer list of booleans, 
where answer[i] is true if and only if queries[i] matches the pattern. 


Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: 
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: 
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".

Note:

1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
All strings consists only of lower and upper case English letters.
*/
class _1023_CamelcaseMatching {
public:
    std::vector<bool> camelMatch(std::vector<std::string>& queries, std::string pattern);
    bool canMatch_prefixMatchingBased(std::string query, std::string pattern);
    bool canMatch_regularExpressionBased(std::string query, std::string pattern);
private:
    std::vector<bool> prefixMatchingBased(std::vector<std::string>& queries, std::string pattern);
    std::vector<bool> regularExpressionBased(std::vector<std::string>& queries, std::string pattern);
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

class _1027_LongestArithmeticSequence{
    public:
    // Copy from the solution.
    int longestArithSeqLength(std::vector<int>& A);
};

/*
There are 2N people a company is planning to interview. The cost of flying 
the i-th person to city A is costs[i][0], and the cost of flying the i-th 
person to city B is costs[i][1].
Return the minimum cost to fly every person to a city such that exactly N 
people arrive in each city.

Input: [[10,20],[30,200],[400,50],[30,20]]          :         Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
*/
// Inspired by the solution
class _1029_TwoCityScheduling {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& costs);
};

/*
We are given a matrix with R rows and C columns has cells with integer coordinates
(r, c), where 0 <= r < R and 0 <= c < C.
Additionally, we are given a cell in that matrix with coordinates (r0, c0).

Return the coordinates of all cells in the matrix, sorted by their distance from (r0, c0) 
from smallest distance to largest distance. Here, the distance between two cells (r1, c1) 
and (r2, c2) is the Manhattan distance, |r1 - r2| + |c1 - c2|.  (You may return the answer 
in any order that satisfies this condition.) 

Input: R = 1, C = 2, r0 = 0, c0 = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (r0, c0) to other cells are: [0,1]

Input: R = 2, C = 2, r0 = 0, c0 = 1
Output: [[0,1],[0,0],[1,1],[1,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.

Input: R = 2, C = 3, r0 = 1, c0 = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as 
[[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
*/
class _1030_MatrixCellsInDistanceOrder {
public:
    std::vector<std::vector<int>> allCellsDistOrder(int R, int C, int r0, int c0);
private:
    int ManhattonDis(int i, int j, int r0, int c0);
};


/*
We have a collection of rocks, each rock has a positive integer weight.
Each turn, we choose the two heaviest rocks and smash them together.  Suppose 
the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight 
y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 
0 if there are no stones left.)
*/
class _1046_LastStoneWeight {
public:
    int lastStoneWeight(std::vector<int>& stones);
};

/*
Given a string S of lowercase letters, a duplicate removal consists of 
choosing two adjacent and equal letters, and removing them.
We repeatedly make duplicate removals on S until we no longer can.
Return the final string after all such duplicate removals have been 
made.  It is guaranteed the answer is unique.

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are 
adjacent and equal, and this is the only possible move. The result 
of this move is that the string is "aaca", of which only "aa" is possible,
so the final string is "ca".

1 <= S.length <= 20000
S consists only of English lowercase letters.
*/
class _1047_RemoveAllAdjacentDuplicatesInString {
public:
    std::string removeDuplicates(std::string S);
};



/*
Return the lexicographically smallest subsequence of text that contains all the distinct characters of text exactly once.

Input: "cdadabcc"         :         Output: "adbc"
Input: "abcd"             :         Output: "abcd"
Input: "ecbacba"          :         Output: "eacb"
Input: "leetcode"         :         Output: "letcod"

1 <= text.length <= 1000
text consists of lowercase English letters.
*/
class _1081_SmallestSubsequenceOfDistinctCharacters {
public:
    std::string smallestSubsequenc(std::string text);
};

/* 1103. distribute candies to people:
We distribute some number of candies, to a row of n = num_people 
people in the following way:
We then give 1 candy to the first person, 2 candies to the second 
person, and so on until we give n candies to the last person.Then, 
we go back to the start of the row, giving n + 1 candies to the 
first person, n + 2 candies to the second person, and so on until 
we give 2 * n candies to the last person.
This process repeats (with us giving one more candy each time, and 
moving to the start of the row after we reach the end) until we run 
out of candies. The last person will receive all of our remaining 
candies (not necessarily one more than the previous gift).
Return an array (of length num_people and sum candies) that represents 
the final distribution of candies. 

Example 1:

Input: candies = 7, num_people = 4
Output: [1,2,3,1]
Explanation:
On the first turn, ans[0] += 1, and the array is [1,0,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0,0].
On the third turn, ans[2] += 3, and the array is [1,2,3,0].
On the fourth turn, ans[3] += 1 (because there is only one candy left), and the final array is [1,2,3,1].
Example 2:

Input: candies = 10, num_people = 3
Output: [5,2,3]
Explanation: 
On the first turn, ans[0] += 1, and the array is [1,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0].
On the third turn, ans[2] += 3, and the array is [1,2,3].
On the fourth turn, ans[0] += 4, and the final array is [5,2,3].
*/
class _1103_DistributeCandiesToPeople {
public:
    std::vector<int> distributeCandies(int candies, int num_people);
};

/*
We have a sequence of books: the i-th book has thickness books[i][0] 
and height books[i][1]. 
We want to place these books in order onto bookcase shelves that have 
total width shelf_width.
We choose some of the books to place on this shelf (such that the sum 
of their thickness is <= shelf_width), then build another level of 
shelf of the bookcase so that the total height of the bookcase has 
increased by the maximum height of the books we just put down. We repeat 
this process until there are no more books to place.

Note again that at each step of the above process, the order of the 
books we place is the same order as the given sequence of books. 
For example, if we have an ordered list of 5 books, we might place the 
first and second book onto the first shelf, the third book on the second 
shelf, and the fourth and fifth book on the last shelf.

Return the minimum possible height that the total bookshelf can be after 
placing shelves in this manner.

Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves are 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.

Constraints:
1 <= books.length <= 1000
1 <= books[i][0] <= shelf_width <= 1000
1 <= books[i][1] <= 1000
*/
class _1105_FillingBookcaseShelves {
public:
    int minHeightShelves(std::vector<std::vector<int>>& books, int shelf_width);
};


/*
Return the result of evaluating a given boolean expression, represented as a string.

An expression can either be:

"t", evaluating to True;
"f", evaluating to False;
"!(expr)", evaluating to the logical NOT of the inner expression expr;
"&(expr1,expr2,...)", evaluating to the logical AND of 2 or more inner expressions expr1, expr2, ...;
"|(expr1,expr2,...)", evaluating to the logical OR of 2 or more inner expressions expr1, expr2, ...
 

Example 1:

Input: expression = "!(f)"
Output: true
Example 2:

Input: expression = "|(f,t)"
Output: true
Example 3:

Input: expression = "&(t,f)"
Output: false
Example 4:

Input: expression = "|(&(t,f,t),!(t))"
Output: false
 

Constraints:

1 <= expression.length <= 20000
expression[i] consists of characters in {'(', ')', '&', '|', '!', 't', 'f', ','}.
expression is a valid expression representing a boolean, as given in the description.
*/
class _1106_ParsingABolleanExpression {
public:
    bool parseBoolExpr(std::string expression);
};


/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all 
elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are 
the same as in arr2.  Elements that don't appear in arr2 should be placed at 
the end of arr1 in ascending order.

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
 
Constraints:

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
Each arr2[i] is distinct.
Each arr2[i] is in arr1.
*/
class _1122_RelativeSortArray {
public:
    std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2);
};

/*
Given two arrays of integers with equal lengths, return the 
maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
where the maximum is taken over all 0 <= i, j < arr1.length. 

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]           :   Output: 13
Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4] :   Output: 20

Constraints:
2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6
*/
class _1131_MaximumOfAbsoluteValueExpression {
public:
    int maxAbsValExpr(std::vector<int>& arr1, std::vector<int>& arr2);
};


/*
Two players play a turn based game on a binary tree.  We are given the root
of this binary tree, and the number of nodes n in the tree. n is odd, and 
each node has a distinct value from 1 to n.
Initially, the first player names a value x with 1 <= x <= n, and the second 
player names a value y with 1 <= y <= n and y != x. The first player colors 
the node with value x red, and the second player colors the node with value 
y blue.
Then, the players take turns starting with the first player. In each turn, 
that player chooses a node of their color (red if player 1, blue if player 2) 
and colors an uncolored neighbor of the chosen node (either the left child,
 right child, or parent of the chosen node.)
If (and only if) a player cannot choose such a node in this way, they must 
pass their turn. If both players pass their turn, the game ends, and the 
winner is the player that colored more nodes.

You are the second player.  If it is possible to choose such a y to ensure 
you win the game, return true.  If it is not possible, return false.
这道题赢的条件是谁拿到更多的节点而不是节点的和。当时看到这个题有点懵，以为是算节点
的和。
*/
class _1145_BinaryTreeColoringGame {
public:
    bool btreeGameWinningMove(TreeNode<int>* root, int n, int x);
private:
    int l_;
    int r_;
    int nodes(TreeNode<int>* root, int x);
};

/*
Let's define a function f(s) over a non-empty string s, which calculates the frequency 
of the smallest character in s. For example, if s = "dcce" then f(s) = 2 because the 
smallest character is "c" and its frequency is 2.
Now, given string arrays queries and words, return an integer array answer, where each 
answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words. 

Input: queries = ["cbd"], words = ["zaaaz"]      :      Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").

Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]   :   Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").

Constraints:

1 <= queries.length <= 2000
1 <= words.length <= 2000
1 <= queries[i].length, words[i].length <= 10
queries[i][j], words[i][j] are English lowercase letters.
*/
class _1170_CompareStringByFrequencyOfTheSmallestCharacter {
public:
    std::vector<int> numSmallerByFrequency(std::vector<std::string>& queries, std::vector<std::string>& words);
    
};



/*
Return the number of permutations of 1 to n so that prime numbers are at prime 
indices (1-indexed.) (Recall that an integer is prime if and only if it is greater 
than 1, and cannot be written as a product of two positive integers both smaller than it.)
Since the answer may be large, return the answer modulo 10^9 + 7.

Input: n = 5             :              Output: 12
Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.

Input: n = 100           :              Output: 682289015
*/
class _1175_PrimeArrangements {
public:
    constexpr static auto MOD = static_cast<int>(1e9+7); // Use C++11 constexpr
    int numPrimeArrangements(int n, int primes, long long ans);
private:
    bool isPrime(int n);
};

/*
Given a string text, you want to use the characters of text to form as many instances 
of the word "balloon" as possible.
You can use each character in text at most once. Return the maximum number of instances 
that can be formed.

Input: text = "nlaebolko"              :             Output: 1
Input: text = "loonbalxballpoon"       :             Output: 2
Input: text = "leetcode"               :             Output: 0
*/
class _1189_MaximumNumberOfBalloons {
public:
    int maxNumberOfBalloons(std::string text);
    bool updateBallon(std::vector<int>& map);
};

/*
You are given a string s that consists of lower case English letters and brackets. 
Reverse the strings in each pair of matching parentheses, starting from the innermost 
one. Your result should not contain any brackets.

Input: s = "(abcd)"                    :         Output: "dcba"
Input: s = "(u(love)i)"                :         Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Input: s = "(ed(et(oc))el)"            :         Output: "leetcode"
Input: s = "a(bcdefghijkl(mno)p)q"     :         Output: "apmnolkjihgfedcbq"

Constraints:
0 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It's guaranteed that all parentheses are balanced.
*/
class _1190_ReverseSubstringsBetweenEachPairOfParentheses {
public:
    std::string reverseParentheses(std::string s);
};


/*
Given an array of integers arr, write a function that returns true if and only if the 
number of occurrences of each value in the array is unique.

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the 
same number of occurrences.

Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
*/
class _1207_UniqueNumberOfOccurances {
public:
    bool uniqueOccurrences(std::vector<int>& arr);
};


/*
Hint: 祖玛
Given a string s, a k duplicate removal consists of choosing k adjacent and 
equal letters from s and removing them causing the left and the right side 
of the deleted substring to concatenate together.
We repeatedly make k duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made.
It is guaranteed that the answer is unique.

Input: s = "abcd", k = 2                  :                Output: "abcd"
Input: s = "deeedbbcccbdaa", k = 3        :                Output: "aa"
Input: s = "pbbcggttciiippooaais", k = 2  :                Output: "ps"

Constraints:

1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.
*/
class _1209_RemoveAllAdjacentDuplicatesInStringII {
public:
    std::string removeDuplicates(std::string s, int k);
};


/*
Given an integer array arr and an integer difference, return the length of the 
longest subsequence in arr which is an arithmetic sequence such that the 
difference between adjacent elements in the subsequence equals difference.

Example 1:
Input: arr = [1,2,3,4], difference = 1
Output: 4
Explanation: The longest arithmetic subsequence is [1,2,3,4].

Example 2:
Input: arr = [1,3,5,7], difference = 1
Output: 1
Explanation: The longest arithmetic subsequence is any single element.

Example 3:
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
 
Constraints:

1 <= arr.length <= 10^5
-10^4 <= arr[i], difference <= 10^4
*/
class _1218_LongestArithmeticSubsequenceOfGivenDifference {
public:
    int longestSubsequence(std::vector<int>& arr, int difference);
};




class _1221_SplitAStringInBalancedStrings {
public:
    int balancedStringSplit(std::string s);
};


/*
n passengers board an airplane with exactly n seats. The first passenger has 
lost the ticket and picks a seat randomly. But after that, the rest of 
passengers will:

Take their own seat if it is still available, 
Pick other seats randomly when they find their seat occupied 
What is the probability that the n-th person can get his own seat?

Input: n = 1                   :             Output: 1.00000
Input: n = 2                   ：            Output: 0.50000
Explanation: The second person has a probability of 0.5 to get the second 
seat (when first person gets the first seat).
*/
class _1227_AirplaneSeatAssignmentProbability {
    public:
        double nthPersionGetsNthSeat(int n);

};



} // namespace LeetCode





















































namespace LintCode {

    /*
    Write a function that add two numbers A and B. There is no need to read data 
    from standard input stream. Both parameters are given in function aplusb, your 
    job is to calculate the sum and return it.
    
    Have you met this question in a real interview?  
    Clarification
    Are a and b both 32-bit integers? Yes.
    
    Can I use bit operation? Sure you can.
    
    Input:  a = 1, b = 2
    Output: 3	
    Explanation: return the result of a + b.
    
    Example 2:
    Input:  a = -1, b = 1
    Output: 0	
    Explanation: return the result of a + b.
    Challenge
    Of course you can just return a + b to get accepted. But Can you challenge not 
    do it like that?(You should not use + or any arithmetic operators.)
    */    
    class _0001_APlusBProblem {
        public:
            int aplusb(int a, int b);
    };

    /*
    Write an algorithm which computes the number of trailing zeros in n factorial. 
    
    Example 1:
	Input:  11         :        Output: 2	
	Explanation: 
	11! = 39916800, so the output should be 2

	Input:  5          :        Output: 1	
	Explanation: 
	5! = 120, so the output should be 1.

    Challenge   O(log N) time
    还没有理解为什么，可以用笔一点一点照着solution写出来看看
    */
    class _0002_TrailingZeros {
        public:
            long long trailingZeros(long long n);
    };

/*
Ugly number is a number that only have prime factors 2, 3 and 5.

Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

Note that 1 is typically treated as an ugly number.

Have you met this question in a real interview?  
Example
Example 1:

Input: 9
Output: 10
Example 2:

Input: 1
Output: 1
Challenge
O(n log n) or O(n) time.
*/
class _0004_UglyNumberII {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n);
};

/*
Merge two given sorted ascending integer array A and B into a new sorted integer array.
Have you met this question in a real interview?  

Input:  A=[1], B=[1]        :        Output: [1,1]	
Input:  A=[1,2,3,4], B=[2,4,5,6]  :  Output: [1,2,2,3,4,4,5,6]	

How can you optimize your algorithm if one array is very large and the other is very small?
Related Problems
*/
class _0006_MergeTwoSortedArrays {
public:
    std::vector<int> mergeSortedArray(std::vector<int> &A, std::vector<int> &B);
};



    /*
    Description
    In a 2D array grid, each value grid[i][j] represents the height of a building 
    located there. We are allowed to increase the height of any number of buildings, 
    by any amount (the amounts can be different for different buildings). Height 
    0 is considered to be a building as well.
    
    At the end, the "skyline" when viewed from all four directions of the grid, i.e. 
    west, east, north, and south, must be the same as the skyline of the original 
    grid. A city's skyline is the outer contour of the rectangles formed by all the 
    buildings when viewed from a distance. See the following example.
    
    What is the maximum total sum that the height of the buildings can be increased?
    1 < grid.length = grid[0].length <= 50.
    All heights grid[i][j] are in the range [0, 100].
    All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.
    Have you met this question in a real interview?  
    
    Example
    Input: 
    [   [3,0,8,4],
        [2,4,5,7],
        [9,2,6,3],
        [0,3,1,0] ]
        
    Output: 35
    Explanation: 
        The skyline viewed from north or south is: [9, 4, 8, 7]
        The skyline viewed from west or right is: [8, 7, 9, 3]
        The grid after increasing the height of buildings without affecting skylines is:
        [ [8,4,8,7],
          [7,4,7,7],
          [9,4,8,7],
          [3,3,3,3] ]
    */
    class _1010_MaxIncreaseToKeepCitySkyline {
        public:
            int maxIncreaseKeepingSkyline(std::vector<std::vector<int>> &grid);
    };

    class _1207_UniqueNumberOfOccurances {
        public:
            bool uniqueOccurrences(std::vector<int>& arr);
    };
    
    /* Description
    You're given strings J representing the types of stones that are jewels, and S 
    representing the stones you have. Each character in S is a type of stone you have. 
    You want to know how many of the stones you have are also jewels.
    
    The letters in J are guaranteed distinct, and all characters in J and S are letters. 
    Letters are case sensitive, so "a" is considered a different type of stone from "A".
    S and J will consist of letters and have length at most 50.
    
    The characters in J are distinct.
    Example
    Example 1:
    Input: J = "aA", S = "aAAbbbb"
    
    Output: 3
    Example 2:
    Input: J = "z", S = "ZZ"
    Output: 0
    */
    class _1038_JewelsAndStones{
        public:
            int numJewelInStones(std::string& J, std::string& S);
    };

    /*
    Initially, there is a Robot at position (0, 0). Given a 
    sequence of its moves, judge if this robot makes a circle, 
    which means it moves back to the original place finally.
    The move sequence is represented by a string. And each move 
    is represent by a character. The valid robot moves are R 
    (Right), L (Left), U (Up) and D (down). The output should be 
    true or false representing whether the robot makes a circle.

    Example 1: Input: "UD"      Output: true
    Example 2: Input: "LL"      Output: false
    */
    class _1104_JudgeRouteCircle {
        public:
            bool judgeCircle(std::string& moves);
    };

    /*
    Given a non-empty binary tree, return the average value of the nodes on each level 
    in the form of an array. The range of node's value is in the range of 32-bit signed 
    integer. 
    Example
    Example 1:
    Input:
        3
       / \'
      9  20
        /  \
       15   7
    Output: [3, 14.5, 11]
    */
    class _1115_AverageOfLevelsInBinaryTree{
        public:
            std::vector<double> averageOfLevels(TreeNode<int>* root);
    };

    /*
    Given two binary trees and imagine that when you put one of them 
    to cover the other, some nodes of the two trees are overlapped 
    while the others are not.
    
    You need to merge them into a new binary tree. The merge rule is 
    that if two nodes overlap, then sum node values up as the new 
    value of the merged node. Otherwise, the NOT null node will be 
    used as the node of new tree.
    
    The merging process must start from the root nodes of both trees.
    
    Example
    Example1
    Input: 
    {1,3,2,5}
    {2,1,3,#,4,#,7}
    Output:
    {3,4,5,5,4,#,7}
    Explanation:
    	Tree 1                     Tree 2                  
                  1                         2                             
                 / \                       / \                            
                3   2                     1   3                        
               /                           \   \                     
              5                             4   7                  
    Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
    */

    class _1126_MergeTwoBinaryTrees{
        public:
            TreeNode<int> * mergeTrees(TreeNode<int> * t1, TreeNode<int> * t2);
    };

    /*
    Given a complete binary tree, count the number of nodes.
    */
    class _1317_CountCompleteTreeNodes {
        public:
            int countNodes(TreeNode<int>* root);
    };

    /*
    Write a function that takes an unsigned integer and returns the number of ’1' bits the 
    corresponding binary number has (also known as the Hamming weight).
    
    Input：n = 11
    Output：3
    Explanation：11(10) = 1011(2), so return 3
    */
    class _1332_NumberOf1Bits{
        public:
            int hammingWeight(unsigned int n);
    };

    /*
    Given a non-negative integer numRows, generate the first numRows of 
    Pascal's triangle.
    In Pascal's triangle, each number is the sum of the two numbers 
    directly above it.
    
    Input: 5
    Output:
    [
    [1],
    [1,1],
    [1,2,1],
    [1,3,3,1],
    [1,4,6,4,1]]
    
    Input: 3
    Output:
    [
    [1],
    [1,1],
    [1,2,1]
    ]
    */
    class _1355_PascalsTriangle{
        public:
            std::vector<std::vector<int>> generate(int numRows);
    };

    /*
    Description: We have a two dimensional matrix A where
    each value is 0 or 1. A move consists of choosing any 
    row or column, and toggling each value in that row or
    column: changing all 0s to 1s, and all 1s to 0s.
    After making any number of moves, every row of this 
    matrix is interpreted as a binary number, and the 
    score of the matrix is the sum of these numbers.
    
    Return the highest possible score.
    1 <= A.length <= 20
    1 <= A[0].length <= 20
    A[i][j] is 0 or 1.
    
    
    Example 1:
    Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
    Output: 39
    
    Explanation:
    Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
    0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

    Example 2:
    Input: [[1,1],[0,0],[1,0],[1,0],[1,1]]
    Output: 13
    Explanation:
    Toggled to [[1,1],[1,1],[1,0],[1,0],[1,1]].
    0b11 + 0b11 + 0b10 + ob10 + ob11 = 3 + 3 + 2 + 2 + 3= 13
    */
    class _1508_ScoreAfterFlippingMatrix{
        public:
            int matrixScore(std::vector<std::vector<int>>& A);

        private:
            void flipRow(std::vector<std::vector<int>>& A, int rowIdx);
            void flipCol(std::vector<std::vector<int>>& A, int colIdx);
            int countOnes(std::vector<std::vector<int>>& A, int colIdx);
            int toNum(std::vector<int>& v);
    };


    /*
    There is a special square room with mirrors on each of the four walls. 
    Except for the southwest corner, there are receptors on each of the 
    remaining corners, numbered 0, 1, and 2.
    
    The square room has walls of length p, and a laser ray from the southwest 
    corner first meets the east wall at a distance q from the 0th receptor.
    
    Return the number of the receptor that the ray meets first. (It is 
    guaranteed that the ray will meet a receptor eventually.)

    Input: p = 2, q = 1
    Output: 2
    Explanation: The ray meets receptor 2 the first time it gets reflected 
    back to the left wall.

    Input: p = 3, q = 1
    Output: 1
    Explanation: The ray meets receptor 1 the first time it gets reflected 
    back to the left wall.
    这道题完全抄答案的
    */
    class _1511_MirrorReflection {
        public:
            int mirrorReflection(int p, int q);
        private:
            int gcd(int p, int q);

    };

    /*
    Implement function ToLowerCase() that has a string parameter str, 
    and returns the same string in lowercase.
    */
    class _1535_ToLowerCase {
        public:
            std::string toLowerCase(std::string &str);
    };

    /*
    You have a list of words and a pattern, and you want to know which words
    in words matches the pattern. A word matches the pattern if there exists 
    a permutation of letters p so that after replacing every letter x in the 
    pattern with p(x), we get the desired word.
    (Recall that a permutation of letters is a bijection from letters to letters: 
    every letter maps to another letter, and no two letters map to the same letter.)
    
    Return a list of the words in words that match the given pattern.
    You may return the answer in any order.
    
    1 <= words.length <= 501<=words.length<=50
    1 <= pattern.length = words[i].length <= 201<=pattern.length=words[i].length<=20
    
    Example
    Example 1:
    Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
    Output: ["aqq","mee"]
    
    Explanation: 
    "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
    "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
    since a and b map to the same letter.
    
    Example 2:
    Input: words = ["a","b","c"], pattern = "a"
    Output: ["a","b","c"]
    */
    class _1592_FindAndReplacePattern {
        public:
            std::vector<std::string> findAndReplacePattern(std::vector<std::string> &words, std::string &pattern);
        private:
            bool samePattern(std::string& A, std::string& B);
    };
}