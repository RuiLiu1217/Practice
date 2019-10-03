#include "headers.hpp"

int LeetCode::_0058_LengthOfLastWord::lengthOfLastWord(std::string s) {
    int len = 0;
    int t = s.size() - 1;
    while(t >= 0 && s[t] == ' ') {
        --t;
    }
    while(t >= 0 && s[t] != ' ') {
        ++len;
        --t;
    }
    return len;
}