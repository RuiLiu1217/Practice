#include "headers.hpp"

// Facebook 

std::vector<int> LeetCode::_0438_FindAllAnagramsInAString::findAnagrams(std::string s, std::string p) {
    std::vector<int> sv(26, 0);
    std::vector<int> pv(26, 0);
    
    std::vector<int> res;
    if(s.size() < p.size())
        return res;
    
    for(int i = 0; i < p.size(); ++i) {
        ++sv[s[i] - 'a'];
        ++pv[p[i] - 'a'];
    }
    if(pv == sv) {
        res.push_back(0);
    }
    
    for(size_t i = p.size(); i < s.size(); ++i)
    {
        ++sv[s[i] - 'a'];
        --sv[s[i-p.size()] - 'a'];
        if(sv == pv)
        {
            res.push_back(i-p.size()+1);
        }
    }
    return res;        
}