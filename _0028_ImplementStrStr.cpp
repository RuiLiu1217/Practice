#include "headers.hpp"

/*
Google
*/
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

// Based on the KMP algorithm
int strStr(std::string haystack, std::string needle) {
    int m = haystack.size();
    int n = needle.size();
    if(!n) {
        return 0;
    }

    std::vector<int> lps = kmpProcess(needle);
    for(int i = 0, j = 0; i < m; ) {
        if(haystack[i] == needle[j]) {
            ++i;
            ++j;
        }
        if(j == n) {
            return i - j;
        }
        if(i < m && haystack[i] != needle[j]) {
            j ? j = lps[j - 1] : i++;
        }
    }
    return -1;
}


std::vector<int> kmpProcess(std::string needle) {
    int n = needle.size();
    std::vector<int> lps(n, 0);
    for(int i = 1, len = 0; i < n; ) {
        if(needle[i] == needle[len]) {
            lps[i++] = ++len;
        } else if(len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0
        }
    }
    return lps;
}