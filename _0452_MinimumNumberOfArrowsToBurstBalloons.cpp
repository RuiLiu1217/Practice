#include "headers.hpp"
#include <algorithm>
int LeetCode::_0452_MinimumNumberOfArrowsToBusrtBalloons::findMinArrowShots(std::vector<std::vector<int>>& points) {
    if(points.empty()) {
        return 0;
    }
    std::sort(points.begin(), points.end(), [](const std::vector<int>& a,
    const std::vector<int>& b){
        return a[1] < b[1];
    });
    int right = points[0][0];
    int res = 0;
    for(auto& point : points) {
        if(point[0] > right) {
            ++res;
            right = point[1];
        }
    }
    return res;
}

