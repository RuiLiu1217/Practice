#include "headers.hpp"
// 抄答案的
void LeetCode::_0073_SetMatrixZeros::setZeroes(std::vector<std::vector<int>>& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0) {
        return;
    }

    const int rows = matrix.size();
    const int cols = matrix[0].size();

    bool empty_row0 = false;
    bool empty_col0 = false;
    for(int i = 0; i < cols; ++i) { // 看第 0 行是否有 0
        if(matrix[0][i] == 0) {
            empty_row0 = true;
            break;
        }
    }

    for(int i = 0; i < rows; ++i) { // 看第 0 列是否有 0
        if(matrix[i][0] == 0) {
            empty_col0 = true;
            break;
        }
    }

    for(int i = 1; i < rows; ++i) { // 从第1行第1列 开始看，把带0的记录放到第0行，第0列
        for(int j = 1; j < cols; ++j) {
            if(matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(int i =1; i < rows; ++i) {
        for(int j = 1; j < cols; ++j) {
            if(matrix[0][j] == 0 || matrix[i][0] == 0) { // 从第1行，第1列开始看，发现0的话，就将他变成0.
                matrix[i][j] = 0;
            }
        }
    }

    if(empty_row0) {
        for(int i = 0; i < cols; ++i) {  // 如果第0行本来就有0，那么把第0行都变成0
            matrix[0][i] = 0;
        }
    }
    if(empty_col0) {
        for(int i = 0; i < rows; ++i) {  // 如果第0列本来就有0，那么把第0列都变成0
            matrix[i][0] = 0;
        }
    }

}