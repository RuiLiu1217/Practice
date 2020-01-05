#include "headers.hpp"

std::vector<int> LeetCode::_1304_FindNUniqueIntegersSumupToZero::sumZero(int n) {
    if(n == 1) {
        return {0};
    } else if(n == 2) {
        return {-1, 1};
    } else {
        std::vector<int> cur = sumZero(n - 2);
        cur.push_back(n);
        cur.push_back(-n);
        return cur;
    }
}