#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_1222_QueensThatCanAttackTheKing::queensAttackTheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king) {
    int dis[8] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    std::vector<std::vector<int>> temp(8);
    for(auto& queen : queens) {
        const int disX = std::abs(queen[0] - king[0]);
        const int disY = std::abs(queen[1] - king[1]);
        const int d = disX + disY;
        if(queen[1] == king[1] && queen[0] > king[0]) {
            if(d < dis[0]) {
                dis[0] = d;
                temp[0] = queen;
            }
        } else if(queen[1] > king[1] && queen[0] > king[0] && (disX == disY)) {
            if(d < dis[1]) {
                dis[1] = d;
                temp[1] = queen;
            }
        } else if(queen[0] == king[0] && queen[1] > king[1]) {
            if(d < dis[2]) {
                dis[2] = d;
                temp[2] = queen;
            }
        } else if(queen[1] > king[1] && queen[0] < king[0] && (disX == disY)) {
            if(d < dis[3]) {
                dis[3] = d;
                temp[3] = queen;
            }
        } else if(queen[0] < king[0] && queen[1] == king[1]) {
            if(d < dis[4]) {
                dis[4] = d;
                temp[4] = queen;
            }
        } else if(queen[0] < king[0] && queen[1] < king[1] && (disX == disY)) {
            if(d < dis[5]) {
                dis[5] = d;
                temp[5] = queen;
            }
        } else if(queen[0] == king[0] && queen[1] < king[1]) {
            if(d < dis[6]) {
                dis[6] = d;
                temp[6] = queen;
            }
        } else if(queen[0] > king[0] && queen[1] < king[1] && (disX == disY)) {
            if(d < dis[7]) {
                dis[7] = d;
                temp[7] = queen;
            }
        }
    }
    std::vector<std::vector<int>> res;
    for(int i = 0; i < 8; ++i) {
        if(dis[i] != INT_MAX) {
            res.push_back(temp[i]);
        }
    }
    return res;
}