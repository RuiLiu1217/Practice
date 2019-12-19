#include "headers.hpp"
#include <cmath>
// It is very easy to come up with a solution with run time 
// O(n*sizeof(integer)). But can you do it in linear time 
// O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin 
// function like __builtin_popcount in c++ or in any other language.
std::vector<int> LeetCode::_0338_CountingBits::countBits(int num) {
    std::vector<int> res(num + 1, 0);
    
    if (num == 0) {
        return res;
    }
    if(num == 1) {
        res[1] = 1;
        return res;
    }

    res[1] = 1;
    int idx = 0;
    for(int i = 2; i <= num; ++i) {
        if(((i-1) & i) == 0) { // meet a perfect square number; == has higher priority than &
            ++idx;
        }
        res[i] = res[i - std::pow(2, idx)] + 1; // 数字 i 要比 数字 i - 2^idx 多一位 1
    }
    // [0, 1, 2, 3, 4, 5, 6, 7, 8]
    // [0, 1]
    // [0, 1, d=1] --> [0, 1, 0+1]                       i = 2
    // [0, 1, 1, r[1] + 1]                               i = 3
    // [0, 1, 1, 2, d=2] --> [0, 1, 1, 2, 0+1]           i = 4
    // [0, 1, 1, 2, 1, r[5-4] + 1]                       i = 5
    // [0, 1, 1, 2, 1, 2, 2]                             i = 6
    // [0, 1, 1, 2, 1, 2, 2, r[7-4]+1]                   i = 7
    return res;
}
