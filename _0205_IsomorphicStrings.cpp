#include "headers.hpp"
#include <map>
#include <string>
bool LeetCode::_0205_IsomorphicStrings::isIsomorphic(std::string s, std::string t) {
    if(s.size() != t.size()) {
        return false;
    }
    std::map<char, char> strMap;
    std::map<char, char> strMap2;
    for(int i = 0; i != s.size(); ++i) {
        auto iter = strMap.find(s[i]);
        auto iter2 = strMap2.find(t[i]);
        if(iter == strMap.end()) {
            strMap.insert(std::pair<char,char>(s[i],t[i]));
        } else {
            if (iter->second != t[i]) {
                return false;
            }
        }
        if(iter2 == strMap2.end()) {
            strMap2.insert(std::pair<char,char>(t[i], s[i]));
        } else {
            if(iter2->second != s[i]) {
                return false;
            }
        }
    }
    return true;
}