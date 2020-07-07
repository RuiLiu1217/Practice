#include "headers.hpp"

LeetCode::_0676_ImplementMagicDictionary::_0676_ImplementMagicDictionary() {}
void LeetCode::_0676_ImplementMagicDictionary::buildDict(std::vector<std::string> dict) {
    for(auto& d : dict) {
        _dict[d.size()].insert(d);
    }
}

bool LeetCode::_0676_ImplementMagicDictionary::search(std::string word) {
    const int ws = word.size();
    auto potentialWordsIter = _dict.find(ws);
    if(potentialWordsIter == _dict.end()) {
        return false;
    }

    for(auto& it : _dict[ws]) {
        int countDif = 0;
        for(int i = 0; i < ws; ++i) {
            if(word[i] != it[i]) {
                ++countDif;
            }
            if(countDif > 1) {
                break;
            }
        }
        if(countDif == 1) {
            return true;
        }
    }
    return false;
}
