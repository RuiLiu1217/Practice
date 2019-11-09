#include "headers.hpp"

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
        res[i] = res[i - pow(2, idx)] + 1;
    }
    return res;
}
