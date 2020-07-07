#include "headers.hpp"
/*
Type: Array
*/
bool LeetCode::_0074_SearchA2DMatrix::searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    const int M = matrix.size();
    if(M == 0) {
        return false;
    }
    const int N = matrix[0].size();
    if(N == 0) {
        return false;
    }
    int i = 0;
    int j = N - 1;
    while(i < M && j >= 0) {
        if(matrix[i][j] == target) {
            return true;
        } else if(matrix[i][j] > target) {
            --j;
        } else {
            ++i;
        }
    }
    return false;
}
