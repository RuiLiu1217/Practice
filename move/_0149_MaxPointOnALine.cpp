#include "headers.hpp"
#include <vector>
#include <unordered_map>
#include <iterator>

// Tag: hash, but I don't think it is a good problem
// TODO

int LeetCode::_0149_MaxPointsOnALine::maxPoints(std::vector<std::vector<int>>& points) {
    std::unordered_map<float, int> statistic; // slope --> number of lines;
    int maxNum = 0;
    for(int i = 0; i < points.size(); ++i) {
        statistic.clear();
        statistic[INT_MIN] = 0; // for processing duplicate point
        int duplicate = 1;
        for(int j = i + 1; j < points.size(); ++j) {
            if(j == i) {
                continue;
            }
            if(points[j][0] == points[i][0] && points[j][1] == points[i][1]) { // count duplicate;
                duplicate++;
                continue;
            }

            float key = (points[j][0] - points[i][0] == 0)?INT_MAX : (float) (points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
            ++statistic[key];
        }

        for(auto el : statistic) {
            if(el.second + duplicate > maxNum) {
                maxNum = el.second + duplicate;
            }
        }
    }
    return maxNum;

}