#include "headers.hpp"

// 非常经典的动态规划题目。需要认真看，为什么这么写，其中的推导是如何的。
int LeetCode::_0664_StrangePrinter::strangePrinter(const std::string& s) {
    int l = s.length();
    DP = std::vector<std::vector<int>>(l, std::vector<int>(l, 0));
    return turn(s, 0, l - 1);
}

int LeetCode::_0664_StrangePrinter::turn(const std::string& s, int i, int j) {
    if(i > j) {
        return 0;
    }
    if(DP[i][j] > 0) {
        return DP[i][j];
    }

    int ans = turn(s, i, j - 1) + 1;

    for(int k = i; k < j; ++k) {
        if(s[k] == s[j]) {
            ans = std::min(ans, turn(s, i, k) + turn(s, k + 1, j - 1));
        }
    }
    return DP[i][j] = ans;
}