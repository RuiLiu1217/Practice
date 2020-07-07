#include "headers.hpp"

std::string LeetCode::_0423_ReconstructOriginalDigitFromEnglish::originalDigits(std::string s) {
    std::unordered_map<char, int> Map;
    std::vector<int> resCount(10, 0);
    for(auto& c : s) {
        ++Map[c];
    }
    if(Map.find('z') != Map.end() && Map['z'] > 0) {
        int count = Map['z'];
        resCount[0] += count;
        Map['z'] = 0;
        Map['e'] -= count;
        Map['r'] -= count;
        Map['o'] -= count;            
    }
    if(Map.find('w') != Map.end() && Map['w'] > 0) {
        int count = Map['w'];
        resCount[2] += count;
        Map['w'] = 0;
        Map['t'] -= count;
        Map['o'] -= count;
    }
    if(Map.find('u') != Map.end() && Map['u'] > 0) {
        int count = Map['u'];
        resCount[4] += count;
        Map['u'] = 0;
        Map['f'] -= count;
        Map['o'] -= count;
        Map['r'] -= count;
    }
    if(Map.find('x') != Map.end() && Map['x'] > 0) {
        int count = Map['x'];
        resCount[6] += count;
        Map['x'] = 0;
        Map['s'] -= count;
        Map['i'] -= count;
    }
    if(Map.find('g') != Map.end() && Map['g'] > 0) {
        int count = Map['g'];
        resCount[8] += count;
        Map['g'] = 0;
        Map['e'] -= count;
        Map['i'] -= count;
        Map['h'] -= count;
        Map['t'] -= count;
    }
    if(Map.find('r') != Map.end() && Map['r'] > 0) {
        int count = Map['r'];
        resCount[3] += count;
        Map['r']  = 0;
        Map['t'] -= count;
        Map['h'] -= count;
        Map['e'] -= count;
        Map['e'] -= count;
    }
    if(Map.find('s') != Map.end() && Map['s'] > 0) {
        int count = Map['s'];
        resCount[7] += count;
        Map['s'] = 0;
        Map['e'] -= count;
        Map['v'] -= count;
        Map['e'] -= count;
        Map['n'] -= count;
    }
    if(Map.find('v') != Map.end() && Map['v'] > 0) {
        int count = Map['v'];
        resCount[5] += count;
        Map['v'] = 0;
        Map['f'] -= count;
        Map['i'] -= count;
        Map['e'] -= count;
    }
    if(Map.find('o') != Map.end() && Map['o'] > 0) {
        int count = Map['o'];
        resCount[1] += count;
        Map['o'] = 0;
        Map['n'] -= count;
        Map['e'] -= count;
    }
    if(Map.find('i') != Map.end() && Map['i'] > 0) {
        int count = Map['i'];
        resCount[9] += count;
        Map['i'] = 0;
        Map['n'] -= count;
        Map['n'] -= count;
        Map['e'] -= count;
    }
    std::string res;
    for(int i = 0; i < 10; ++i) {
        if(resCount[i] > 0) {
            for(int r = 0; r < resCount[i]; ++r) {
                res += std::to_string(i);
            }
        }
    }
    return res;
}
