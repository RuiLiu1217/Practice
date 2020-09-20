#include "headers.hpp"

std::vector<bool> LeetCode::_1018_BinaryPrefixDivisibleBy5::prefixesDivBy5(std::vector<int>& A) {
    int num = 0;
    std::vector<bool> res;
    res.reserve(A.size());
    for(int a : A) {
        if(num > 100000) {
            num -= 100000;
        }
        num <<= 1;
        num += a;
        res.push_back(!(num % 5));
    }
    return res;
}