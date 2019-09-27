#include "headers.hpp"


std::string LeetCode::_0005_LongestPalindromicSubstring::longestPalidrome(std::string s) {
    if(s.size() == 0) {
        return "";
    }
    int start = 0;
    int end = 0;
    for(int i = 0; i < s.size(); ++i) {
        int len1 = expandAroundCenter(s, i, i); // Expand with one core center;
        int len2 = expandAroundCenter(s, i, i + 1); // Expand with neighbor same;
        int l = std::max(len1, len2);
        if(l > end - start) {
            start = i - (l - 1) / 2; // The difficulty is how to calculate the start and end index according to the given center index
            end = i + l / 2;
        }
    }
    return s.substr(start, end - start + 1);
}
    
int LeetCode::_0005_LongestPalindromicSubstring::expandAroundCenter(std::string& s, int i , int j) {
    while(i >= 0 && j < s.size() && s[i] == s[j]) {
        --i;
        ++j;
    }
    return j - i - 1; // not + 1 because both i and j are one step outside the palindromic.
}
