#include "headers.hpp"

int LeetCode::_0694_NumberOfDistinceIslands::numDistinctIslands(std::vector<std::vector<int>>& grid) {
    M = grid.size();
    if(M == 0) {
        return 0;
    }
    N = grid[0].size();
    if(N == 0) {
        return 0;
    }
    std::unordered_set<std::string> islands;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(grid[i][j] == 1) {
                std::string path;
                DFS(grid, path, i, j, i, j);
                islands.insert(path);
            }
        }
    }
    return islands.size();
}

void LeetCode::_0694_NumberOfDistinceIslands::DFS(std::vector<std::vector<int>>& grid, std::string& path, int i, int j, const int I, const int J) {
    if(i < 0 || i >= M || j < 0 || j >= N || grid[i][j] == 0) {
        return;
    }
    grid[i][j] = 0;
    path += std::to_string(i - I) + "*" + std::to_string(j - J) + "_"; // Serialize the island
    DFS(grid, path, i+1, j, I, J);
    DFS(grid, path, i-1, j, I, J);
    DFS(grid, path, i, j+1, I, J);
    DFS(grid, path, i, j-1, I, J);
}
