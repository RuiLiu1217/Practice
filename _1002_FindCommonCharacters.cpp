#include "headers.hpp"
#include <map>
static std::map<char, int> createMap(const std::string& a) {
    std::map<char, int> res;
    for(int i = 0; i < a.size(); ++i)
    {
        if(res.find(a[i]) == res.end()) {
            res.insert(std::make_pair(a[i], 1));
        } else {
            res[a[i]]++;
        }
    }
    return res;
}
    
static std::map<char, int> intersectMap(const std::map<char, int>& a, const std::map<char, int>& b) {
    std::map<char, int> res;
    for(int i = 0; i < 26; ++i) {
        char t = static_cast<char>('a' + i);
        if(a.find(t) != a.end() && b.find(t) != b.end()) {
            res.insert(std::make_pair(t, std::min(a.at(t), b.at(t))));
        }
    }
    return res;
}


std::vector<std::string> LeetCode::_1002_FindCommonCharacters::commonChars(std::vector<std::string>& A) {
    std::map<char, int> res = createMap(A[0]);
    for(int i = 1; i < A.size(); ++i) {
        res = intersectMap(res, createMap(A[i]));
    }
    
    std::vector<std::string> ret;
    for(auto a : res) {
        for(int i = 0; i < a.second; ++i) {
            std::string c{a.first};
            ret.push_back(c);
        }
    }
    return ret;
}