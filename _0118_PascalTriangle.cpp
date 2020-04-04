#include "headers.hpp"

/*
Type: Array
*/
std::vector<std::vector<int>> LeetCode::_0118_PascalTriangle::generate(int numRows) {
    if(numRows == 0) {
        return std::vector<std::vector<int>>();
    }
    std::vector<std::vector<int>> res;
    std::vector<int> a{1};
    res.push_back(a);
    if(numRows == 1) {
        return res;
    }
    std::vector<int> b{1,1};
    res.push_back(b);
    if(numRows == 2) {
        return res;
    }
    for(int i = 2; i < numRows; ++i) {
        std::vector<int> t(i+1, 0);
        t[0] = 1;
        for(int j = 1; j < t.size() - 1; ++j) {
            t[j] = res[i-1][j-1] + res[i-1][j];
        }
        t[t.size()-1] = 1;
        res.push_back(t);
    }
    return res;
}
