#include "headers.hpp"

// Facebook 

std::vector<std::string> LeetCode::_0282_ExpressionAddOperators::addOperators(std::string num, int target) {
    std::string exp;
    std::vector<std::string> ans;
    DFS(num, target, 0, exp, 0, 0, ans);
    return ans;
}

void LeetCode::_0282_ExpressionAddOperators::DFS(const std::string& num, const int target, int pos, 
std::string exp, long prev, long curr, std::vector<std::string>& ans) {
    if(pos == num.length()) {
        if(curr == target) {
            ans.push_back(exp);
        }
        return;
    }

    for(int l = 1; l <= num.size() - pos; ++l) {
        std::string t = num.substr(pos, l);
        if(t[0] == '0' && t.length() > 1) {
            continue;
        }
        long n = std::stol(t);
        if(n > INT_MAX) {
            break;
        }
        if(pos == 0) {
            DFS(num, target, l, t, n, n, ans);
            continue;
        }
        DFS(num, target, pos + l, exp + '+' + t, n, curr + n, ans);
        DFS(num, target, pos + l, exp + '-' + t, -n, curr - n, ans);
        DFS(num, target, pos + l, exp + '*' + t, prev * n, curr - prev + prev * n, ans);
    }
}