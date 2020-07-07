#include "headers.hpp"
#include <unordered_map>
int LeetCode::_1267_CountServersThatCommunicate::countServers(std::vector<std::vector<int>>& grid) {
    std::unordered_map<int, int> rowCount;
    std::unordered_map<int, int> colCount;
    int totCom = 0;
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            if(grid[i][j]) {
                ++rowCount[i];
                ++colCount[j];
                ++totCom;
            }
        }
    }
    
    int res = 0;
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[i].size(); ++j) {
            if(grid[i][j]) {
                if(rowCount[i] == 1 && colCount[j] == 1) {
                    ++res;
                }
            }
        }
    }
    
    return totCom - res;
}