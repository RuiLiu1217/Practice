#include "headers.hpp"

bool LeetCode::_0717_OneBitAndTwoBitsCharacters::isOneBitCharacter(std::vector<int>& bits) {
    return isOneBitCharacter(bits, 0, bits.size() - 1);
}

bool LeetCode::_0717_OneBitAndTwoBitsCharacters::isOneBitCharacter(std::vector<int>& bits, int start, int end) {
    if(start > end) {
        return false;
    }
    
    if(start == end) {
        if(bits[start] == 0) {
            return true;
        } else {
            return false;
        }
    }
    if(bits[start] == 0) {
        return isOneBitCharacter(bits, start + 1, end);
    } else {
        return isOneBitCharacter(bits, start + 2, end);
    }
}