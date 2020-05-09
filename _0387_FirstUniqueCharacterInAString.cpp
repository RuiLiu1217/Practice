#include "headers.hpp"

int LeetCode::_0387_FirstUniqueCharacterInAString::firstUniqChar(std::string s) {
    std::vector<std::pair<int, int>> index(26);
    for(int i = 0; i < s.size(); ++i) {
        if(index[s[i] - 'a'].second == 0) {
            index[s[i] - 'a'] = {i, 1};
        } else {
            ++index[s[i] - 'a'].second;
        }
    }
    int idx = INT_MAX;
    for(int i = 0; i < 26; ++i) {
        if(index[i].second == 1) {
            idx = std::min(idx, index[i].first);
        }
    }
    return idx == INT_MAX ? -1 : idx;
}