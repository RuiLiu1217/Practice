#include "headers.hpp"

std::string LeetCode::_1271_Hexspeak::toHexspeak(std::string num) {
    long n = std::stol(num);
    std::string res;
    while(n) {
        int r = n % 16;
        if(r == 2 || r == 3 || r == 4 || r == 5 || 
            r == 6 || r == 7 || r == 8 || r == 9) {
            return "ERROR";
        } else {
            if(r == 0) {
                res += "O";
            } else if(r == 1) {
                res += "I";
            } else {
                res += (r - 10 + 'A');
            }
        }
        n /= 16;
    }
    std::reverse(begin(res), end(res));
    int i = 0;
    while(i < res.size() && res[i] == 'O') {
        ++i;
    }
    
    return res.substr(i);
}