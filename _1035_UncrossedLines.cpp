#include "headers.hpp"

// A Typical DP problem

// Copy from the solution:
// 记dp[i][j]为A[i]与B[j]连线后可以组成的最多连线的数量，
// 当然这里A[i]与B[j]连线是虚拟的连线，因此存在A[i] != B[j]
// 的情况。首先来看A[i] == B[j]，这说明A[i]与B[i]可以连线，
// 显然有dp[i][j] = dp[i-1][j-1]+1；如果是A[i] != B[j]，
// 那么分为三种情况dp[i][j] = max(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])，
// 这是因为A[i]不与B[j]连线，但是A[i]可能可以与B[j]之前所有点的连线，
// 同理B[j]也是一样的。
int LeetCode::_1035_UncrossedLines::maxUncrossedLines(std::vector<int>& A, std::vector<int>& B) {
    const int M = A.size();
    const int N = B.size();
    std::vector<std::vector<int>> DP(M, std::vector<int>(N, 0));
    for(int i = 0; i < A.size(); ++i) {
        for(int j = 0; j < B.size(); ++j) {
            if(A[i] == B[j]) {
                DP[i][j] = std::max(DP[i][j], 1);
                if(i > 0 && j > 0) {
                    DP[i][j] = std::max(DP[i][j], DP[i-1][j-1] + 1);
                }
            } else {
                if(i > 0 && j > 0) {
                    DP[i][j] = std::max(DP[i][j], DP[i-1][j-1]);
                }
                if(j > 0) {
                    DP[i][j] = std::max(DP[i][j], DP[i][j-1]);
                }
                if(i > 0) {
                    DP[i][j] = std::max(DP[i][j], DP[i-1][j]);
                }
            }
        }
    }

    return DP.back().back();
}