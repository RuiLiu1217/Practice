#include "headers.hpp"
#include <set>

// Need re consider
std::vector<int> LeetCode::_0970_PowerfulIntegers::powerfulIntegers(int x, int y, int bound) {
    if(bound < 2) {
        return std::vector<int>();
    }
    if(x == 1 && y == 1) {
        if(bound < 2) {
            return std::vecotr<int>();
        } else {
            return {2};
        }
    }
    if(x == 1 && y != 1) {
        if(bound < 2) {
            return std::vector<int>();
        } else {
            int idx = 0;
            int v = 1;
            std::vector<int> res;
            while(1 + v <= bound) {
                res.push_back(1+v);
                v = v * y;
            }
            return res;
        }
    }
    if(x != 1 && y == 1) {
        if(bound < 2) {
            return std::vector<int>();
        } else {
            int idx = 0;
            int v = 1;
            std::vector<int> res;
            while(1 + v <= bound) {
                res.push_back(1+v);
                v = v * x;
            }
            return res;
        }
    }

    int idxX = 0;
    int idxY = 0;
    int vx = 1;
    int vy = 1;
    
    std::set<int> ss;
    for(; vx <= bound; vx *= x) {
        for(vy = 1; vy <= bound - vx; vy *= y) {
            ss.insert(vx + vy);
        }
    }
    
    std::vector<int> res;
    res.insert(res.end(), ss.begin(), ss.end());
    return res;
}