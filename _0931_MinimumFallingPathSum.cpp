#include "headers.hpp"
#include <algorithm>
int LeetCode::_0931_MinimumFallingPathSum::minFallingPathSum(std::vector<std::vector<int>>& A) {
    std::vector<std::vector<int>> DP(A.size(), std::vector<int>(A[0].size(), 0));
    for(int i = 0; i < A.size(); ++i) {
        for(int c = 0; c < A[i].size(); ++c) {
            if(i == 0) {
                DP[i][c] = A[i][c];
            } else {
                int t;
                if(c == 0) {
                    t = std::min(DP[i-1][c], DP[i-1][c+1]);
                } else if(c == A[i].size() - 1) {
                    t = std::min(DP[i-1][c], DP[i-1][c-1]);
                } else {
                    t = std::min(std::min(DP[i-1][c], DP[i-1][c-1]), DP[i-1][c+1]);
                }
                DP[i][c] = t + A[i][c];
            }
        }
    }
    return *std::min_element(DP.back().begin(), DP.back().end());
}