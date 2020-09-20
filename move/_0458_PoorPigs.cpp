#include "headers.hpp"
#include <math.h>

// https://www.cnblogs.com/grandyang/p/7664088.html

int LeetCode::_0458_PoorPigs::poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    return std::ceil(std::log(buckets) / std::log(minutesToTest / minutesToDie + 1));
}