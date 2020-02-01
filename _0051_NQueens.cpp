#include "headers.hpp"

std::vector<std::vector<std::string>> LeetCode::_0051_NQueens::solveNQueens(int n) {
    std::string ol;
    for(int i = 0 ;i < n; ++i) {
        ol += ".";
    }
    std::vector<std::string> tmp(n, ol);
    std::vector<std::vector<std::string>> res;
    solve(tmp, 0, n, res);
    return res;
}
    
void LeetCode::_0051_NQueens::solve(std::vector<std::string>& tmp, int curN, int n, std::vector<std::vector<std::string>>& res) {
    if(curN == n) {
        res.push_back(tmp);
        return;
    }
    std::vector<int> available = availableQ(tmp, curN, n);
    for(int i = 0; i < available.size(); ++i) {
        if(available[i]) {
            tmp[curN][i] = 'Q';
            solve(tmp, curN + 1, n, res);
            tmp[curN][i] = '.';
        }
    }
}
    
std::vector<int> LeetCode::_0051_NQueens::availableQ(std::vector<std::string> tmp, int curN, int n) {
    std::vector<int> available(n, 1);
    for(int i = 0; i < curN; ++i) {
        int dis = std::abs(curN - i);
        for(int j = 0; j < n; ++j) {
            if(tmp[i][j] == 'Q') {
                available[j] = 0;
                if(j + dis < n && j + dis >= 0) {
                    available[j + dis] = 0;
                }
                if(j - dis >= 0 && j - dis < n) {
                    available[j - dis] = 0;
                }
            }
        }
    }
    return available;
}
