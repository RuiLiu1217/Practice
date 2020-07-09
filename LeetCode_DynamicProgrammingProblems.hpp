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




}
#endif