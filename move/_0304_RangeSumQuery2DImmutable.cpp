#include "headers.hpp"

LeetCode::_0304_RangeSumQuery2D_Immutable::_0304_RangeSumQuery2D_Immutable(std::vector<std::vector<int>>& matrix) {
    const int rowNum = matrix.size();
    if(rowNum == 0)
    {
        return;
    }
    const int colNum = matrix[0].size();
    if(colNum == 0)
    {
        return;
    }
    prefixSum.resize(rowNum+1);
    for(int i = 0; i != prefixSum.size(); ++i)
    {
        prefixSum[i].resize(colNum+1);
    }
    
    for(int i = 0; i != rowNum; ++i)
    {
        for(int j = 0; j != colNum; ++j)
        {
            prefixSum[i+1][j+1] = prefixSum[i][j+1] + prefixSum[i+1][j] - prefixSum[i][j] + matrix[i][j];
        }
    }   
}

int LeetCode::_0304_RangeSumQuery2D_Immutable::sumRegion(int row1, int col1, int row2, int col2) {
     return prefixSum[row2 + 1][col2 + 1] - prefixSum[row1][col2 + 1] - prefixSum[row2 + 1][col1] + prefixSum[row1][col1];
}