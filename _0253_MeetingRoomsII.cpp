#include "headers.hpp"

int LeetCode::_0253_MeetingRoomsII::minMeetingRooms(std::vector<std::vector<int>>& intervals) {
    std::vector<int> startEvents;
    std::vector<int> endEvents;
    for(int i = 0; i < intervals.size(); ++i) {
        startEvents.push_back(intervals[i][0]);
        endEvents.push_back(intervals[i][1]);
    }
    std::sort(begin(startEvents), end(startEvents));
    std::sort(begin(endEvents), end(endEvents));
    int numOfRooms = 0;
    int endIter = 0;
    for(int i = 0; i < intervals.size(); ++i) {
        if(startEvents[i] < endEvents[endIter]) { // if the next meeting start before the last one end, need another meeting room.
            ++numOfRooms;
        } else {
            ++endIter;
        }
    }
    return numOfRooms;
}