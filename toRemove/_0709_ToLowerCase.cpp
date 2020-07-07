#include "headers.hpp"
#include <string>
#include <map>

std::string LeetCode::_0709_ToLowerCase::toLowerCase(std::string str) {
    std::string res = str;
    std::map<char, char> mp;
    mp['A'] = 'a'; mp['B'] = 'b'; mp['C'] = 'c'; mp['D'] = 'd';
    mp['E'] = 'e'; mp['F'] = 'f'; mp['G'] = 'g'; mp['H'] = 'h';
    mp['I'] = 'i'; mp['J'] = 'j'; mp['K'] = 'k'; mp['L'] = 'l';
    mp['M'] = 'm'; mp['N'] = 'n'; mp['O'] = 'o'; mp['P'] = 'p';
    mp['Q'] = 'q'; mp['R'] = 'r'; mp['S'] = 's'; mp['T'] = 't';
    mp['U'] = 'u'; mp['V'] = 'v'; mp['W'] = 'w'; mp['X'] = 'x';
    mp['Y'] = 'y'; mp['Z'] = 'z';
    for(int i = 0 ; i != str.size(); ++i)
    {
        if(res[i] >= 'A' && res[i] <= 'Z') {
            res[i] = mp[res[i]];
        }
    }
    return res;
}