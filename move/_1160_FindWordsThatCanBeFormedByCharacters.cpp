#include "headers.hpp"

int LeetCode::_1160_FindWordsThatCanBeFormedByCharacters::countCharacters(std::vector<std::string>& words, std::string chars) {
    std::unordered_map<char, int> ChMap;
    for(auto c : chars) {
        if (ChMap.find(c) == ChMap.end()) {
            ChMap[c] = 1;
        } else {
            ++ChMap[c];
        }
    }
    
    int totLength = 0;
    for(auto word : words) {
        std::unordered_map<char, int> tmpMap = ChMap;
        bool count = true;
        for(auto c : word) {
            if(tmpMap.find(c) == tmpMap.end() || tmpMap[c] == 0) {
                count = false;
                break;
            } else {
                --tmpMap[c];
            }
        }
        if(count) {
            totLength += word.size();
        }
    }
    return totLength;
}