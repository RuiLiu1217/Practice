#include "headers.hpp"

int LeetCode::_0718_MaximumLengthOfRepeatedSubarray::findLength(std::vector<int>& A, std::vector<int>& B) {
    std::vector<std::vector<int>> DP(A.size(), std::vector<int>(B.size(), 0));
    for(int j = 0; j < DP[0].size(); ++j) {
        if(B[j] == A[0]) {
            DP[0][j] = 1;
        }
    }
    for(int i = 0; i < DP.size(); ++i) {
        if(A[i] == B[0]) {
            DP[i][0] = 1;
        }
    }
    int maxV = 0;
    for(int i = 1; i < DP.size(); ++i) {
        for(int j = 1; j < DP[i].size(); ++j) {
            if(A[i] == B[j]) {
                DP[i][j] = DP[i-1][j-1] + 1;
                maxV = std::max(DP[i][j], maxV);
            }
        }
    }
    return maxV;
}