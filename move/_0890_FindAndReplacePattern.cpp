#include "headers.hpp"
#include <map>

static std::string TransString(const std::string& pattern) {
    std::map<char, char> patMap;
    char v = 'A';
    std::string res = pattern;
    for(int i = 0; i < pattern.size(); ++i) {
        auto chIdx = patMap.find(pattern[i]);
        if(chIdx == patMap.end()) {
            res[i] = v;
            patMap.insert(std::make_pair(pattern[i], v));
            ++v;
        } else {
            res[i] = (*chIdx).second;
        }
    }
    return res;
}

std::vector<std::string> LeetCode::_0890_FindAndReplacePattern::findAndReplacePattern(std::vector<std::string>& words, std::string pattern) {
    std::string transPat = TransString(pattern);
    std::vector<std::string> res;
    res.reserve(words.size());
    const int sz = pattern.size();
    for(int i = 0; i < words.size(); ++i) {
        if(sz != words[i].size()) {
            continue;
        }
        if(TransString(words[i]) == transPat) {
            res.push_back(words[i]);
        }
    }
    return res;
}