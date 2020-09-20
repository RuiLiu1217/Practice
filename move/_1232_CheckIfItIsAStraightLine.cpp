#include "headers.hpp"

bool LeetCode::_1232_CheckIfItIsAStraightLine::checkStraightLine(std::vector<std::vector<int>>& coordinates) {
    if(coordinates.size() <= 2) {
        return true;
    }
    
    const int difx = coordinates[1][0] - coordinates[0][0];
    const int dify = coordinates[1][1] - coordinates[0][1];
    for(int i = 2; i < coordinates.size(); ++i) {
        int dx = coordinates[i][0] - coordinates[i-1][0];
        int dy = coordinates[i][1] - coordinates[i-1][1];
        
        if(difx == 0) {
            if(dx != 0) {
                return false;
            }
        }
        if(dify == 0) {
            if(dy != 0) {
                return false;
            }
        }
        if (dify * dx != dy * difx) {
            return false;
        }
    }
    return true;
}