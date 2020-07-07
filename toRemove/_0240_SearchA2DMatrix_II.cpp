#include "headers.hpp"

bool LeetCode::_0240_SearchA2DMatrix_II::searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    const int m = matrix.size();
    if(m == 0)     {
        return false;
    }
    const int n = matrix[0].size();
    if(n == 0) {
        return false;
    }

    int i = 0;
    int j = n - 1;
    while(i < m && j >= 0) {
        if(matrix[i][j] == target) {
            return true;
        } else if(matrix[i][j] > target) {
            --j;
        } else {
            ++i;
        }
    }
    return false;
};

