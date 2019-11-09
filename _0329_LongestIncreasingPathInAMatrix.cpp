#include "headers.hpp"

int LeetCode::_0329_LongestIncreasingPathInAMatrix::DFS(const std::vector<std::vector<int>>& matrix, int I, int J) {
    if(DP[I][J] != -1) {
        return DP[I][J];
    }
    static int dirs[5] = {0, -1, 0, 1, 0}; // 4 directions
    DP[I][J] = 1;
    for(int dirIdx = 0; dirIdx < 4; ++dirIdx) {
        int tI = I + dirs[dirIdx];
        int tJ = J + dirs[dirIdx+1];
        if(tI < 0 || tI >= mRow || tJ < 0 || tJ >= mCol || matrix[tI][tJ] <= matrix[I][J]) {
            continue;
        }
        DP[I][J] = std::max(DP[I][J], 1 + DFS(matrix, tI, tJ));
    }
    return DP[I][J];
}

int LeetCode::_0329_LongestIncreasingPathInAMatrix::longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
    if(matrix.empty()) {
        return 0;
    }
    mRow = matrix.size();
    mCol = matrix[0].size();
    if(mCol == 0) {
        return 0;
    }
    DP = std::move(std::vector<std::vector<int>>(mRow, std::vector<int>(mCol, -1)));
    
    int res = 0;
    for(int i = 0; i < mRow; ++i) {
        for(int j = 0; j < mCol; ++j) {
            res = std::max(res, DFS(matrix, i, j));
        }
    }
    return res;
}