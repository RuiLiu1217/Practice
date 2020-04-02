#include "headers.hpp"

static bool isValid(const std::string& s, int i, int j, int d) { // d : is the number of characters that allowed to be deleted at most
    if(i >= j) {
        return true;
    }
    if(s[i] == s[j]) {
        return isValid(s, i + 1, j - 1, d);
    } else {
        if(d == 0) {
            return false;
        } else {
            return isValid(s, i + 1, j, d-1) || isValid(s, i, j-1, d-1);
        }
    }
}


bool LeetCode::_0680_ValidPalindromeII::validPalindrome(std::string s) {
    return isValid(s, 0, s.size() - 1, 1);
}