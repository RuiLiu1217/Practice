#include "headers.hpp"
#include <unordered_map>

static bool replaceAble(const std::string& S, int index, const std::string& source) {
    const int l = source.size();
    if(index >= S.size()) {
        return false;
    }
    if(S.substr(index, l) == source) {
        return true;
    }
    return false;
}

std::string LeetCode::_0833_FindAndReplaceInString::findReplaceString(
    std::string S, std::vector<int>& indexes, 
    std::vector<std::string>& sources,
    std::vector<std::string>& targets) {

    std::unordered_map<int, std::pair<std::string, std::string>> startIndex;
    for(int i = 0; i < indexes.size(); ++i) {
        if(replaceAble(S, indexes[i], sources[i])) {
            startIndex.insert({indexes[i], {targets[i], sources[i]}});
        }
    }

    std::string result;
    for(int i = 0; i < S.size();) {
        if(startIndex.find(i) != startIndex.end()) {
            result += startIndex[i].first;
            i += startIndex[i].second.size();
        } else {
            result += S[i];
            ++i;
        }
    }
    return result;
}