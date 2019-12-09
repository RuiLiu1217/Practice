#include "headers.hpp"
int LeetCode::_1254_NumberOfClosedIslands::closedIsland(std::vector<std::vector<int>>& grid) {
    M = grid.size();
    N = grid[0].size();
    count = 0;
    if(M == 0 || N == 0) {
        return count;
    }
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if (grid[i][j] == 0) {
                bool touchEdge = false;
                DFS(grid, i, j, touchEdge);
                if(!touchEdge) {
                    ++count;
                }
            }
        }
    }
    return count;
}

void LeetCode::_1254_NumberOfClosedIslands::DFS(std::vector<std::vector<int>>& grid, int I, int J, bool& touchEdge) {
    if(I < 0 || I >= M || J < 0 || J >= N || grid[I][J] == 1 || grid[I][J] == 2) { // Out of scope
        return;
    }
    if(grid[I][J] == 0) {
        if(I == 0 || I == M - 1 || J == 0 || J == N - 1) {  // This water touch the edge
            touchEdge = true;
        }
        grid[I][J] = 2;
        DFS(grid, I + 1, J, touchEdge);
        DFS(grid, I - 1, J, touchEdge);
        DFS(grid, I, J + 1, touchEdge);
        DFS(grid, I, J - 1, touchEdge);
    }
}

