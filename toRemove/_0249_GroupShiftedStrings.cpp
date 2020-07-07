#include "headers.hpp"

std::vector<std::vector<std::string>> LeetCode::_0249_GroupShiftedStrings::groupStrings(std::vector<std::string>& strings) {
    std::unordered_map<std::string, std::vector<std::string>> map;
    for(std::string& s : strings) {
        std::string ts = transback(s);
        map[ts].push_back(s);
    }
    std::vector<std::vector<std::string>> res;
    for(auto& m : map) {
        res.push_back(m.second);
    }
    return res;
}
  
std::string LeetCode::_0249_GroupShiftedStrings::transback(std::string& s) {
    int l = s[0] - 'a';
    std::string res;
    for(auto& c : s) {
        res += static_cast<char>((c - l + 26) % 26);
    }
    return res;
}