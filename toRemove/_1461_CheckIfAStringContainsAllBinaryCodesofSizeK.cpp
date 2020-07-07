#include "headers.hpp"
#include <cmath>

bool LeetCode::_1461_CheckIfAStringContainsAllBinaryCodesofSizeK::hasAllCodes(std::string s, int k) {
    long long binaries = std::pow(2, k);
    if(s.size() < k || s.size() - k + 1 < binaries) {
        return false;
    }
    std::unordered_set<std::string> set;
    for(int i = 0; i < s.size() - k + 1; ++i) {
        set.insert(s.substr(i, k));
    }
    return set.size() == binaries;
}