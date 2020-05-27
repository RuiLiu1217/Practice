#include "headers.hpp"

std::string LeetCode::_0451_SortCharactersByFrequency::frequencySort(std::string s) {
    std::unordered_map<char, int> f;
    for(char c : s) {
        ++f[c];
    }
    std::vector<std::pair<char,int>> st(begin(f), end(f));
    
    std::sort(st.begin(), st.end(), [&](auto& v1, auto& v2){return v1.second > v2.second;});
    
    std::string res;
    for(auto& s : st) {
        res += std::string(s.second, s.first);
    }
    return res;
}