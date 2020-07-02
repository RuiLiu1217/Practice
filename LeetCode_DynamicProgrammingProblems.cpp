#include "LeetCode_DynamicProgrammingProblems.hpp"

#include <vector>
// Tag: dynamic programming, string matching.
bool LC::_0010_RegularExpressionMatching::isMatch(std::string s, std::string p){
    const int M = s.length();
    const int N = p.length();

    // DP[i][j] means whether the first [0,i) substr of s 
    // matches with the first [0,j) substr of p.
    std::vector<std::vector<bool>> DP(M + 1, std::vector<bool>(N + 1, false));
    DP[0][0] = true;

    for(int i = 0; i <= M; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(p[j-1] == '*') {
                DP[i][j] = DP[i][j-2] || (i && DP[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
            } else {
                DP[i][j] = i && DP[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            }
        }
    }
    return DP[M][N];
}