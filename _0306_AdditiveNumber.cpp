#include "headers.hpp"
#include <algorithm>

bool LeetCode::_0306_AdditiveNumber::isAdditiveNumber(std::string num) {
    const int N = num.size();
    for(int start3 = 2; start3 < N; ++start3) {
        for(int start2 = start3 - 1; start2 > 0; --start2) {
            if(isAdditiveNumber(num, 0, start2, start3) == true) {
                return true;
            }
        }
    }
    return false;
}

    
bool LeetCode::_0306_AdditiveNumber::isAdditiveNumber(std::string& num, int start1, int start2, int start3) {
    std::string a = num.substr(start1, start2-start1);
    std::string b = num.substr(start2, start3-start2);
    if((a.size() > 1 && a[0] == '0') || (b.size() > 1 && b[0] == '0')) {
        return false;
    }
    std::string p = add(a,b);
    int i = 0;
    for(; i < p.size() && i + start3 < num.size(); ++i) {
        if(num[start3+i] != p[i]) {
            return false;
        }
    }
    if(i == p.size()) {
        if(start3 + i == num.size()) {
            return true;
        } else {
            return isAdditiveNumber(num, start2, start3, start3 + i);
        }            
    } else {
        return false;
    }
}

    
    
std::string LeetCode::_0306_AdditiveNumber::add(std::string a, std::string b) {
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    
    int carry = 0;
    std::string res;
    int i = 0;
    for(i = 0; i < std::min(a.size(), b.size()); ++i) {
        int v = a[i] - '0' + b[i] - '0' + carry;
        if(v >= 10) {
            v -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res += std::to_string(v);
    }
    if(a.size() > i) {
        for(; i < a.size(); ++i) {
            int v = a[i] - '0' + carry;
            if(v >= 10) {
                v -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res += std::to_string(v);
        }
    } else if(b.size() > i) {
        for(; i < b.size(); ++i) {
            int v = b[i] - '0' + carry;
            if(v >= 10) {
                v -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            res += std::to_string(v);
        }
    }
    if(carry) {
        res += std::to_string(carry);
    }
    
    std::reverse(res.begin(), res.end());
    return res;
    
}