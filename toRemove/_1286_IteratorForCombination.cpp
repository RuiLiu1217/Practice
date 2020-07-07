#include "headers.hpp"

LeetCode::_1286_IteratorForCombination::_1286_IteratorForCombination(std::string cs, int cl) : characters(cs),
combinationLength(cl) {
    combinIndex.resize(combinationLength);
    for(int i = 0; i < combinationLength; ++i) {
        combinIndex[i] = i;
    }

    isFirstCombination = true;
    charactersLength = characters.length();
}

std::string LeetCode::_1286_IteratorForCombination::next() {
    if(hasNext()) {
        std::string result;
        if(isFirstCombination) {
            for(int i = 0; i < combinationLength; ++i) {
                result += characters[combinIndex[i]];
                isFirstCombination = false;
            }
            return result;
        }

        for(int i = combinationLength - 1; i >= 0; --i) {
            if(combinIndex[i] != charactersLength - combinationLength + i) {
                ++combinIndex[i];
                for(int j = i + 1; j < combinationLength; ++j) {
                    combinIndex[j] = combinIndex[i] + j - i;
                }
                break;
            }
        }

        for(int i = 0; i < combinationLength; ++i) {
            result += characters[combinIndex[i]];
        }
        return result;
    }
}

bool LeetCode::_1286_IteratorForCombination::hasNext() {
    return combinIndex[0] != charactersLength - combinationLength;
}