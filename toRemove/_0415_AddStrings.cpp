#include "headers.hpp"
#include <algorithm>

// Facebook
std::string LeetCode::_0415_AddStrings::addStrings(std::string num1, std::string num2) {
    std::reverse(begin(num1), end(num1));
    std::reverse(begin(num2), end(num2));
    const int minL = std::min(num1.size(), num2.size());
    int carry = 0;
    std::string res;
    int i = 0;
    for(i = 0; i < minL; ++i) {
        int t = (num1[i] - '0' + num2[i] - '0' + carry);
        if(t >= 10) {
            carry = 1;
            t -= 10;
        } else {
            carry = 0;
        }
        res += ('0' + t);
    }
    while(i < num1.size()) {
        int t = (num1[i] - '0' + carry);
        if(t >= 10) {
            carry = 1;
            t -= 10;
        } else {
            carry = 0;
        }
        res += ('0' + t);
        ++i;
    }
    while(i < num2.size()) {
        int t = (num2[i] - '0' + carry);
        if(t >= 10) {
            carry = 1;
            t -= 10;
        } else {
            carry = 0;
        }
        res += ('0' + t);
        ++i;
    }
    if(carry) {
        res += '1';
    }
    std::reverse(begin(res), end(res));
    return res;
}