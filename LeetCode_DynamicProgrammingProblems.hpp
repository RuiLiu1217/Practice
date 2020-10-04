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
Tag: Dynamic Programming, backtracking (TLE)

Facebook

Given a non-empty string s and a dictionary wordDict containing a list of non-empty 
words, determine if s can be segmented into a space-separated sequence of one or 
more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/
class _0139_WordBreak {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict);
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


/*
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:  
1 is typically treated as an ugly number.
n does not exceed 1690.
*/
class _0264_UglyNumberII {
public:
    int nthUglyNumber(int n);
};

/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it 
represented by array nums. You are asked to burst all the balloons. If the you burst 
balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right 
are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Input: [3,1,5,8]
Output: 167 

Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/
class _0312_BurstBalloons {
public:
    int maxCoins(std::vector<int>& nums);

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
    int coinChange(std::vector<int>& coins, int amount); //! This is hard to understand
    int coinChangeDP(std::vector<int>& coins, int amount);
private:
    void coinChange(const std::vector<int>& coins, int s, int amount, int count, int& ans);
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
We are playing the Guessing Game. The game will work as follows:

I pick a number between 1 and n.
You guess a number.
If you guess the right number, you win the game.
If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.

Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.
Example 2:

Input: n = 1
Output: 0
Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.
Example 3:

Input: n = 2
Output: 1
Explanation: There are two possible numbers, 1 and 2.
- Guess 1.
    - If this is my number, your total is $0. Otherwise, you pay $1.
    - If my number is higher, it must be 2. Guess 2. Your total is $1.
The worst case is that you pay $1.
 

Constraints:
1 <= n <= 200

*/
class _0375_GuessNumberHigherOrLowerII {
public:
    int getMoneyAmount(int n);
};

/*
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.
*/
class _0472_ConcatenatedWords {
public:
    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words);
};


/*
You are given n pairs of numbers. In every pair, the first number is always 
smaller than the second number.
Now, we define a pair (c, d) can follow another pair (a, b) if and only if 
b < c. Chain of pairs can be formed in this fashion.
Given a set of pairs, find the length longest chain which can be formed. You 
needn't use up all the given pairs. You can select pairs in any order.

Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].
*/
class _0646_MaximumLengthOfPairChain {
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs);
};


/*
On an NxN chessboard, a knight starts at the r-th row and c-th 
column and attempts to make exactly K moves. The rows and columns 
are 0 indexed, so the top-left square is (0, 0), and the 
bottom-right square is (N-1, N-1).
A chess knight has 8 possible moves it can make, as illustrated 
below. Each move is two squares in a cardinal direction, then one 
square in an orthogonal direction.

Each time the knight is to move, it chooses one of eight possible 
moves uniformly at random (even if the piece would go off the 
chessboard) and moves there.
The knight continues moving until it has made exactly K moves or 
has moved off the chessboard. Return the probability that the knight 
remains on the board after it has stopped moving.

Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep 
the knight on the board. From each of those positions, there are also 
two moves that will keep the knight on the board. The total probability 
the knight stays on the board is 0.0625.

Note:
N will be between 1 and 25.
K will be between 0 and 100.
The knight always initially starts on the board.
*/
class _0688_KnightProbabilityInChessboard {
public:
    double knightProbability(int N, int K, int r, int c);
};

/*
Given the integer n representing the number of courses at some university labeled from 1 to n, 
and the array dependencies where dependencies[i] = [xi, yi]  represents a prerequisite relationship, 
that is, the course xi must be taken before the course yi.  Also, you are given the integer k.
In one semester you can take at most k courses as long as you have taken all the prerequisites 
for the courses you are taking.
Return the minimum number of semesters to take all courses. It is guaranteed that you can take all 
courses in some way. 

Example 1:
Input: n = 4, dependencies = [[2,1],[3,1],[1,4]], k = 2
Output: 3 
Explanation: The figure above represents the given graph. In this case we can take courses 2 and 3 
in the first semester, then take course 1 in the second semester and finally take course 4 in the 
third semester.

Example 2:
Input: n = 5, dependencies = [[2,1],[3,1],[4,1],[1,5]], k = 2
Output: 4 
Explanation: The figure above represents the given graph. In this case one optimal way to take all 
courses is: take courses 2 and 3 in the first semester and take course 4 in the second semester, 
then take course 1 in the third semester and finally take course 5 in the fourth semester.
Example 3:

Input: n = 11, dependencies = [], k = 2
Output: 6

Constraints:

1 <= n <= 15
1 <= k <= n
0 <= dependencies.length <= n * (n-1) / 2
dependencies[i].length == 2
1 <= xi, yi <= n
xi != yi
All prerequisite relationships are distinct, that is, dependencies[i] != dependencies[j].
The given graph is a directed acyclic graph.
*/
class _1494_ParallelCoursesII {
public:
    int minNumberOfSemesters(int n, std::vector<std::vector<int>>& dependencies, int k);
};

}
#endif