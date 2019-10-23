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
}

