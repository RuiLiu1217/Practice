#include "headers.hpp"

// it looks like a DP problem, but actually it is a Binary Search Problem
// Calculate how many numbers from 1 to num are divisble by either a, b or c
// using the formula:
// num / a + num / b + num / c - num / lcm(ab) - num / lcm(bc) - num / lcm(ac) + num / lcm(abc)
int LeetCode::_1201_UglyNumberIII::nthUglyNumber(int n, int a, int b, int c) {
    
    int left = 0;
    int right = INT_MAX;
    int result = 0;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(count(mid, a, b, c) >= n) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}


long long LeetCode::_1201_UglyNumberIII::gcb(long long a, long long b) {
    if(a == 0) {
        return b;
    }
    return gcb(b % a, a);
}

long long LeetCode::_1201_UglyNumberIII::lcm(long long a, long long b) {
    long long ab = gcb(a, b);
    return a * b / ab;
}

// 算有多少个数能够被三个数至少一个整除。
int LeetCode::_1201_UglyNumberIII::count(long long num, long long a, long long b, long long c) {
    long long lab = lcm(a, b);
    long long lbc = lcm(b, c);
    long long lac = lcm(a, c);
    long long labc = lcm(a, lbc);
    return int(num / a + num / b + num / c - num / lab - num / lac - num / lbc + num / labc);
}