#include "headers.hpp"
#include <functional>
int LeetCode::_0361_BombEnemy::maxkilledEnemies(std::vector<std::vector<char>>& grid) {
    if(grid.size() == 0 || grid[0].size() == 0) {
        return 0;
    }
    const int Row = grid.size();
    const int Col = grid[0].size();

    std::vector<std::vector<int>> DP(Row, std::vector<int>(Col, 0));
    int cnt = 0;
    std::function<void(int, int, int&)> update = [&](int r, int c, int& cnt){
        if(grid[r][c] == '0') {
            DP[r][c] += cnt;
        } else if(grid[r][c] == 'E') {
            ++cnt;
        } else {
            cnt = 0;
        }
    };

    for(int r = 0; r < Row; ++r) {
        cnt = 0;
        for(int c = 0; c < Col; ++c) {
            update(r,c,cnt);
            
        }
        
        cnt = 0;
        for(int c = Col - 1; c >= 0; --c) {
            update(r,c,cnt);
        }
    }
    
    int max = 0;
    for(int c = 0; c < Col; ++c) {
        int cnt = 0;
        for(int r = 0; r < Row; ++r) {
            update(r,c,cnt);
        }
        
        cnt = 0;
        
        for(int r = Row - 1; r >= 0; --r) {
            update(r,c,cnt);
            max = std::max(max, DP[r][c]);
        }
    }
    return max;

}