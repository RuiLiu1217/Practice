#include "headers.hpp"
void LeetCode::_0344_ReverseString::reverseString(vector<char>& s) {
    int i = 0;
    int j = s.size() - 1;
    while(i < j) {
        std::swap(s[i++], s[j--]);
    }
}