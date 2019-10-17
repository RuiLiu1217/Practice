#include "headers.hpp"

std::vector<std::vector<int>> LintCode::_1355_PascalsTriangle::generate(int numRows) {
    if(numRows == 1) {
        std::vector<int> a{1};
        std::vector<std::vector<int>> res;
        res.push_back(a);
        return res;
    } else if(numRows == 2) {
        std::vector<std::vector<int>> res;
        std::vector<int> a{1};
        std::vector<int> b{1,1};
        
        res.push_back(a);
        res.push_back(b);
        return res;
    } else {
        std::vector<std::vector<int>> res;
        std::vector<int> a{1};
        std::vector<int> b{1,1};
        
        res.push_back(a);
        res.push_back(b);
        for(int i = 2; i < numRows; ++i) {
            std::vector<int> c;
            c.push_back(1);
            for(int j = 0; j < res[i-1].size() - 1; ++j) {
                c.push_back(res[i-1][j] + res[i-1][j+1]);
            }
            c.push_back(1);
            res.push_back(c);
        }
        return res;
    }
}