#include "headers.hpp"
#include <algorithm>
/*
Type: Array
*/
std::vector<int> LeetCode::_0066_PlusOne::plusOne(std::vector<int>& digits) {
    std::vector<int> res = digits;
    std::reverse(res.begin(), res.end());
    int i = 0;
    bool flag = true;

    while(i < res.size()) {
        res[i] += flag;
        if(res[i] < 10) {
            std::reverse(res.begin(), res.end());
            return res;
        } else {
            res[i] -= 10;
            ++i;
            flag = true;
        }
    }

    if(flag) {
        res.push_back(1);
    }
    std::reverse(res.begin(), res.end());
    return res;
}
