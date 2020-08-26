#include "headers.hpp"

std::string _1370_IncreasingDecreasingString::sortString(std::string s) {
    std::vector<int> map(26, 0);
    int totalChars = s.size();
    for(char c : s) {
        ++map[c-'a'];
    }
    std::string res;
    int idx = 0;
    int flipIdx = 1;
    while(totalChars) {
        if(map[idx] > 0) {
            res += idx + 'a';
            --map[idx];
            --totalChars;
        }
        idx += flipIdx;
        if(idx == 26) {
            idx = 25;
            flipIdx = -1;
        } else if(idx == -1) {
            idx = 0;
            flipIdx = 1;
        }
    }
    return res;
}