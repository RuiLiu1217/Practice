#include "headers.hpp"

bool LeetCode::_0490_TheMaze::hasPath(std::vector<std::vector<int>>& maze, std::vector<int>& start, std::vector<int>& destination) {
    M = maze.size();
    N = maze[0].size();
    di = destination[0];
    dj = destination[1];
    return hasPath(maze, start[0], start[1]);
}

bool LeetCode::_0490_TheMaze::hasPath(std::vector<std::vector<int>>& maze, int i, int j) {
    if(i == di && j == dj) {
        return true;
    }
    bool res = false;
    maze[i][j] = -1;
    for(int d = 0; d < 4; ++d) {
        int x = i;
        int y = j;
        while(x >= 0 && x < M && y >= 0 && y < N && maze[x][y] != 1) {
            x += dirs[d];
            y += dirs[d+1];
        }
        x -= dirs[d];
        y -= dirs[d+1];
        if(maze[x][y] != -1) {
            res |= hasPath(maze, x, y);
        }
    }
    return res;
}