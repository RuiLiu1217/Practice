#include "headers.hpp"

std::string LeetCode::_0405_ConvertANumberToHexadecimal::toHex(int num) {
    std::string res;
    int count = 0;
    do {
        char n = (num & 0x0000000f);
        if(n < 10) {
            res = (char)(n + '0') + res;
        } else {
            res = (char)(n - 10 + 'a') + res;
        }
        num >>= 4;
        ++count;
    } while (count < 8 && num);
    return res;
}