#ifndef LEETCODE_DYNAMICPROGRAMMINGPROBLEMS_HPP
#define LEETCODE_DYNAMICPROGRAMMINGPROBLEMS_HPP
#include <vector>
#include <string>
namespace LC {
/* 
TODO: Copy from the answer
Tag: dynamic programming, string matching
Given an input string (s) and a pattern (p), implement 
regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not 
partial).

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, 
and characters like . or *.

Input:  s = "aa"       :       p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Input:  s = "aa"       :       p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Input:  s = "ab"       :       p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Input:  s = "aab"      :       p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Input:  s = "mississippi"    :    p = "mis*is*p*."
Output: false
*/
class _0010_RegularExpressionMatching {
public:
    bool isMatch(std::string s, std::string p);
};


/*
Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
*/
class _0062_UniquePaths {
public:
    int uniquePaths(int m, int n);
};



/*
A robot is located at the top-left corner of a m x n 
grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any 
point in time. The robot is trying to reach the 
bottom-right corner of the grid (marked 'Finish' in 
the diagram below).

Now consider if some obstacles are added to the grids. 
How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 
respectively in the grid.

Note: m and n will be at most 100.

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/
class _0063_UniquePathsII {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);
};



/*
Tag: dynamic programming
64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from 
top left to bottom right which minimizes the sum of all numbers along 
its path.
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


/*
Tag: dynamic programming, string
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
*/
class _0097_InterleavingString {
public:
    bool isInterleav(std::string s1, std::string s2, std::string s3);
};


/*
Tag: Hash, dynamic programming
Todo
Given an unsorted array of integers, find the length of the 
longest consecutive elements sequence.
Your algorithm should run in O(n) complexity.

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/
class _0128_LongestConsecutiveSequence {
public:
    int longestConsecutive(std::vector<int>& nums);
};


/*
You are a professional robber planning to rob houses along 
a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them 
is that adjacent houses have security system connected and 
it will automatically contact the police if two adjacent 
houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
*/
class _0198_HouseRobber {
public:
    int rob(std::vector<int>& nums);
};

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
Tag: dynamic programming
Google
TODO: State Transition Equation
Given a 2D binary matrix filled with 0's and 1's, find the largest 
square containing only 1's and return its area.

Input: 
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/
class _0221_MaximalSquare {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix);
};

}
#endif