#include "headers.hpp"
#include <algorithm>
std::string LeetCode::_0415_AddStrings::addStrings(std::string num1, std::string num2) {
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    
    int length = std::min(num1.size(), num2.size());
    std::string res;
    bool carry = false;
    for(int i = 0; i < length; ++i) {
        int curRes = num1[i] - '0' + num2[i] - '0' + carry;
        if(curRes >= 10) {
            curRes = curRes - 10;
            carry = true;
        } else {
            carry = false;
        }
        res = char(curRes + '0') + res;
    }
    if(num1.size() < num2.size()) {
        for(int i = length; i < num2.size(); ++i) {
            int curRes = num2[i] - '0' + carry;
            if(curRes >= 10) {
                curRes = curRes - 10;
                carry = true;
            } else {
                carry = false;
            }
            res = char(curRes + '0') + res;
        }
    } else if(num2.size() < num1.size() ) {
        for(int i = length; i < num1.size(); ++i) {
            int curRes = num1[i] - '0' + carry;
            if(curRes >= 10) {
                curRes = curRes - 10;
                carry = true;
            } else {
                carry = false;
            }
            res = char(curRes+'0') + res;
        }
    }
    
    if(carry) {
        res = char('1') + res;
    }
    return res;
}