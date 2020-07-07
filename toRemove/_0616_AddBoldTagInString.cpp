#include "headers.hpp"

// use mask to help solve problems
// we can also use the interval merge technique to solve it.
std::string LeetCode::_0616_AddBoldTagInString::addBoldTag(std::string s, std::vector<std::string>& dict) {
    std::vector<bool> isBold(s.length(), false);
    for(int i = 0; i < s.length(); ++i) {
        for(std::string& w : dict) {
            int wl = w.length();
            if(s.substr(i, wl) == w) {
                for(int t = 0; t < wl; ++t) {
                    if(t + i < s.length()) {
                        isBold[t + i] = true;
                    }
                }
            }
        }
    }
    
    std::string res;
    for(int i = 0; i < s.length(); ++i) {
        if(!isBold[i]) {
            res += s[i];
            continue;
        }
        int j = i;
        while(j < s.length() && isBold[j]) {
            ++j;
        }
        res += "<b>" + s.substr(i, j - i) + "</b>";
        i = j - 1;
    }
    return res;
}