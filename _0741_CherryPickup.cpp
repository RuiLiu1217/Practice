#include "headers.hpp"

int dp(const std::vector<std::vector<int>>& grid, std::vector<std::vector<std::vector<int>>>& DP, int x1, int y1, int x2) {
    const int y2 = x1 + y1 - x2;
    if(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) {
        return -1;
    }

    if(grid[x1][y1] < 0 || grid[x2][y2] < 0) {
        return -1;
    }

    if(x1 == 0 && y1 == 0) {
        return grid[x1][y1];
    }

    if(DP[x1][y1][x2] != INT_MIN) {
        return DP[x1][y1][x2];
    }

    int ans = std::max(
        std::max(dp(grid,DP, x1-1, y1, x2), dp(grid,DP, x1, y1-1, x2)), 
        std::max(dp(grid,DP, x1-1, y1, x2-1), dp(grid,DP, x1, y1-1, x2-1))
        );
    if(ans < 0) {
        return DP[x1][y1][x2] = -1;
    }
    ans += grid[x1][y1];
    if(x1 != x2) {
        ans += grid[x2][y2];
    }
    return DP[x1][y1][x2] = ans;   
}


int LeetCode::_0741_CherryPickup::cherryPickup(std::vector<std::vector<int>>& grid) {
    const int N = grid.size();
    std::vector<std::vector<std::vector<int>>> DP(N, std::vector<std::vector<int>>(N, std::vector<int>(N, INT_MIN)));
    return std::max(0, dp(grid, DP, N-1, N-1, N-1));
}