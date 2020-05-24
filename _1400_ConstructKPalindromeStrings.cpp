#include "headers.hpp"
#include <bitset>
bool LeetCode::_1400_ConstructKPalindromeStrings::canConstruct(std::string s, int k) {
    std::bitset<26> odd;
    for(char c : s) {
        odd.flip(c - 'a');
    }
    return odd.count() <= k && s.length() >= k;
}