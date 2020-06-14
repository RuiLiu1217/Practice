#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_1065_IndexPairOfAString::indexPairs(std::string text, std::vector<std::string>& words) {
    std::unordered_set<std::string> wordSet(begin(words), end(words));
    std::unordered_set<int> lengthSet;        
    for(auto& w : wordSet) {
        lengthSet.insert(w.size());
    }
    std::vector<std::vector<int>> res;
    for(int i = 0; i < text.size(); ++i) {
        for(int l : lengthSet) {
            if(wordSet.count(text.substr(i, l)) && i + l <= text.size()) {
                res.push_back({i, i+l-1});
            }
        }
    }
    std::sort(begin(res), end(res));
    return res;
}