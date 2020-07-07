#include "headers.hpp"
int LeetCode::_1247_MinimumSwapsToMakeStringsEqual::minimumSwap(std::string s1, std::string s2) {
    int count[2] = {0};
    if(s1 == s2) {
        return 0;
    }
    if(s1.size() != s2.size()) {
        return -1;
    }
    for(int i = 0; i < s1.size(); ++i) {
        if(s1[i] != s2[i]) {
            if(s1[i] == 'x') {
                ++count[0];
            } else if(s1[i] == 'y') {
                ++count[1];
            }
        }
    }
    if((count[0] + count[1]) % 2) {
        return -1;
    }

    int c = 0;
    while(count[0] >= 2) {
        count[0] -= 2;
        ++c;
    }
    while(count[1] >= 2) {
        count[1] -= 2;
        ++c;
    }
    if(count[0] == 1 && count[1] == 1) {
        c += 2;
    } 
    return c == 0?-1:c;
}