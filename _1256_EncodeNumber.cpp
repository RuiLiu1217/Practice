#include "headers.hpp"

std::string LeetCode::_1256_EncodeNumber::encode(int num) {
    int n = 0;
    while(num - std::pow(2,n) >= 0) {
        num -= std::pow(2,n);
        ++n;
    }
    std::string res;
    while(num) {
        res += (num % 2 + '0');
        num /= 2;
    }
    std::reverse(begin(res), end(res));
    res = std::string(n - res.size(), '0') + res;
    return res;
}