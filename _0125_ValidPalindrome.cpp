#include "headers.hpp"
#include <algorithm>
#include <cctype>
bool LeetCode::_0125_ValidPalindrome::isPalindrome(std::string s) {
    if (s.empty())
        return true;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    int i = 0;
    int j = s.size() - 1;
    while(i < j) {
        if(!std::isalnum(s[i])) {
            i++;
            continue;
        }
        if(!std::isalnum(s[j])) {
            j--;
            continue;
        }
        if(s[i] == s[j]) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}