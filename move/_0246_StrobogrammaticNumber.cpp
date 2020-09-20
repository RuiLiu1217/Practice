#include "headers.hpp"

bool LeetCode::_0246_StrobogrammaticNumber::isStrobogrammatic(std::string num) {
    std::unordered_map<char, char> map;
    map['0'] = '0';
    map['1'] = '1';
    map['2'] = '#';
    map['3'] = '#';
    map['4'] = '#';
    map['5'] = '#';
    map['6'] = '9';
    map['7'] = '#';
    map['8'] = '8';
    map['9'] = '6';
    std::string res;
    for(auto c : num) {
        if(map[c] == '#') {
            return false;
        }
        res += map[c];            
    }
    std::reverse(begin(res), end(res));
    return res == num;
}