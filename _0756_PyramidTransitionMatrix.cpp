#include "headers.hpp"
#include <unordered_set>
#include <unordered_map>
bool LeetCode::_0756_PyramidTransitionMatrix::pyramidTransition(std::string bottom, std::vector<std::string>& allowed) {
    std::unordered_map<std::string, std::unordered_set<char>> Map;
    for(auto& s : allowed) {
        Map[s.substr(0, 2)].insert(s[2]);
    }
    
    return pyramidTransition(bottom, 0, "", Map);
    
}
bool LeetCode::_0756_PyramidTransitionMatrix::pyramidTransition(
    std::string bottom, int start, std::string res, std::unordered_map<std::string, std::unordered_set<char>>& Map) {
    if(bottom.size() == 1) {
        return true;
    }
    
    if(start == bottom.size() - 1) {
        bottom = res;
        res.clear();
        return pyramidTransition(bottom, 0, res, Map);
    }
    std::string key = bottom.substr(start, 2);
    if(Map.count(key) == 0) {
        return false;
    } else {
        bool result = false;
        for(char s : Map[key]) {
            res += s;
            bool t = pyramidTransition(bottom, start + 1, res, Map);
            if(t) {
                return true;
            } else {
                result |= t;
            }
            
            res.pop_back();
        }
        return result;
    }
}