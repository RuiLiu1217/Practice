#include "headers.hpp"

// Tag: dynamic programming
// dp[r][c][steps] at step "steps", the probability of knight is at r,c 
double LeetCode::_0668_KnightProbabilityInChessboard::knightProbability(int N, int K, int sr, int sc) {
    std::vector<std::vector<double>> dp(N, std::vector<double>(N, 0));
    std::vector<int> dr = {2, 2, 1, 1, -1, -1, -2, -2};
    std::vector<int> dc = {1, -1, 2, -2, 2, -2, 1, -1};
    dp[sr][sc] = 1;
    for(; K > 0; --K) {
        std::vector<std::vector<double>> dp2(N, std::vector<double>(N, 0));
        for(int r = 0; r < N; ++r) {
            for(int c = 0; c < N; ++c) {
                for(int k = 0; k < 8; ++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if(nr >= 0 && nr < N && nc >= 0 && nc < N) {
                        dp2[nr][nc] += (dp[r][c] / 8.0);
                    }
                }
            }
        }
        dp = dp2;
    }

    double ans = 0.0;
    for(auto row : dp) {
        for(auto x : row) {
            ans += x;
        }
    }
    return ans;
}