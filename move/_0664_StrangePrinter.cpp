#include "headers.hpp"

// 非常经典的动态规划题目。需要认真看，为什么这么写，其中的推导是如何的。
int LeetCode::_0664_StrangePrinter::strangePrinter(const std::string& s) {
    int l = s.length();
    DP = std::vector<std::vector<int>>(l, std::vector<int>(l, 0));
    return turn(s, 0, l - 1);
}

// 这个函数表示从第i个字母 打印到 第字母 j 个字母所需要的次数
int LeetCode::_0664_StrangePrinter::turn(const std::string& s, int i, int j) {
    if(i > j) {
        return 0;
    }
    if(DP[i][j] > 0) {
        return DP[i][j];
    }

    int ans = turn(s, i, j - 1) + 1; // 首先将结果设定为从第i个字母打印到第 j-1个字母所需要的次数
                                     // 加上最后打印第j个字母所需要的1次
    for(int k = i; k < j; ++k) { //循环从第i个字母开始看一直看到第j个字母之前一个字母，
        if(s[k] == s[j]) { // 如果第k个字母和第j个字母一样，我们可以这样打印 
                           // 先把第i个字母到第k个字母打印出来，然而在打印到第k个字母的时候并不停下来，
                           // 一直打印到第j个字母的位置，因为 S[k] == S[j]，因此次数不变。然后从第k+1个字母开始打印
                           // 一直打印到第 j-1 个字母。
            ans = std::min(ans, turn(s, i, k) + turn(s, k + 1, j - 1));
        }
    }
    return DP[i][j] = ans;
}