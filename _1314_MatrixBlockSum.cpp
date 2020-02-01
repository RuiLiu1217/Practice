#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_1314_MatrixBlockSum::matrixBlockSum(std::vector<std::vector<int>>& mat, int K) {
    const int M = mat.size();
    const int N = mat[0].size();
    std::vector<std::vector<int>> rangeSum(M+1, std::vector<int>(N+1));
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            rangeSum[i+1][j+1] = 
            rangeSum[i+1][j] + rangeSum[i][j+1] - rangeSum[i][j] 
            + mat[i][j];
        }
    }

    std::vector<std::vector<int>> ans(M, std::vector<int>(N));
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            int r1 = std::max(0, i - K);
            int c1 = std::max(0, j - K);
            int r2 = std::min(M, i + K + 1);
            int c2 = std::min(N, j + K + 1);
            ans[i][j] = rangeSum[r2][c2] - rangeSum[r1][c2] - rangeSum[r2][c1] + rangeSum[r1][c1];
        }
    }
    return ans;
}