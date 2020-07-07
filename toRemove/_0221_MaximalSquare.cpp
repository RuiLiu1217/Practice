#include "headers.hpp"
// Tag: Dynamic Programming
// Google
// TODO: state transition equation
int LeetCode::_0221_MaximalSquare::maximalSquare(std::vector<std::vector<char>>& matrix) {
    const int M = matrix.size();
    if(M == 0) {
        return 0;
    }
    const int N = matrix[0].size();
    if(N == 0) {
        return 0;
    }
    
    std::vector<std::vector<int>> DP(M, std::vector<int>(N, 0));
    int maxS = 0;
    for(int j = 0; j < N; ++j) {
        if(matrix[0][j] == '1') {
            DP[0][j] = 1;
            maxS = std::max(maxS, DP[0][j]);
        }
    }
    for(int i = 0; i < M; ++i) {
        if(matrix[i][0] == '1') {
            DP[i][0] = 1;
            maxS = std::max(maxS, DP[i][0]);
        }
    }
    for(int i = 1; i < M; ++i) {
        for(int j = 1; j < N; ++j) {
            if(matrix[i][j] == '1') {
                DP[i][j] = std::min(std::min(DP[i-1][j], DP[i][j-1]), DP[i-1][j-1]) + 1;
                maxS = std::max(maxS, DP[i][j]);
            }
        }
    }
    return maxS * maxS;
}