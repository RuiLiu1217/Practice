#include "LeetCode_BFS.hpp"
#include "HeaderFiles.hpp"

bool LC::_0403_FrogJump::canCross(std::vector<int>& stones) {
    std::queue<std::pair<int, int>> q;
    std::unordered_set<std::string> visited;
    std::unordered_set<int> val;
    for(int s : stones) {
        val.insert(s);
    }
    q.push({0, 0});
    visited.insert("0_0");
    while(!q.empty()) {
        const int N = q.size();
        for(int i = 0; i < N; ++i) {
            auto f = q.front();
            q.pop();
            
            if (f.first == stones.back()) {
                return true;
            }
            
            int v1 = f.first + f.second - 1;
            if (v1 > f.first) {
                std::string sv1 = std::to_string(v1) + "_" + std::to_string(f.second - 1);
                if(val.count(v1) && !visited.count(sv1)) {
                    q.push({v1, f.second-1});
                    visited.insert(sv1);
                }
            }
            
            int v2 = f.first + f.second;
            if(v2 > f.first) {
                std::string sv2 = std::to_string(v2) + "_" + std::to_string(f.second);
                if(val.count(v2) && !visited.count(sv2)) {
                    q.push({v2, f.second});
                    visited.insert(sv2);
                }
            }
            
            int v3 = f.first + f.second + 1;
            if(v3 > f.first) {
                std::string sv3 = std::to_string(v3) + "_" + std::to_string(f.second + 1);
                if(val.count(v3) && !visited.count(sv3)) {
                    q.push({v3, f.second+1});
                    visited.insert(sv3);
                }
            }                
        }
    }
    return false;
}


void LC::_0286_WallsAndGates::wallsAndGates(std::vector<std::vector<int>>& rooms) {
    const int row = rooms.size();
    if(0 == row) {
        return;
    }
    const int col = rooms[0].size();
    if(0 == col) {
        return;
    }
    
    std::queue<int> canSearch; 
    int dirs[5] = {1, 0, -1, 0, 1};
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            if(rooms[i][j] == 0) {
                canSearch.push(i * col + j);
            }
        }
    }
    while(!canSearch.empty()) {
        int v = canSearch.front(); canSearch.pop();
        int r = v / col;
        int c = v % col;
        for(int d = 0; d < 4; ++d) {
            int x = r + dirs[d];
            int y = c + dirs[d+1];
            if(x < 0 || x >= row || y < 0 || y >= col || rooms[x][y] <= rooms[r][c] + 1) {
                continue;
            }
            rooms[x][y] = rooms[r][c] + 1;
            canSearch.push(x * col + y);
        }
    }
}


bool LC::_0841_KeysAndRooms::canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
    std::vector<int> visited(rooms.size(), 0);
    std::queue<int> roomQ;
    for(int key : rooms[0]) {
        roomQ.push(key);
    }
    visited[0] = 1; // room 0 is visited

    while(!roomQ.empty()) {
        int rmIdx = roomQ.front(); // room rmIdx is visitable
        roomQ.pop();

        if (!visited[rmIdx]) {
            visited[rmIdx] = 1; // visit room rmIdx
            for(int keyIdx : rooms[rmIdx]) {
                if(visited[keyIdx] == false) {
                    roomQ.push(keyIdx);
                }
            }
        }
        
    }

    return std::accumulate(visited.begin(), visited.end(), 0) == visited.size();
}



int LC::_1091_ShortestPathInBinaryMatrix::shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    int steps = 0;
    while(!q.empty()) {
        ++steps;
        std::queue<std::pair<int, int>> q1;
        while(!q.empty()) {
            auto c = q.front();
            q.pop();

            if(c.first >= 0 && c.second >= 0 && c.first < grid.size() && c.second < grid[0].size()
            && !grid[c.first][c.second]) {
                grid[c.first][c.second] = 1;
                if(c.first == grid.size() - 1 && c.second == grid[0].size() - 1) {
                    return steps;
                }

                for(int i = -1; i < 2; ++i) {
                    for(int j = -1; j < 2; ++j) {
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