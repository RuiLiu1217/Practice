#include "headers.hpp"

std::string LeetCode::_1021_RemoveOutermostParentheses::removeOuterParentheses(std::string S) {
    int opened = 0; // Use This counter the out most ()
    std::string res;
    for(auto a : S) {
        if(a == '(' && opened++ > 0) {
            res += a;
            
        } else if(a == ')' && opened-- > 1) {
            res += a;
            
        }
    }
    return res;
}