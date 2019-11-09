#include "headers.hpp"

int LeetCode::_0172_FactorialTrailingZeroes::trailingZeroes(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}