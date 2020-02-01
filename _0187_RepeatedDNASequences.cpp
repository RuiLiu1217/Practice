#include "headers.hpp"
#include <unordered_map>
std::vector<std::string> LeetCode::_0187_RepeatedDNASequences::findRepeatedDNASequences(std::string s) {
    std::unordered_map<std::string, int> sMap;
    std::unordered_set<std::string> resSet;
    if(s.length() < 10) {
        return {};
    }

    for(int i = 0; i <= s.length() - 10; ++i) {
        std::string subStr = s.substr(i, 10);
        if(sMap.find(subStr) != sMap.end()) {
            resSet.insert(subStr);
        } else {
            sMap[subStr] = i;
        }
    }

    std::vector<std::string> result;
    for(auto su : resSet) {
        result.push_back(su);
    }
    return result;
}