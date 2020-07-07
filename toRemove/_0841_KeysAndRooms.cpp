#include "headers.hpp"
#include <queue>
#include <numeric>
bool LeetCode::_0841_KeysAndRooms::canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
    std::vector<int> accessible(rooms.size(), 0);
    accessible[0] = 1;
    std::queue<int> roomQ;
    for(int i = 0; i < rooms[0].size(); ++i) {
        roomQ.push(rooms[0][i]);
    }

    while(!roomQ.empty()) {
        int rmIdx = roomQ.front();
        if( accessible[rmIdx] == 0){
            accessible[rmIdx] = 1;
            for(int j = 0; j < rooms[rmIdx].size(); ++j) {
                if(accessible[rooms[rmIdx][j]] == false) {
                    roomQ.push(rooms[rmIdx][j]);
                }
            }
        }
        roomQ.pop();
    }

    return std::accumulate(accessible.begin(), accessible.end(), 0) == accessible.size();
}
