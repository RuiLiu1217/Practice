#include "headers.hpp"

std::string LeetCode::_0038_CountAndSay::countAndSay(int n) {
    std::string s = "1";
    for(int i = 0; i < n; ++i) {
        s = countOnce(s);
    }
    return s;
}

std::string LeetCode::_0038_CountAndSay::countOnce(std::string& s) {
    int i = 0;
    int j = 0;
    std::string res;
    int c = 0;
    while(i < s.size()) {
        c = 0;
        while(j < s.size() && s[i] == s[j]) {
            ++j;
            ++c;
        }

        res += std::to_string(c);
        res += s[i];
        i = j;
    }
    return res;
}