#include "headers.hpp"

std::vector<int> LeetCode::_0386_LexicographicalNumbers::lexicalOrder(int n) {
    for(int i = 1; i <= 9; ++i) {
        dfs(i, n);
    }
    return res;
}

void LeetCode::_0386_LexicographicalNumbers::dfs(int cur, int n) {
    if(cur > n) {
        return;
    }
    res.push_back(cur);
    for(int i = 0; i <= 9; ++i) {
        if(cur * 10 + i <= n) {
            dfs(cur * 10 + i, n);
        }
    }
}