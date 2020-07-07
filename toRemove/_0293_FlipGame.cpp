#include "headers.hpp"

std::vector<std::string> LeetCode::_0293_FlipGame::generatePossibleNextMoves(std::string s) {
    std::vector<std::string> res;
    if(s.empty()) {
        return {};
    }

    for(int i = 0; i < s.size() - 1; ++i) {
        if(s[i] == '+' && s[i+1] == '+') {
            s[i] = '-';
            s[i+1] = '-';
            res.push_back(s);
            s[i] = '+';
            s[i+1] == '+';
        }
    }
    return res;
}