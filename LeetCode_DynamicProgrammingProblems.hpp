#ifndef LEETCODE_DYNAMICPROGRAMMINGPROBLEMS_HPP
#define LEETCODE_DYNAMICPROGRAMMINGPROBLEMS_HPP
#include "HeaderFiles.hpp"

namespace LC {

    /*
Given a string containing just the characters '(' and ')', find the length of the 
longest valid (well-formed) parentheses substring.

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
! 这道题的动态规划解法超级难想。需要多看几次
! 这道题必须掌握
*/
class _0032_LongestValidParentheses {
public:
    int longestValidParentheses(std::string s) {
        std::vector<int> dp(s.size(), 0);
        int maxLen = 0;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == ')') {
                if(s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                }
            } else if(i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(') {
                dp[i] = dp[i-1] + (i - dp[i-1] >= 2 ? dp[i - dp[i-1] - 2] : 0) + 2;
            }
            maxLen = std::max(maxLen, dp[i]);
        }
        return maxLen;
    }
    /*
        这里借助栈来求解，需要定义个 start 变量来记录合法括号串的起始位置，遍历字符串，
        如果遇到左括号，则将当前下标压入栈，如果遇到右括号，如果当前栈为空，则将下一个坐
        标位置记录到 start，如果栈不为空，则将栈顶元素取出，此时若栈为空，则更新结果和 
        i - start + 1 中的较大值，否则更新结果和 i - st.top() 中的较大值
    */
    int longestValidParentheses_StackBased(std::string s) {
        int res = 0;
        int start = 0;
        const int n = s.size();
        std::stack<int> st;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                if(st.empty()) {
                    start = i + 1;
                } else {
                    st.pop();
                    res = st.empty() ? std::max(res, i - start + 1) : std::max(res, i - st.top());
                }
            }
        }
        return res;
    }

    /*
    不用额外空间的解法：使用了两个变量 left 和 right，分别用来记录到当前位置时左括号和右括号的出现次数，
    当遇到左括号时，left 自增1，右括号时 right 自增1。对于最长有效的括号的子串，一定是左括号等于右括号
    的情况，此时就可以更新结果 res 了，一旦右括号数量超过左括号数量了，说明当前位置不能组成合法括号子串，
    left 和 right 重置为0。但是对于这种情况 "(()" 时，在遍历结束时左右子括号数都不相等，此时没法更新结
    果 res，但其实正确答案是2，怎么处理这种情况呢？答案是再反向遍历一遍，采取类似的机制，稍有不同的是此时
    若 left 大于 right 了，则重置0，这样就可以 cover 所有的情况了，参见代码如下：
    */
    int longestValidParentheses_TwoPointers(std::string s) {
        int res = 0;
        int left = 0;
        int right = 0;
        const int n = s.size();

        for(int i = 0; i < n; ++i) {
            (s[i] == '(') ? ++left : ++right;
            if (left == right) res = std::max(res, 2 * right);
            else if (right > left) left = right = 0;
        }
        left = right = 0;
        for(int i = n - 1; i >= 0; --i) {
            (s[i] == '(') ? ++left : ++right;
            if (left == right) res = std::max(res, 2 * left);
            else if (left > right) left = right = 0;
        }
        return res;
    }
};


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
    int minDistance(std::string word1, std::string word2) {
        int m = word1.size(), n = word2.size();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) { // 位置 i 上的跟位置j上的字母相同，则不需要做新的调整
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1; // 删除一个字母和增加一个字母是对偶的，从A删除一个跟从B删除一个，是对偶的。
                }
            }
        }
        return dp[m][n];
    }
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
There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.
Note:
n and k are non-negative integers.

Example:

Input: n = 3, k = 2
Output: 6
Explanation: Take c1 as color 1, c2 as color 2. All possible ways are:

            post1  post2  post3      
 -----      -----  -----  -----       
   1         c1     c1     c2 
   2         c1     c2     c1 
   3         c1     c2     c2 
   4         c2     c1     c1  
   5         c2     c1     c2
   6         c2     c2     c1
    https://www.cnblogs.com/grandyang/p/5231220.html
*/
class _0276_PaintFence {
public:
    int numWays(int n, int k) {
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return k;
        }
        if(n == 2) {
            return k * k;
        }
        std::vector<int> DP(n+1, 0);
        DP[0] = 0;
        DP[1] = k;
        DP[2] = k * k;
        for(int i = 3; i <= n; ++i) {
            DP[i] = DP[i-1] * (k-1) + DP[i-2] * (k-1);
        }
        return DP[n];
    }
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
Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.
*/
class _0562_LongestLineOfConsecutiveOneInMatrix {
public:
    int longestLine(std::vector<std::vector<int>>& M) {
        const int n = M.size();
        int max = 0;
        if (n == 0) return max;
        int m = M[0].size();
        
        std::vector<std::vector<std::vector<int>>> 
            dp(n, std::vector<std::vector<int>>(m, std::vector<int>(4, 0)));
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (M[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    dp[i][j][k] = 1;
                }
                if (j > 0) dp[i][j][0] += dp[i][j-1][0]; // horizontal line
                if (j > 0 && i > 0) dp[i][j][1] += dp[i-1][j-1][1]; // anti-diagonal line
                if (i > 0) dp[i][j][2] += dp[i-1][j][2]; // vertical line
                if (j < m-1 && i > 0) dp[i][j][3] += dp[i-1][j+1][3]; // diagonal line
                max = std::max({max, dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3]});
            }
        }
        return max;
    }
};

/*
Given two words word1 and word2, find the minimum number of steps 
required to make word1 and word2 the same, where in each step you 
can delete one character in either string.

Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
!LCS longest common subsequences is an important algorithm that we need to know!
*/
class _0583_DeleteOperationForTwoStrings {
private:
    std::vector<std::vector<int>> DP;
    int minDistance_DP_nonLCS_based(std::string word1, std::string word2);
    int minDistance_LCS_DP_based(std::string word1, std::string word2);
    int minDistance_LCS_based(std::string word1, std::string word2);
    int lcs(std::string& s1, std::string& s2, int m, int n);
public:
    int minDistance(std::string word1, std::string word2) {
        std::vector<std::vector<int>> DP(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
        for(int i = 0; i <= word2.size(); ++i) {
            DP[0][i] = i;
        }
        for(int j = 0; j <= word1.size(); ++j) {
            DP[j][0] = j;
        }
        
        for(int i = 1; i <= word1.size(); ++i) {
            for(int j = 1; j <= word2.size(); ++j) {
                if(word1[i-1] == word2[j-1]) {
                    DP[i][j] = DP[i-1][j-1];
                } else {
                    DP[i][j] = std::min(DP[i-1][j], DP[i][j-1]) + 1;
                }
            }
        }
        
        return DP.back().back();
    }
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
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3, 2, 1].

Note:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/
class _0718_MaximumLengthOfRepeatedSubarray {
public:
    int findLength(std::vector<int>& A, std::vector<int>& B);
};

/*
Given an array nums of integers, you can perform operations on the array.
In each operation, you pick any nums[i] and delete it to earn nums[i] points. 
After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.
You start with 0 points. Return the maximum number of points you can earn by 
applying such operations.

Input: nums = [3, 4, 2]
Output: 6
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.

Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
*/
class _0740_DeleteAndEarn {
public:
    int deleteAndEarn(std::vector<int>& nums);
};


/*
Tag: dynamic programming
On a staircase, the i-th step has some non-negative cost cost[i] assigned 
(0 indexed). Once you pay the cost, you can either climb one or two steps. 
You need to find minimum cost to reach the top of the floor, and you can 
either start from the step with index 0, or the step with index 1.

Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].
*/
class _0746_MinCostClimbingStairs {
public:
    int minCostClimbingStairs(std::vector<int>& cost);
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
    std::vector<std::vector<int>> DP;
public:
    bool stoneGame(std::vector<int>& piles) {
        const int n = piles.size();
        DP = std::vector<std::vector<int>>(n, std::vector<int>(n, INT_MIN));
        for(int i = 0; i < n; ++i) {
            DP[i][i] = piles[i];
        }
        
        for(int l = 2; l <= n; ++l) { // ! A hint: loop based on the length of piles to be optimized (真正DP 方法)
            for(int i = 0; i < n - l + 1; ++i) {
                int j = i + l - 1;
                DP[i][j] = std::max(piles[i] - DP[i+1][j], piles[j] - DP[i][j-1]);
            }
        }
        return DP[0][n-1] > 0;
    }
    int score(const std::vector<int>& piles, int l, int r) { // 记忆化递归;
        if(l == r) {
            return piles[l];
        }
        if(DP[l][r] == INT_MIN) {
            DP[l][r] = std::max(piles[l] - score(piles, l+1, r), piles[r] - score(piles, l, r-1));
        }
        return DP[l][r];
    }
};

/*
! 巨难的一道动态规划题目
这道题给了我们一个长度为n的字符串S，里面只有两个字母D和I，分别表示下降 Decrease 和上升 Increase，
意思是对于 [0, n] 内所有数字的排序，必须满足S的模式，比如题目中给的例子 S="DID"，就表示序列需要先
降，再升，再降，于是就有那5种情况。题目中提示了结果可能会是一个超大数，让我们对 1e9+7 取余。
这道题正确的动态规划解法其实是比较难想出来的，因为存在着关键的隐藏信息 Hidden Information，若不能
正确的挖掘出来，是不太容易解出来的。首先来定义我们的 DP 数组吧，这里大家的第一直觉可能是想着就用一个
一维数组 dp，其中 dp[i] 表示范围在 [0, i] 内的字符串S的子串能有的不同序列的个数。这样定义的话，就
无法写出状态转移方程，像之前说的，我们忽略了很关键的隐藏信息。先来想，序列是升是降到底跟什么关系最大，
答案是最后一个数字，比如我们现在有一个数字3，当前的模式是D，说明需要下降，所以可能的数字就是 0，1，2，
但如果当前的数字是1，那么还要下降的话，那么貌似就只能加0了？其实也不一定，因为这道题说了只需要保证升
降模式正确就行了，数字之间的顺序关系其实并不重要，举个例子来说吧，假如我们现在已经有了一个 "DID" 模式
的序列 1032，假如我们还想加一个D，变成 "DIDD"，该怎么加数字呢？多了一个模式符，就多了一个数字4，显然
直接加4是不行的，实际是可以在末尾加2的，但是要先把原序列中大于等于2的数字都先加1，即 1032 -> 1043，然
后再加2，变成 10432，就是 "DIDD" 了。虽然我们改变了序列的数字顺序，但是升降模式还是保持不变的。同理，
也是可以加1的，1032 -> 2043 -> 20431，也是可以加0的，1032 -> 2143 -> 21430。但是无法加3和4，因为 
1032 最后一个数字2很很重要，所有小于等于2的数字，都可以加在后面，从而形成降序。那么反过来也是一样，若
要加个升序，比如变成 "DIDI"，猜也猜的出来，后面要加大于2的数字，然后把所有大于等于这个数字的地方都减1，
比如加上3，1032 -> 1042 -> 10423，再比如加上4，1032 -> 1032 -> 10324。
通过上面的分析，我们知道了最后一个位置的数字的大小非常的重要，不管是要新加升序还是降序，最后的数字的大
小直接决定了能形成多少个不同的序列，这个就是本题的隐藏信息，所以我们在定义 dp 数组的时候必须要把最后一
个数字考虑进去，这样就需要一个二维的 dp 数组，其中 dp[i][j] 表示由范围 [0, i] 内的数字组成且最后一个
数字为j的不同序列的个数。就拿题目中的例子来说吧，由数字 [0, 1, 2, 3] 组成 "DID" 模式的序列，首先 
dp[0][0] 是要初始化为1，如下所示(括号里是实际的序列):

We are given S, a length n string of characters from the set {'D', 'I'}. (These letters stand for "decreasing" and "increasing".)

A valid permutation is a permutation P[0], P[1], ..., P[n] of integers {0, 1, ..., n}, such that for all i:

If S[i] == 'D', then P[i] > P[i+1], and;
If S[i] == 'I', then P[i] < P[i+1].
How many valid permutations are there?  Since the answer may be large, return your answer modulo 10^9 + 7.

Example 1:

Input: "DID"
Output: 5
Explanation: 
The 5 valid permutations of (0, 1, 2, 3) are:
(1, 0, 3, 2)
(2, 0, 3, 1)
(2, 1, 3, 0)
(3, 0, 2, 1)
(3, 1, 2, 0)
 

Note:
1 <= S.length <= 200
S consists only of characters from the set {'D', 'I'}.
*/
class _0903_ValidPermutationsForDISequence {
public:
    int numPermsDISequence(std::string S) {
        int res = 0;
        const int n = S.size();
        const int M = 1e9+7;
        std::vector<std::vector<int>> DP(n + 1, std::vector<int>(n + 1));
        DP[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(S[i-1] == 'D') {
                    for(int k = j; k <= i - 1; ++k) {
                        DP[i][j] = (DP[i][j] + DP[i-1][k]) % M;
                    }
                } else {
                    for(int k = 0; k <= j - 1; ++k) {
                        DP[i][j] = (DP[i][j] + DP[i-1][k]) % M;
                    }
                }
            }
        }

        for(int i = 0; i <= n; ++i) {
            res = (res + DP[n][i]) % M;
        }
        return res;
    }
};

/*
Given a square array of integers A, we want the minimum sum of a 
falling path through A. A falling path starts at any element in 
the first row, and chooses one element from each row. The next 
row's choice must be in a column that is different from the 
previous row's column by at most one.

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12

Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.

Note:

1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100
*/
class _0931_MinimumFallingPathSum {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& A);
};


/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

Constraints:
1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/
class _1277_CountSquareSubmatricesWithAllOnes {
public:
    int countSquares(std::vector<std::vector<int>>& matrix);
};

/*
You are given a square board of characters. You can move on the board starting 
at the bottom right square marked with the character 'S'.
You need to reach the top left square marked with the character 'E'. The rest 
of the squares are labeled either with a numeric character 1, 2, ..., 9 or with 
an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if 
there is no obstacle there.
Return a list of two integers: the first integer is the maximum sum of numeric 
characters you can collect, and the second is the number of such paths that you
 can take to get that maximum sum, taken modulo 10^9 + 7.
In case there is no path, return [0, 0].

Input: board = ["E23","2X2","12S"]
Output: [7,1]

Input: board = ["E12","1X1","21S"]
Output: [4,2]

Input: board = ["E11","XXX","11S"]
Output: [0,0]
 
Constraints:

2 <= board.length == board[i].length <= 100
!这道题特别容易做错
*/
class _1301_NumberOfPathsWithMaxScore {
public:
    std::vector<int> pathsWithMaxScore(std::vector<std::string>& board) {  
        const int M = board.size();
        const int N = board[0].size();
        const int MOD = 1000000000 + 7;
        std::vector<std::vector<std::pair<int,int>>> DP(M, std::vector<std::pair<int, int>>(N, {0,0}));
        DP[M-1][N-1] = {0, 1}; // 起点是通的
        bool hasX = false;
        for(int j = N - 2; j >= 0; --j) {
            if(!hasX) {
                if(board[M-1][j] == 'X') {
                    DP[M-1][j] = {0, 0};
                    hasX = true;
                } else {
                    DP[M-1][j] = {(board[M-1][j] - '0' + DP[M-1][j+1].first) % MOD, 1};
                }
            } else {
                DP[M-1][j] = {0, 0}; // 最后一行，从后向前扫描，一旦遇到X，后面的一定不通
            }
        }
        hasX = false;
        for(int i = M-2; i >= 0; --i) {
            if(!hasX) {
                if(board[i][N-1] == 'X') {
                    DP[i][N-1] = {0, 0};
                    hasX = true;
                } else {
                    DP[i][N-1] = {(board[i][N-1] - '0' + DP[i+1][N-1].first) % MOD, 1};
                }
            } else {
                DP[i][N-1] = {0, 0}; // 最后一列，从下向上扫描，一旦遇到X，上面也同理不通
            }
        }
        DP[0][0] = {0, 0};
        board[0][0] = '0';

        for(int i = M-2; i >= 0; --i) {
            for(int j = N-2; j >= 0; --j) {
                int sc = 0;
                if(board[i][j] >= '0' && board[i][j] <= '9') {
                    sc = board[i][j] - '0';
                }
                if(!(DP[i+1][j].first == 0 && DP[i+1][j].second == 0)) { // 三个判断，每次判断都是要确保这个点本身是能走通的.
                    DP[i][j] = std::make_pair((DP[i+1][j].first + sc) % MOD,DP[i+1][j].second);
                }

                if(!(DP[i][j+1].first == 0 && DP[i][j+1].second == 0)) {
                    if(DP[i][j+1].first + sc > DP[i][j].first) {
                        DP[i][j].first = (DP[i][j+1].first + sc) % MOD;
                        DP[i][j].second = DP[i][j+1].second;
                    } else if(DP[i][j+1].first + sc == DP[i][j].first) {
                        DP[i][j].second = (DP[i][j].second + DP[i][j+1].second) % MOD;
                    }
                }

                if(!(DP[i+1][j+1].first == 0 && DP[i+1][j+1].second == 0)) {
                    if(DP[i+1][j+1].first + sc > DP[i][j].first) {
                        DP[i][j].first = (DP[i+1][j+1].first + sc) % MOD;
                        DP[i][j].second = DP[i+1][j+1].second;
                    } else if (DP[i+1][j+1].first + sc == DP[i][j].first) {
                        DP[i][j].second = (DP[i][j].second + DP[i+1][j+1].second) % MOD;
                    }
                }
            }
        }
        return {DP[0][0].first, DP[0][0].second};
    }
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

/*
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there are n stones in a pile.  On each player's turn, that 
player makes a move consisting of removing any non-zero square number 
of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.
Given a positive integer n. Return True if and only if Alice wins the 
game otherwise return False, assuming both players play optimally.

Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.

Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).

Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).

Input: n = 7
Output: false
Explanation: Alice can't win the game if Bob plays optimally.
If Alice starts removing 4 stones, Bob will remove 1 stone then Alice should remove only 1 stone and finally Bob removes the last one (7 -> 3 -> 2 -> 1 -> 0). 
If Alice starts removing 1 stone, Bob will remove 4 stones then Alice only can remove 1 stone and finally Bob removes the last one (7 -> 6 -> 2 -> 1 -> 0).

Input: n = 17
Output: false
Explanation: Alice can't win the game if Bob plays optimally.

Constraints:

1 <= n <= 10^5 
*/
class _1510_StoneGameIV {
public:
    bool winnerSquareGame(int n) {
        std::unordered_set<int> perfectSquare;
        std::vector<bool> winningTab(n+1, false);
        for(int i = 1; i <= n; ++i) {
            int si = std::sqrt(i);
            if(si * si == i) {
                winningTab[i] = true;
                perfectSquare.insert(i);
                continue;
            } else {
                for(auto ps : perfectSquare) {
                    winningTab[i] = !(winningTab[i - ps]);
                    if(winningTab[i]) {
                        break;
                    }
                }
            }
        }
        return winningTab[n];
    }
};

}
#endif