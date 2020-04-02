#include "headers.hpp"

// Facebook 

std::vector<int> LeetCode::_0438_FindAllAnagramsInAString::findAnagrams(std::string s, std::string p) {
    std::vector<int> sv(256, 0);
    std::vector<int> pv(256, 0);

    std::vector<int> res;
    if(s.size() < p.size()) {
        return res;
    }

    for(int i = 0; i < p.size(); ++i) {
        ++sv[s[i]];
        ++pv[p[i]]; // initialize the map;
    }

    if(pv == sv) {
        res.push_back(0);
    }
    for(size_t i = p.size(); i < s.size(); ++i) {
        ++sv[s[i]];
        --sv[s[i-p.size()]]; // update the map of s in slide window 
        if(sv == pv) {
            res.push_back(i - p.size() + 1);
        }
    }
    return res;
}