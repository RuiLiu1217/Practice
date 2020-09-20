#include "headers.hpp"

 int LeetCode::_1266_MinimumTimeVisitingAllPoints::minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
    int res = 0;
    for(int i = 1 ;i < points.size(); ++i) {
        res += std::max(std::abs(points[i][0] - points[i-1][0]), std::abs(points[i][1] - points[i-1][1]));
    }
    return res;
}