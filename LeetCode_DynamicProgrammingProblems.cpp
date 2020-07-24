#include "LeetCode_DynamicProgrammingProblems.hpp"
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <algorithm>
#include <numeric>
#include <vector>
// Tag: dynamic programming, string matching.
bool LC::_0010_RegularExpressionMatching::isMatch(std::string s, std::string p){
    const int M = s.length();
    const int N = p.length();

    // DP[i][j] means whether the first [0,i) substr of s 
    // matches with the first [0,j) substr of p.
    std::vector<std::vector<bool>> DP(M + 1, std::vector<bool>(N + 1, false));
    DP[0][0] = true;

    for(int i = 0; i <= M; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(p[j-1] == '*') {
                DP[i][j] = DP[i][j-2] || (i && DP[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
            } else {
                DP[i][j] = i && DP[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            }
        }
    }
    return DP[M][N];
}


int LC::_0062_UniquePaths::uniquePaths(int m, int n) {
    std::vector<std::vector<int>> DP(m, std::vector<int>(n, 0));
    DP[0][0] = 1;
    for(int j = 0; j < n; ++j) {
        DP[0][j] = 1;
    }
    for(int i = 0; i < m; ++i) {
        DP[i][0] = 1;
    }
    for(int i = 1; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            DP[i][j] = DP[i-1][j] + DP[i][j-1];
        }
    }
    return DP[m-1][n-1];
}



int LC::_0063_UniquePathsII::uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    const int M = obstacleGrid.size();
    const int N = obstacleGrid[0].size();
    std::vector<std::vector<long long>> DP(M, std::vector<long long>(N));
    bool flag = false;
    for (int i = 0; i < M; ++i) {
        if (obstacleGrid[i][0] == 0) {
            DP[i][0] = 1;
        } else {
            DP[i][0] = -1;
            flag = true;
        }

        if (flag) {
            DP[i][0] = -1;
        }
    }

    flag = false;
    for (int j = 0; j < N; ++j) {
        if (obstacleGrid[0][j] == 0) {
            DP[0][j] = 1;
        } else {
            DP[0][j] = -1;
            flag = true;
        }

        if (flag) {
            DP[0][j] = -1;
        }
    }

    for (int i = 1; i < M; ++i) {
        for (int j = 1; j < N; ++j) {
            if (obstacleGrid[i][j] != 1) {
                if (DP[i - 1][j] == -1 && DP[i][j - 1] == -1) {
                    DP[i][j] = -1;
                } else if (DP[i - 1][j] != -1 && DP[i][j - 1] == -1) {
                    DP[i][j] = DP[i - 1][j];
                } else if (DP[i - 1][j] == -1 && DP[i][j - 1] != -1) {
                    DP[i][j] = DP[i][j - 1];
                } else {
                    DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
                }
            } else {
                DP[i][j] = -1;
            }
        }
    }
    return DP[M - 1][N - 1] == -1 ? 0 : DP[M - 1][N - 1];
}


int LC::_0064_MinimumPathSum::minPathSum(std::vector<std::vector<int>>& grid) {
    if(grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }
    std::vector<std::vector<int>> DP(grid.size(), std::vector<int>(grid[0].size()));
    
    DP[0][0] = grid[0][0];
    for(int j = 1; j < grid[0].size(); ++j) {
        DP[0][j] = DP[0][j-1] + grid[0][j];
    }
    for(int i = 1; i < grid.size(); ++i) {
        DP[i][0] = DP[i-1][0] + grid[i][0];
    }
    
    for(int i = 1; i < grid.size(); ++i) {
        for(int j = 1; j < grid[i].size(); ++j) {
            DP[i][j] = std::min(DP[i-1][j] , DP[i][j-1]) + grid[i][j];
        }
    }
    return DP.back().back();
}


int LC::_0070_ClimbingStairs::climbStairs(int n) {
    if(n < 3) {
        return n;
    }
    int f1 = 1;
    int f2 = 2;
    int f;
    for(int i = 3; i <= n; ++i) {
        f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    return f;
}

bool LC::_0097_InterleavingString::isInterleav(std::string s1, std::string s2, std::string s3) {
    if(s3.length() != s1.length() + s2.length())
        return false;

    bool table[s1.length() + 1][s2.length() + 1];

    for(int i = 0; i <= s1.length(); ++i) {
        for(int j = 0; j <= s2.length(); ++j) {
            if(i == 0 && j == 0) {
                table[i][j] = true;
            } else if(i == 0) {
                table[i][j] = (table[i][j-1] && s2[j-1] == s3[i+j-1]);
            } else if(j == 0) {
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1]);
            } else {
                table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
            }
        }
    }
    return table[s1.length()][s2.length()];
}


//! 抄答案的，动态规划
// 由于需要在O(N)时间复杂度内完成，
// 这道题要求求最长连续序列，并给定了O(n)复杂度限制，我们的思路是，使用一个集合HashSet存入所有的数字，
// 然后遍历数组中的每个数字，如果其在集合中存在，那么将其移除，然后分别用两个变量pre和next算出其前一个
// 数跟后一个数，然后在集合中循环查找，如果pre在集合中，那么将pre移除集合，然后pre再自减1，直至pre不
// 在集合之中，对next采用同样的方法，那么next-pre-1就是当前数字的最长连续序列，更新res即可。这里再说下
// 为啥当检测某数字在集合中存在当时候，都要移除数字。这是为了避免大量的重复计算，就拿题目中的例子来说吧
// 我们在遍历到4的时候，会向下遍历3，2，1，如果都不移除数字的话，遍历到1的时候，还会遍历2，3，4。同样，
// 遍历到3的时候，向上遍历4，向下遍历2，1，等等等。如果数组中有大量的连续数字的话，那么就有大量的重复计
// 算，十分的不高效，所以我们要从HashSet中移除数字，代码如下：
int LC::_0128_LongestConsecutiveSequence::longestConsecutive(std::vector<int>& nums) {
    int res = 0;
    std::unordered_set<int> s(nums.begin(), nums.end());
    for (int val : nums) {
        if (!s.count(val)) continue;
        s.erase(val);
        int pre = val - 1, next = val + 1;
        while (s.count(pre)) s.erase(pre--);
        while (s.count(next)) s.erase(next++);
        res = std::max(res, next - pre - 1);
    }
    return res;
}


/* It is a typical DP problem. We design a DP vector, DP[i] means the maximum value that we can get from 
nums[0] to nums[i].

DP[0] = nums[0];
DP[1] = max(nums[0], nums[1]);
DP[2] = max(DP[0] + nums[0], nums[1]); 

Therefore, DP[i] = max(DP[i-2] + nums[i], DP[i-1]); */
int LC::_0198_HouseRobber::rob(std::vector<int>& nums) {
    if(nums.size() == 0) {
        return 0;
    }
    std::vector<int> DP(nums.size()+1, 0);
    DP[0] = nums[0];
    if(nums.size() == 1) {
        return nums[0];
    }
    DP[1] = std::max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); ++i) {
        DP[i] = std::max(DP[i-2] + nums[i], DP[i-1]);
    }
    
    return DP[nums.size()-1];
}
