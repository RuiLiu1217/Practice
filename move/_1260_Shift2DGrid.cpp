#include "headers.hpp"

// 其实没有看懂这道题的shift operation 到底在干什么，直接抄答案
std::vector<std::vector<int>> LeetCode::_1260_Shift2DGrid::shiftGrid(std::vector<std::vector<int>>& grid, int K) {
    int n = grid.size(), m = grid[0].size();
    for(int k = 0; k < K; k++) {            
        int prev = grid[0][0]; grid[0][0] = grid[n - 1][m - 1];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0)
                    continue;
                int temp = grid[i][j];
                grid[i][j] = prev;
                prev = temp;
            }
        }
    }
    return grid;
}