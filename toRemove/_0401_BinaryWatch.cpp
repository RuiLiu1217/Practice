#include "headers.hpp"
#include <bitset>
#include <functional>
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


// easier understand solution
static std::vector<std::string> readBinaryWatch_Solution2(int num) {
    
    std::vector<std::string> res;
    std::function<int(int)> numOf1 = [](int n){
        int res = 0;
        while(n) {
            res += (n & 1);
            n >>= 1;
        }
        return res;
    };

    for(int h = 0; h < 23; ++h) {
        int hn = numOf1(h);
        if(hn > num) {
            continue;
        }
        for(int m = 0; m < 60; ++m) {
            int mn = numOf1(m);
            if(mn + hn == num) {
                if(m < 10) {
                    res.push_back(std::to_string(h) + ":0" + std::to_string(m));
                } else {
                    res.push_back(std::to_string(h) + ":" + std::to_string(m));
                }
            }
        }
    }
}