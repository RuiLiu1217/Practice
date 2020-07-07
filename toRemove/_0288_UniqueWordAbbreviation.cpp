#include "headers.hpp"
// Copy from solution. I don't know how the algorithm works
LeetCode::_0288_UniqueWordAbbreviation::_0288_UniqueWordAbbreviation(std::vector<std::string>& dictionary) {
    for(std::string& d : dictionary) {
        int n = d.length();
        std::string abbr = d[0] + std::to_string(n) + d[n - 1];
        mp[abbr].insert(d);
    }
}
bool LeetCode::_0288_UniqueWordAbbreviation::isUnique(std::string word) {
    int n = word.length();
	std::string abbr = word[0] + std::to_string(n) + word[n - 1];
    return mp[abbr].count(word) == mp[abbr].size();
}
