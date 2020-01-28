#include "headers.hpp"

bool LeetCode::_1232_CheckIfItIsAStraightLine::checkStraightLine(std::vector<std::vector<int>>& coordinates) {
    for(int i = 1; i < coordinates.size() - 1; ++i) {
        int x1 = coordinates[i][0] - coordinates[i-1][0];
        int y1 = coordinates[i][1] - coordinates[i-1][1];
        int x2 = coordinates[i+1][0] - coordinates[i][0];
        int y2 = coordinates[i+1][1] - coordinates[i][1];
        
        if(x1 == 0) {
            if(x2 != 0) {
                return false;
            }
        } else {
            if(x2 == 0) {
                return false;
            } else {
                long long p1 = y2 * x1;
                long long p2 = x2 * y1;
                if (p1 != p2) {
                    return false;
                }
            }
        }
    }
    return true;
}