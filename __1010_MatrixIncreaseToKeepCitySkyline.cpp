#include "headers.hpp"

int LintCode::_1010_MaxIncreaseToKeepCitySkyline::maxIncreaseKeepingSkyline(std::vector<std::vector<int>> &grid) {
    std::vector<std::vector<int>> res;
    std::vector<int> rowMax(grid.size());
    std::vector<int> colMax(grid[0].size());
    for(int i = 0; i < grid.size(); ++i) {
        int rm = grid[i][0];
        for(int j = 0; j < grid[i].size(); ++j) {
            if(rm < grid[i][j]) {
                rm = grid[i][j];
            }
        }
        rowMax[i] = rm;
    }
    
    for(int j = 0; j < grid[0].size(); ++j) {
        int cm = grid[0][j];
        for(int i = 0; i < grid.size(); ++i) {
            if(cm < grid[i][j]) {
                cm = grid[i][j];
            }
        }
        colMax[j] = cm;
    }

    int count = 0;
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            int minIJ = std::min(rowMax[i], colMax[j]);
            count += (minIJ - grid[i][j]);
        }
    }
    return count;
}