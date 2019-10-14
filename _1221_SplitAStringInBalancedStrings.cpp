#include "headers.hpp"

int LeetCode::_1221_SplitAStringInBalancedStrings::balancedStringSplit(std::string s) {
    int cnt = 0;
    int i = 0; 
    char pre = s[0];
    int bal = 0;
    while(i < s.size()) {
        if(s[i] == pre) {
            ++bal;
        } else {
            --bal;
        }
        if(bal == 0) {
            ++cnt;
        }
        if(bal < 0) {
            pre = s[i];
            bal = 1;
        }
        ++i;
    }
    return cnt;
}

