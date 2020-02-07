#include "headers.hpp"
#include <bitset>

// This problem is to practice to use the library bitset
uint32_t LeetCode::_0190_ReverseBits::reverseBits(uint32_t n) {
    std::bitset<32> bit(n);
    std::bitset<32> ans;
    for (int i = 0; i < 32; ++i)
    {
        ans[i] = bit[32 - i];
    }
    return ans.to_ullong();
}

/*
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res;
        int t= 32;
        while(t) {
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
            --t;
        }
        return res;
    }
};
*/