#include "headers.hpp"
#include <bitset>

// This problem is to practice to use the library bitset
uint32_t _0190_ReverseBits::reverseBits(uint32_t n) {
    std::bitset<32> bit(n);
    std::bitset<32> ans;
    for (int i = 0; i < 32; ++i)
    {
        ans[i] = bit[32 - i];
    }
    return ans.to_ullong();
}
