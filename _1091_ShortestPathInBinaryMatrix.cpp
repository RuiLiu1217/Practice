#include "headers.hpp"
#include <queue>


int LeetCode::_1091_ShortestPathInBinaryMatrix::shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {

}

static int shortPathBinaryMatrix(std::vector<std::vector<int>>& grid, int steps = 0) {
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()) {
        ++steps;
        std::queue<std::pair<int, int>> q1;
        while(!q.empty()) {
            auto c = q.front();
            q.pop();

            if(
            c.first >= 0 && 
            c.second >= 0 && 
            c.first < grid.size() && 
            c.second < grid[0].size() && 
            !grid[c.first][c.second]) {
                grid[c.first][c.second] = 1;
                if(c.first == grid.size() - 1 && c.second == grid[0].size() - 1) {
                    return steps;
                }

                for(auto i = -1; i < 2; ++i) {
                    for(auto j = -1; j < 2; ++j) {
                        if(i != 0 || j != 0) {
                            q1.push({c.first + i, c.second + j});
                        }
                    }
                }
            }
        }
        std::swap(q, q1);
    }
    return -1;
}