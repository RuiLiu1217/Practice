#include "headers.hpp"
#include <unordered_map>

bool LeetCode::_0383_RansomNote::canConstruct(std::string ransomNote, std::string magazine) {
    if(ransomNote.size() > magazine.size()) {
        return false;
    }
    
    std::unordered_map<char, int> magMap;
    for(char c : magazine) {
        ++magMap[c];
    }
    
    for(char c : ransomNote) {
        if(magMap[c] <= 0) {
            return false;
        } else {
            --magMap[c];
        }
    }
    return true;
}
