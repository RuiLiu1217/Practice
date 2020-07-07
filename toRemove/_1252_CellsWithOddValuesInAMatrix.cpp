#include "headers.hpp"

int LeetCode::_1252_CellsWithOddValuesInAMatrix::oddCells(int n, int m, std::vector<std::vector<int>>& indices) {
    std::vector<std::vector<bool>> matrix(n, std::vector<bool>(m, false));
    for(auto index : indices) {
        for(int j = 0; j < m; ++j) 
        {
            matrix[index[0]][j] = !matrix[index[0]][j];
        }
        for(int i = 0; i < n; ++i) {
            matrix[i][index[1]] = !matrix[i][index[1]];
        }
    }
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}