#include "headers.hpp"

std::vector<std::string> LeetCode::_0401_BinaryWatch::readBinaryWatch(int num) {
    std::vector<std::string> res;
    for(int h = 0; h < 12; ++h) {
        for(int m = 0; m < 60; ++m) {
            if(std::bitset<10>(h << 6 | m).count() == num) { // Why not 11, <<7?
                res.emplace_back(std::to_string(h) + 
                (m < 10? "0" : "") + std::to_string(m));
            }
        }
    }
    return res;
}