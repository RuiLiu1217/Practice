#include "headers.hpp"

// Totally maths problem
bool LeetCode::_0326_PowerOfThree::isPowerOfThree(int n) {
    return (n > 0 && (1162261467 % n == 0)); // 32-bit integer the largest 3^n is 1162261467
}