#include "headers.hpp"
#include <cmath>

int LeetCode::_0921_MinimumAddToMakeParenthesesValid::minAddToMakeValid(std::string S) {
    int sLeft = 0;
    int sRight = 0;
    for(auto s : S) {
        if(s == '(') {
            ++sLeft;
        } else {
            if(sLeft <= 0) {
                ++sRight;
            } else {
                --sLeft;
            }
        }
    }
    return std::abs(sLeft) + std::abs(sRight);
}