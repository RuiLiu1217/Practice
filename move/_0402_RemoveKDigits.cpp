#include "headers.hpp"

std::string LeetCode::_0402_RemoveKDigits::removeHeadZeros(std::string num) {
    int i = 0;
    while(i < num.size() && num[i] == '0') {
        ++i;
    }
    return i == num.size() ? "0" : num.substr(i);
}

std::string LeetCode::_0402_RemoveKDigits::removeOnedig(std::string num) {
    char pc = '0';
    int I = 0;
    for(int i = 0; i < num.size(); ++i) {
        if(num[i] < pc) {
            break;
        } else {
            I = i;
            pc = num[i];
        }
    }
    return removeHeadZeros(num.erase(I, 1));
}
std::string LeetCode::_0402_RemoveKDigits::removeKdigits(std::string num, int k) {
    while(!num.empty() && num != "0" && k) {
        num = removeOnedig(num);
        --k;
    }
    return num;
}

// Copy from the solution:
std::string removeKdigits(std::string num, int k) {
    std::string res = "";

    for (char c : num) {
        while (res.size() && res.back() > c && k) {  // always use smaller character to replace current tail character
            res.pop_back();
            k--;
        }    
        if (res.size() || c != '0') res += c;
    }
    
    while (res.size() && k--) res.pop_back();
    return res.empty() ? "0" : res;
}