#include "LeetCode_HashProblems.hpp"
#include <unordered_map>
#include <algorithm>
std::vector<std::vector<std::string>> LC::_0049_GroupAnagrams::groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, int> mySet;
    std::vector<std::vector<std::string>> res;
    int idx = 0;
    for(auto & s : strs) {
        std::string ss = s;
        std::sort(ss.begin(), ss.end());
        auto iter = mySet.find(ss);
        if(iter == mySet.end()) {
            mySet[ss] = idx;
            res.push_back(std::vector<std::string>());
            res[idx].push_back(s);
            idx++;
        } else {
            res[iter->second].push_back(s);
        }
    }
    return res;
}