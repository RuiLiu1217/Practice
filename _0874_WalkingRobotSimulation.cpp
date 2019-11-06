#include "headers.hpp"
#include <set>
#include <vector>
#include <cmath>

int LeetCode::_0874_WalkingRobotSimulation::robotSim(std::vector<int>& commands,std::vector<std::vector<int>>& obstacles) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int x = 0, y = 0, di = 0;

    std::set<std::pair<int, int>> obstacleSet;
    for (std::vector<int> obstacle: obstacles)
        obstacleSet.insert(std::make_pair(obstacle[0], obstacle[1]));

    int ans = 0;
    for (int cmd: commands) {
        if (cmd == -2)
            di = (di + 3) % 4;
        else if (cmd == -1)
            di = (di + 1) % 4;
        else {
            for (int k = 0; k < cmd; ++k) {
                int nx = x + dx[di];
                int ny = y + dy[di];
                if (obstacleSet.find(std::make_pair(nx, ny)) == obstacleSet.end()) {
                    x = nx;
                    y = ny;
                    ans = std::max(ans, x*x + y*y);
                }
            }
        }
    }
    return ans;
}