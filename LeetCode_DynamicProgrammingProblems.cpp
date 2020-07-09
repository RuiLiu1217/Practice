#include "LeetCode_DynamicProgrammingProblems.hpp"

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