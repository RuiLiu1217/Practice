#include "headers.hpp"

int LeetCode::_0201_BitwiseANDofNumbersRange::rangeBitwiseAnd(int m, int n) {
    while(m < n) {
        n = n & (n - 1);
    }
    return m & n;
}