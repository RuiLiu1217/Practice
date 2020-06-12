#include "headers.hpp"

bool LeetCode::_0266_PalinndromePermutation::canPermutePalindrome(std::string s) {
    std::vector<int> charMap(256, 0);
    for(char c : s) {
        if(charMap[c] == 1) {
            --charMap[c];
        } else {
            charMap[c] = 1;
        }
    }

    int countOne = 0;
    for(int i = 0; i < 256; ++i) {
        if(charMap[i] == 1) {
            ++countOne;
            if(countOne > 1) {
                return false;
            }
        }
    }
    return true;
}