#include "headers.hpp"

long long LintCode::_0002_TrailingZeros::trailingZeros(long long n) {
    long res = 0;
    long t = n;
    long fac = 5;
    while(fac < n) {
        res += t / fac;
        fac = fac * 5;
    }
    return res;
}