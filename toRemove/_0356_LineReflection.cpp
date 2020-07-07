#include "headers.hpp"

bool LeetCode::_0356_LineReflection::isReflected(std::vector<std::vector<int>>& points) {
    if(points.size() == 0) {
        return true;
    }
    int minX = INT_MAX;
    int maxX = INT_MIN;
    std::unordered_set<std::string> pos;
    for(auto& point : points) {
        if(point[0] < minX) {
            minX = point[0];
        }
        if(point[0] > maxX) {
            maxX = point[0];
        }
        pos.insert(std::to_string(point[0]) + "_" + std::to_string(point[1]));
    }
    int mid_double = maxX + minX;
    for(auto& point : points) {
        int mirrx = mid_double - point[0];
        if(pos.find(std::to_string(mirrx) + "_" + std::to_string(point[1])) == pos.end()) {
            return false;
        }
    }
    return true;        
}