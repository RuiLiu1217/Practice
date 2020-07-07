#include "headers.hpp"

int LeetCode::_0159_LongestSubstringWithAtMostTwoDistinctCharacters::lengthOfLongestSubstringTwoDistinct(std::string s) {
    std::unordered_map<char, int> map;
    int back = 0;
    int length = -1;
    for(int i = 0; i < s.size(); ++i) {
        ++map[s[i]];
        while(map.size() > 2 && back < i) {
            --map[s[back]];
            if(map[s[back]] == 0) {
                map.erase(s[back]);
            }
            ++back;
        }
        length = std::max(length, i - back + 1);
    }
    return length == -1 ? 0 : length; // edge case that the string is empty
}