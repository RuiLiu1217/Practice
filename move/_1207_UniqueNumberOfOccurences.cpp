#include "headers.hpp"

bool LeetCode::_1207_UniqueNumberOfOccurances::uniqueOccurrences(std::vector<int>& arr) {
    std::unordered_map<int, int> mapNumToOccurance;
    std::unordered_map<int, int> mapOccuranceToNum;
    for(auto& a : arr) {
        ++mapNumToOccurance[a];
    }
    
    for(auto& m : mapNumToOccurance) {
        if(mapOccuranceToNum.find(m.second) != mapOccuranceToNum.end()) {
            return false;
        } else {
            mapOccuranceToNum[m.second] = m.first;
        }
    }
    return true;
}