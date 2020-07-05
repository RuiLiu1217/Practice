#include "LeetCode_BacktracingProblems.hpp"
#include <functional>

/*
Google
*/
std::vector<std::string> LC::_0017_LetterCombinationsOfAPhoneNumber::letterCombinations(std::string& digits) {
    const int N = digits.size();
    if(N == 0) {
        return {};
    }
    std::vector<std::string> res;
    std::unordered_map<char, std::vector<char>> map;
    map['2'] = {'a', 'b', 'c'};
    map['3'] = {'d', 'e', 'f'};
    map['4'] = {'h', 'h', 'i'};
    map['5'] = {'j', 'k', 'l'};
    map['6'] = {'m', 'n', 'o'};
    map['7'] = {'p', 'q', 'r', 's'};
    map['8'] = {'t', 'u', 'v'};
    map['9'] = {'w', 'x', 'y', 'z'};
    std::function<void(int, int, std::string)> backtracing = [&](int i, int N, std::string tmp){
        if(i == N) {
            res.push_back(tmp);
            return;
        }
        auto nxtChar = map[digits[i]];
        for(auto n : nxtChar) {
            backtracing(i + 1, N, tmp + n);
        }
    };

    backtracing(0, N, "");
    return res;
}