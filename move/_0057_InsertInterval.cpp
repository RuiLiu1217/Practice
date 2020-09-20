#include "headers.hpp"
#include <algorithm>

/*
Type : Array
*/
std::vector<std::vector<int>> LeetCode::_0057_InsertInterval::insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
    int i = 0;
    std::vector<std::vector<int>> res;
    bool inserted = false;
    while(i < intervals.size()) {
        if(!inserted) {
            if(intersect(intervals[i], newInterval)) {
                newInterval[0] = std::min(intervals[i][0], newInterval[0]);
                newInterval[1] = std::max(intervals[i][1], newInterval[1]);
            } else {
                if(newIntervalSmaller(newInterval, intervals[i])) {
                    res.push_back(newInterval);
                    inserted = true;
                    res.push_back(intervals[i]);
                } else {
                    res.push_back(intervals[i]);
                }
                
            }
        } else {
            res.push_back(intervals[i]);
        }
        ++i;            
    }
    if(!inserted) {
        res.push_back(newInterval);
    }
    return res;
}
bool LeetCode::_0057_InsertInterval::newIntervalSmaller(const std::vector<int>& a, const std::vector<int>& b) {
    return a[0] < b[0];
}
bool LeetCode::_0057_InsertInterval::intersect(const std::vector<int>& a,const std::vector<int>& b) {
    if (b[0] <= a[1] && b[0] >= a[0]) {
        return true;
    }
    if (b[1] >= a[0] && b[1] <= a[1]) {
        return true;
    }
    if(b[0] <= a[0] && b[1] >= a[1]) {
        return true;
    }
    if(a[0] <= b[0] && a[1] >= b[1]) {
        return true;
    }
    return false;
}