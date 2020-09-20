#include "headers.hpp"

int LeetCode::_1189_MaximumNumberOfBalloons::maxNumberOfBalloons(std::string text) {
    std::vector<int> map(256, 0);
    for(auto& c : text) {
        ++map[c];
    }
    int count = 0;
    while(updateBallon(map)) {
        ++count;
    }
    return count;
}

bool LeetCode::_1189_MaximumNumberOfBalloons::updateBallon(std::vector<int>& map) {
    if(map['b'] <= 0) {
        return false;
    } else {
        --map['b'];
    }
    if(map['a'] <= 0) {
        return false;
    } else {
        --map['a'];
    }
    if(map['l'] <= 1) {
        return false;
    } else {
        map['l'] -= 2;
    }
    if(map['o'] <= 1) {
        return false;
    } else {
        map['o'] -= 2;
    }
    if(map['n'] <= 0) {
        return false;
    } else {
        --map['n'];
    }
    return true;
}