#include "headers.hpp"

bool LeetCode::_0242_ValidAnagram::isAnagram(std::string s, std::string t) {
    int c1[26] = {0};
    int c2[26] = {0};
    if(s.size() != t.size()) {
        return false;
    }
    for(int i = 0; i < s.size(); ++i) {
        ++c1[s[i] - 'a'];
        ++c2[t[i] - 'a'];
    }
    for(int i = 0; i < 26; ++i) {
        if(c1[i] != c2[i]) {
            return false;
        }
    }
    return true;
}