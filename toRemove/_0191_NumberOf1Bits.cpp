#include "headers.hpp"
// Bit operations
int LeetCode::_0191_NumberOf1Bits::hammingWeight(uint32_t n) {
    int res = 0;
    while(n) {
        res += (n & 1);
        n >>= 1;
    }
    return res;
}