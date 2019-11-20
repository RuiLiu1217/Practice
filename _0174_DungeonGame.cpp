#include "headers.hpp"

int LeetCode::_0174_DungeonGame::calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
    const std::vector<std::vector<int>>& d = dungeon;
    const int M = d.size();
    const int N = d[0].size();
    std::vector<std::vector<int>> HP(M + 1, std::vector<int>(N+1, INT_MAX));
    HP[M-1][N] = 1;
    HP[M][N-1] = 1;  // It means after saving princess, we still at heast have 1 HP
    for(int y = M -1; y >= 0; --y) {
        for(int x = N-1; x >= 0; --x) {
            HP[y][x] = std::max(1, std::min(HP[y+1][x], HP[y][x+1])- d[y][x]);
        }
    }
    return HP[0][0];
}