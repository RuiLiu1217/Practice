#include "headers.hpp"

bool LeetCode::_0231_PowerOfTwo::isPowerOfTwo(int n) {
    return (n > 0) && !(n & (n - 1));
}