#include "headers.hpp"
#include <unordered_map>
int LeetCode::_0409_LongestPalindrome::longestPalindrome(std::string s) {
    std::unordered_map<char, int> M;
    for(char c : s) {
        ++M[c];
    }
    int length = 0;
    for(auto& m : M) {
        if(m.second % 2 == 0) {
            length += m.second;
            m.second = 0;
        } else {
            if(m.second >= 3) {
                length += ((m.second / 2) * 2);
                m.second = 1;                    
            }
        }
    }
    
    for(auto& m : M) {
        if(m.second == 1) {
            length += 1;
            break;
        }
    }
    return length;
}