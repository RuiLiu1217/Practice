#include "headers.hpp"

double LeetCode::_1344_AngleBetweenHandsOfAClock::angleClock(int hour, int minutes) {
    double hpos = hour * 30 + 0.5 * minutes;
    double mpos = 6.0 * minutes;
    double posDiff = std::abs(mpos - hpos);
    if (posDiff > 180.0) {
        posDiff = 360.0 - posDiff;
    }
    return posDiff;
}