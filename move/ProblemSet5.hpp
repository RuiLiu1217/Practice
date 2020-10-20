#ifndef PROBLEM_SET5_HPP
#define PROBLEM_SET5_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"

namespace LeetCode {
/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
*/
class _0501_FindModeInBinarySearchTree {
public:
    std::vector<int> findMode(TreeNode<int>* root);
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
509. Fibonacci Number
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci 
sequence, such that each number is the sum of the two preceding ones, starting from 
0 and 1. That is,
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).

Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
*/
class _0509_FibonacciNumber {
public:
    int fib(int N);
};


/*
You are given coins of different denominations and a total amount of money. 
Write a function to compute the number of combinations that make up that 
amount. You may assume that you have infinite number of each kind of coin.

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Input: amount = 10, coins = [10] 
Output: 1

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
*/
class _0518_CoinChange2 {
public:
    int change(int amount, std::vector<int>& coins);
};

class _0519_RandomFlipMatrix {
private:
    int M;
    int N;
    int len;
    std::vector<int> index;    
public:
    _0519_RandomFlipMatrix(int n_rows, int n_cols);
    std::vector<int> flip();
    void reset();

};

/*
Given a list of non-negative numbers and a target integer k, 
write a function to check if the array has a continuous subarray 
of size at least 2 that sums up to a multiple of k, that is, 
sums up to n*k where n is also an integer.

Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
Example 2:

Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.

Note:

The length of the array won't exceed 10,000.
You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
*/
class _0523_ContinuousSubarraySum {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k);
};

/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/
class _0525_ContiguousArray {
public:
    int findMaxLength(std::vector<int>& nums);
};


/*
   Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array 
   that is constructed by these N numbers successfully if one of the following is true for
   the ith position (1 <= i <= N) in this array:
   
   The number at the ith position is divisible by i.
   i is divisible by the number at the ith position.
   Now given N, how many beautiful arrangements can you construct?
   
   Example 1:
   Input: 2
   Output: 2
   Explanation:
   
   The first beautiful arrangement is [1, 2]:
   
   Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
   Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
   
   The second beautiful arrangement is [2, 1]:
   
   Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
   Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
   这是一道典型的回溯问题
*/

class _0526_BeautifulArrangement {
public:
    int countArrangement(int N);
};

/*
Given a picture consisting of black and white pixels, and a positive integer N, find the 
number of black pixels located at some specific row R and column C that align with all the following rules:

Row R and column C both contain exactly N black pixels.
For all rows that have a black pixel at column C, they should be exactly the same as row R
The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

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

Note:
The range of width and height of the input 2D array is [1,200].
*/
class _0533_LonelyPixelII {
public:
    int findBlackPixel(std::vector<std::vector<char>>& picture, int N);
};
/*
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as 
https://leetcode.com/problems/design-tinyurl and it returns a short URL 
such as http://tinyurl.com/4e9iAk.
Design the encode and decode methods for the TinyURL service. There is no 
restriction on how your encode/decode algorithm should work. You just need 
to ensure that a URL can be encoded to a tiny URL and the tiny URL can be 
decoded to the original URL.
*/
class _0535_EncodeAndDecodeTinyURL {
public:
    // Encodes a URL to a shortened URL
    std::string encode(std::string longUrl);

    // Decodes a shortened URL to its original URL
    std::string decode(std::string shortUrl);
};


/*
Tag: Tree
!!! Edge case and initial condtion is very easy to have errors !!!
Facebook 

Given a binary tree, you need to compute the length of the diameter 
of the tree. The diameter of a binary tree is the length of the 
longest path between any two nodes in a tree. This path may or may 
not pass through the root.

Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
Note: The length of path between two nodes is represented by the number 
of edges between them.
*/
class _0543_DiameterofBinaryTree {
private:
    int res;
    int depth(TreeNode<int>* root);
public:
    int diameterOfBinaryTree(TreeNode<int>* root);

};


/*
There is a brick wall in front of you. The wall is rectangular and has 
several rows of bricks. The bricks have the same height but different 
width. You want to draw a vertical line from the top to the bottom and 
cross the least bricks.
The brick wall is represented by a list of rows. Each row is a list of 
integers representing the width of each brick in this row from left to right.
If your line go through the edge of a brick, then the brick is not 
considered as crossed. You need to find out how to draw the line to cross 
the least bricks and return the number of crossed bricks.
You cannot draw a line just along one of the two vertical edges of the 
wall, in which case the line will obviously cross no bricks.

Input: [[1,2,2,1],
        [3,1,2],
        [1,3,2],
        [2,4],
        [3,1,2],
        [1,3,1,1]]
Output: 2

Note:
The width sum of bricks in different rows are the same and won't exceed 
INT_MAX. The number of bricks in each row is in range [1,10,000]. The height 
of wall is in range [1,10,000]. Total number of bricks of the wall won't 
exceed 20,000.
*/
class _0554_BrickWall {
public:
    int leastBricks(std::vector<std::vector<int>>& wall);
};


/*
Given an integer array with even length, where different numbers in this array represent 
different kinds of candies. Each number means one candy of the corresponding kind. You 
need to distribute these candies equally in number to brother and sister. Return the 
maximum number of kinds of candies the sister could gain.

Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too.
The sister has three different kinds of candies.
Example 2:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1].
The sister has two different kinds of candies, the brother has only one kind of candies.
Note:

The length of the given array is in range [2, 10,000], and will be even.
The number in given array is in range [-100,000, 100,000].
*/
class _0575_DistributeCandies {
public:
    int distributeCandies(std::vector<int>& candies);
};

/*
Given an m * n matrix M initialized with all 0's and several update operations.
Operations are represented by a 2D array, and each operation is represented by 
an array with two positive integers a and b, which means M[i][j] should be added 
by one for all 0 <= i < a and 0 <= j < b.

You need to count and return the number of maximum integers in the matrix after performing all the operations.

Example 1:
Input: 
m = 3, n = 3
operations = [[2,2],[3,3]]
Output: 4
Explanation: 
Initially, M = 
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]

After performing [2,2], M = 
[[1, 1, 0],
 [1, 1, 0],
 [0, 0, 0]]

After performing [3,3], M = 
[[2, 2, 1],
 [2, 2, 1],
 [1, 1, 1]]

So the maximum integer in M is 2, and there are four of it in M. So return 4.
Note:
The range of m and n is [1,40000].
The range of a is [1,m], and the range of b is [1,n].
The range of operations size won't exceed 10,000.
*/
class _0598_RangeAdditionII {
public:
    int maxCount(int m, int n, std::vector<std::vector<int>>& ops);
};


}

#endif