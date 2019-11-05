#include "headers.hpp"

int LeetCode::_0647_PalindromicSubstrings::countSubstrings(std::string s) {
    int sum = 0;
    for(int i = 0; i < s.size(); ++i) {
        sum += sub(s, i);
    }
    return sum;
}

int LeetCode::_0647_PalindromicSubstrings::sub(const std::string& s, int i) {
    int oddN = 1;
    int li = i-1;
    int ri = i+1;
    while(li >= 0 && ri < s.size()) {
        if(s[li] == s[ri]) {
            ++oddN;
        } else {
            break;
        }
        ++ri;
        --li;
    }
    
    int eveN = 0;
    int j = i+1;
    while(i >= 0 && j < s.size()) {
        if(s[i] == s[j]) {
            ++eveN;
        } else {
            break;
        }
        ++j;
        --i;
    }
    return oddN + eveN;
}