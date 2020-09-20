#include "headers.hpp"
// Backtracking
int LeetCode::_0200_NumberOfIslands::numIslands(std::vector<std::vector<char>>& grid) {
    const int M = grid.size();
    if(M == 0) {
        return 0;
    }
    const int N = grid[0].size();
    if(N == 0) {
        return 0;
    }
    int numIsland = 0;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(grid[i][j] == '1') {
                ++numIsland;
                eraseIsland(grid, i, j);
            }
        }
    }
    return numIsland;
}

void LeetCode::_0200_NumberOfIslands::eraseIsland(std::vector<std::vector<char>>& grid, int i, int j) {   
    const int M = grid.size();
    if(M == 0) {
        return;
    }
    const int N = grid[0].size();
    if(N == 0) {
        return;
    }
    if(i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == '0') {
        return;
    } else {
        grid[i][j] = '0';
        eraseIsland(grid, i-1, j);
        eraseIsland(grid, i+1, j);
        eraseIsland(grid, i, j-1);
        eraseIsland(grid, i, j+1);
    }
}