#include "headers.hpp"
#include <algorithm>
std::vector<std::vector<int>> LeetCode::_0056_MergeIntervals::merge(std::vector<std::vector<int>>& intervals) {
    if(intervals.size() == 0) {
        return {};
    }
    std::sort(intervals.begin(), intervals.end(), [](auto a, auto b){
        return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1]));
    });
    
    int slow = 0;
    int fast = 0;
    for(fast = 0; fast < intervals.size(); ++fast) {
        if(intervals[slow][1] >= intervals[fast][0]) {
            intervals[slow][1] = std::max(intervals[slow][1],
                                            intervals[fast][1]);
        } else {
            intervals[++slow] = intervals[fast];
        }
    }
    intervals.resize(slow+1);
    return intervals;
}
