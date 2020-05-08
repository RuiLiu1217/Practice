#include "headers.hpp"
#include <algorithm>
#include <math.h>
bool LeetCode::_0633_SumOfSquareNumbers::judgeSquareSum(int c) {
    int hc = c / 2;
    for(int i = 0; i * i <= hc; ++i) {
        int res = c - i * i;
        int f = std::floor(std::sqrt(res));
        if (f * f == res) {
            return true;
        }
    }
    return false;
}