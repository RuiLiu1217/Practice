#include "headers.hpp"
#include <algorithm>

std::vector<std::vector<int>> LeetCode::_1329_SortTheMatrixDiagonally::diagonalSort(std::vector<std::vector<int>>& mat) {
    const int M = mat.size();
    const int N = mat[0].size();
    
    std::vector<std::vector<int>> res = mat;
    for(int col = 0; col < N; ++col) {
        std::vector<int> temp;
        for(int i = 0; i < M && (i + col) < N; ++i) {
            temp.push_back(mat[i][col + i]);
        }
        std::sort(temp.begin(), temp.end());
        for(int i = 0; i < M && (i + col) < N; ++i) {
            res[i][col + i] = temp[i];
        }
    }
    
    for(int row = 1; row < M; ++row) {
        std::vector<int> temp;
        for(int j = 0; j < N && row + j < M; ++j) {
            temp.push_back(mat[row + j][j]);
        }
        std::sort(temp.begin(), temp.end());
        for(int j = 0; j < N && row + j < M; ++j) {
            res[row + j][j] = temp[j];
        }
    }
    return res;
}