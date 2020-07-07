#include "headers.hpp"

int LeetCode::_0562_LongestLineOfConsecutiveOneInMatrix::longestLine(std::vector<std::vector<int>>& M) {
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