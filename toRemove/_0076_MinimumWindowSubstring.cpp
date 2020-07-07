#include "headers.hpp"
#define ALPHALEN 256

// Facebook

 bool isLargerOrEqual(const std::vector<int>& tMap, std::vector<int>& cur) {
    for(int i = 0; i < 256; ++i) {
        if(tMap[i] > cur[i]) {
            return false;
        }
    }
    return true;
}
std::string LeetCode::_0076_MinimumWindowSubstring::minWindow(std::string s, std::string t) {
    std::vector<int> tMap(256, 0);
    for(char c : t) {
        ++tMap[static_cast<int>(c)];
    }
    
    std::vector<int> curMap(256, 0);
    int tail = 0;
    int length = INT_MAX;
    std::string res;
    for(int i = 0; i < s.size(); ++i) {
        ++curMap[s[i]];
        while(isLargerOrEqual(tMap, curMap)) {
            if(i - tail + 1 < length) {
                length = std::min(length, i - tail + 1);
                res = s.substr(tail, i - tail + 1);
            }
            
            --curMap[s[tail]];
            ++tail;
        }
    }
    return res;
}