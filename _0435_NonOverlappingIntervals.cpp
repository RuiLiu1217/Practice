#include "headers.hpp"
#include <algorithm>

int LeetCode::_0435_NonOverlappingIntervals::eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    auto comp = [](const std::vector<int>& i1, const std::vector<int>& i2){ return i1[0] < i2[0]; };
    std::sort(intervals.begin(), intervals.end(), comp);
    int res = 0;
    int pre = 0;
    for(int i = 1; i < intervals.size(); ++i) {
        if(intervals[i][0] < intervals[pre][1]) {
            ++res;
            if(intervals[i][1] < intervals[pre][1]) {
                pre = i;
            }
        } else {
            pre = i;
        }
    }
}