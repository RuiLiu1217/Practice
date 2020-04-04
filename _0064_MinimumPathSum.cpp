#include "headers.hpp"
/*
Type: Array
*/
int LeetCode::_0064_MinimumPathSum::minPathSum(std::vector<std::vector<int>>& grid) {
    if(grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }
    std::vector<std::vector<int>> DP(grid.size(), std::vector<int>(grid[0].size()));
    
    DP[0][0] = grid[0][0];
    for(int j = 1; j < grid[0].size(); ++j) {
        DP[0][j] = DP[0][j-1] + grid[0][j];
    }
    for(int i = 1; i < grid.size(); ++i) {
        DP[i][0] = DP[i-1][0] + grid[i][0];
    }
    
    for(int i = 1; i < grid.size(); ++i) {
        for(int j = 1; j < grid[i].size(); ++j) {
            DP[i][j] = std::min(DP[i-1][j] , DP[i][j-1]) + grid[i][j];
        }
    }
    return DP.back().back();
}
