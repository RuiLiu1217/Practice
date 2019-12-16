#include "headers.hpp"

static bool isEqual(char *a, char *b) {
    for(int i = 0; i < 26; ++i) {
        if(a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool LeetCode::_0567_PermutationInString::checkInclusion(std::string s1, std::string s2) {
    const int patLen = s1.size();
    char pat[26] = {0};
    for(int i = 0; i < s1.size(); ++i) {
        ++pat[s1[i] - 'a'];
    }
    
    char exp[26] = {0};
    if(s2.size() < s1.size()) {
        return false;
    }
    int i = 0;
    for(; i < s1.size(); ++i) {
        ++exp[s2[i] - 'a'];
    }
    const int N = s1.size();
    while(i < s2.size()) {
        if(isEqual(pat, exp)) {
            return true;
        }
        --exp[s2[i-N] - 'a'];
        ++exp[s2[i] - 'a'];
        ++i;
    }
    return isEqual(pat, exp);
}