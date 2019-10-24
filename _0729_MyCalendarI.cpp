#include "headers.hpp"
// 抄答案的，需要重新再看几次.
bool LeetCode::_0729_MyCalendarI::book(int start, int end) {
    auto it = booked.lower_bound(start); // return ceiling value key >= start
    if(it != booked.cend() && it->first < end) {
        return false;
    }
    if(it != booked.cbegin() && (--it)->second > start) {
        return false;
    }
    booked[start] = end;
    return true;
}