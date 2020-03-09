#include "headers.hpp"

int LeetCode::_0340_LongestSubstringWithAtMostKDistintCharacters::lengthOfLongestSubstringKDistinct(std::string s, int k) {
    if(k <= 0) {
        return 0;
    }
    std::unordered_map<char, int> map;
    int endidx = 0;
    int length = 0;
    int startidx = 0;
    for(; startidx < s.size(); ++startidx) {
        ++map[s[startidx]];
        length = std::max(length, startidx - endidx);
        while(map.size() > k && endidx < startidx) {
            --map[s[endidx]];
            if(map[s[endidx]] == 0) {
                map.erase(s[endidx]);
            }
            ++endidx;
        }
    }
    return map.size() > k ? length : std::max(length, startidx - endidx);
}