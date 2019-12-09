#include "headers.hpp"
#include <cmath>
#include <algorithm>
int LeetCode::_1277_CountSquareSubmatricesWithAllOnes::countSquares(std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> DP(matrix.size(), std::vector<int>(matrix[0].size(), 0));
    DP[0] = matrix[0];
    for(int j = 0; j < matrix.size(); ++j) {
        DP[j][0] = matrix[j][0];
    }
    for(int i = 1; i < matrix.size(); ++i) {
        for(int j = 1; j < matrix[i].size(); ++j) {
            if(matrix[i][j] == 1) {
                DP[i][j] = std::min(std::min(DP[i-1][j], DP[i][j-1]), DP[i-1][j-1]) + 1;
            }
        }
    }
    
    int sum = 0;
    for(int i = 0; i < matrix.size(); ++i) {
        for(int j = 0; j < matrix[i].size(); ++j) {
            sum += DP[i][j];
        }
    }
    return sum;
};
