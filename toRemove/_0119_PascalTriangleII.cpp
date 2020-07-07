#include "headers.hpp"
/*
Type: Array
*/
std::vector<int> LeetCode::_0119_PascalTriangleII::getRow(int rowIndex) {
    if(rowIndex == 0) {
        return {1};
    }
    std::vector<int> p{1,1};
    if(rowIndex == 1) {
        return p;
    }

    int rdx = 2;
    while(rdx <= rowIndex) {
        std::vector<int> c(p.size() + 1);
        c[0] = 1;
        for(int i = 1; i < p.size(); ++i) {
            c[i] = p[i-1] + p[i];
        }
        c[c.size() - 1] = 1;
        p = c;
        ++rdx;
    }
    return p;
}