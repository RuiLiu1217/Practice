#include "headers.hpp"

int LeetCode::_0357_CountNumbersWithUniqueDigits::countNumbersWithUniqueDigits(int n) {
    if(n == 0) {
        return 1;
    }
    int res = 0;
    for(int k = 1; k <= n; ++k) {
        res += countExactDigit(k);
    }
    return res;
}

int LeetCode::_0357_CountNumbersWithUniqueDigits::countExactDigit(int n) {
    if (n == 1)
    {
        return 10;
    }
    // 9 * 9 * 8 * ... (9 - k + 2)
    int res = 9;
    for (int i = 2; i <= n; ++i)
    {
        int t = (9 - i + 2) >= 0 ? (9 - i + 2) : 0;
        res *= t;
    }
    return res;
}
