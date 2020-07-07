#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0216_CombinationSumIII::combinationSum3(int k, int n) {
    std::vector<int> tmp;
    std::vector<std::vector<int>> res;
    DFS(k, n, 1, tmp, res);
    return res;
}

 void LeetCode::_0216_CombinationSumIII::DFS(int k, int n, int curV, std::vector<int>& tmp, std::vector<std::vector<int>>& res) {
    if(k == 0 && n == 0) {
        res.push_back(tmp);
        return;
    }
    if((k == 0 && n != 0) || (k != 0 && n == 0) || (k == 1 && n > 9)) {
        return;
    }
    
    for(int t = curV; t <= 9; ++t) {
        tmp.push_back(t);
        DFS(k-1, n-t, t + 1, tmp, res);
        tmp.pop_back();
    }   
}