#include "headers.hpp"
int LeetCode::_0554_BrickWall::leastBricks(std::vector<std::vector<int>>& wall) {
    const int N = wall.size(); // number of rows
    std::unordered_map<int, std::unordered_set<int>> myMap;
    for(int n = 0; n < N; ++n) {
        int wid = wall[n][0];
        if(wall[n].size() > 1) {
            myMap[wid].insert(n);
        }            
        for(int l = 1; l < wall[n].size() - 1; ++l) {
            wid += wall[n][l];
            myMap[wid].insert(n);
        }
    }
    
    int maxNum = 0;
    for(auto wid : myMap) {
        if(wid.second.size() > maxNum) {
            maxNum = wid.second.size();
        }
    }
    return N - maxNum;
}