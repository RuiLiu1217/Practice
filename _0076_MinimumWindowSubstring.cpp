#include "headers.hpp"
#define ALPHALEN 256

template<bool returnVal>
static bool isSmaller(const std::vector<int>& countS,const std::vector<int>& countT) {
    for(int i = 0; i < ALPHALEN; ++i) {
        if(countS[i] < countT[i]) {
            return returnVal;
        }
    }
    return !returnVal;
}
std::string LeetCode::_0076_MinimumWindowSubstring::minWindow(std::string s, std::string t) {
    int startIdx = 0;
    int endIdx = 0;
    std::vector<int> countS(ALPHALEN, 0);
    std::vector<int> countT(ALPHALEN, 0);
    
    for(int i = 0; i < t.size(); ++i) {
        ++countT[static_cast<size_t>(t[i])];
    }
    
    int minWindow = INT_MAX;
    std::string res;
    while(endIdx < s.size()) {
        while(endIdx < s.size() && isSmaller<true>(countS, countT)) {
            ++countS[static_cast<size_t>(s[endIdx++])];
        }
        
        while(startIdx < endIdx &&  isSmaller<false>(countS, countT)) {
            if (minWindow > endIdx - startIdx) {
                minWindow = endIdx - startIdx;
                res = s.substr(startIdx, endIdx - startIdx);
            }
            --countS[static_cast<int>(s[startIdx++])];
        }
    }
    return res;
}