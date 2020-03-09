#include "headers.hpp"
/*
Google
*/
// Greedy algorithm: 
std::string LeetCode::_0012_IntegerToRoman::intToRoman(int num) {
    int value[13] =       {1000,   900,   500,    400,   100,    90,    50,    40,   10,     9,    5,     4,   1};
    std::string str[13] = {"M",   "CM",   "D",   "CD",   "C",  "XC",   "L",  "XL",  "X",  "IX",  "V",  "IV",  "I"};
    std::string res;
    for(int i = 0; i < 13; ++i) {
        if(num >= value[i]) {
            int count = num / value[i];
            num %= value[i];
            for(int j = 0; j < count; ++j) {
                res += str[i];
            }
        }
    }
    return res;
}