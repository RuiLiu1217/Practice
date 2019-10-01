#include "headers.hpp"

int LeetCode::_0028_ImplementStrStr::strStr(std::string& haystack, std::string& needle) {
    const int lenHaystack = haystack.length();
    const int lenNeedle = needle.length();
    if(lenHaystack < lenNeedle) {
        return -1;
    }

    const int lasStartPos = lenHaystack - lenNeedle;
    for(int startIdx = 0; startIdx <= lasStartPos; ++startIdx) {
        int curIdx = 0;
        while(haystack[startIdx + curIdx] == needle[curIdx] && curIdx < lenNeedle) {
            ++curIdx;
        }
        if(curIdx == lenNeedle) {
            return startIdx;
        }
    }
    return -1;
}
