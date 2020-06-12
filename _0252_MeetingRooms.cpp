#include "headers.hpp"
#include <algorithm>

bool LeetCode::_0252_MeetingRooms::canAttendMeetings(std::vector<std::vector<int>>& intervals) {
    std::sort(begin(intervals), end(intervals), [](std::vector<int>& a, std::vector<int>& b){
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    });

    for(int i = 1; i < intervals.size(); ++i) {
        if(intervals[i][0] < intervals[i-1][1]) {
            return false;
        }
    }
    return true;
}