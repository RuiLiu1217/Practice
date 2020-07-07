#include "headers.hpp"

/*
Now, dp[i][j]dp[i][j] refers to the number of deletions required to 
equalize the two strings if we consider the strings' length upto (i-1)^{th}
index and (j-1)^{th} index for s1 and s2 respectively. Again, we fill 
in the dp array in a row-by-row order. Now, in order to fill the entry 
for dp[i][j], we need to consider two cases only:

(1) The characters s1[i-1] and s2[j-1] match with each other. In 
this case, we need to replicate the entry corresponding to dp[i-1][j-1] itself. 
This is because, the matched character doesn't need to be deleted from any of the strings.
(2) The characters s1[i-1] and s2[j-1] don't match with each other. In this 
case, we need to delete either the current character of s1 or s2. Thus, an 
increment of 1 needs to be done relative to the entries corresponding to the 
previous indices. The two options available at this moment are dp[i-1][j] and dp[i][j−1]. 
Since, we are keeping track of the minimum number of deletions required, we 
pick up the minimum out of these two values.
*/
int LeetCode::_0583_DeleteOperationForTwoStrings::minDistance_DP_nonLCS_based(std::string word1, std::string word2) {
    const int m = word1.size();
    const int n = word2.size();
    DP = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));
    for(int i = 0; i <= m; ++i) {
        for(int j = 0; j <= n; ++j) {
            if(i == 0 || j == 0) {
                DP[i][j] = i + j;
            } else if(word1[i-1] == word2[j-1]) {
                DP[i][j] = DP[i-1][j-1];
            } else {
                DP[i][j] = 1 + std::min(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
    return DP[m][n];
}


int LeetCode::_0583_DeleteOperationForTwoStrings::minDistance_LCS_DP_based(std::string word1, std::string word2) {
    const int m = word1.size();
    const int n = word2.size();
    DP = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));
    for(int i = 0; i <= m; ++i) {
        for(int j = 0; j <= n; ++j) {
            if(i == 0 || j == 0) {
                continue;
            }
            if(word1[i - 1] == word2[j - 1]) {
                DP[i][j] = DP[i-1][j-1] + 1;
            } else {
                DP[i][j] = std::max(DP[i][j-1], DP[i-1][j]);
            }
        }
    }
    return m + n - 2 * DP[m][n];
}

int LeetCode::_0583_DeleteOperationForTwoStrings::minDistance_LCS_based(std::string word1, std::string word2) {
    const int m = word1.size();
    const int n = word2.size();
    DP = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));
    return m + n - 2 * lcs(word1, word2, m, n);
}

// 如何计算最长公共子序列
int LeetCode::_0583_DeleteOperationForTwoStrings::lcs(std::string& s1, std::string& s2, int m, int n) {
    if(m == 0 || n == 0) {
        return 0;
    }
    if(DP[m][n] > 0) {
        return DP[m][n];
    }
    if(s1[m-1] == s2[n-1]) {
        return DP[m][n] = 1 + lcs(s1, s2, m-1, n-1);
    } else {
        return DP[m][n] = std::max(lcs(s1, s2, m-1, n), lcs(s1,s2,m, n-1));
    }
}

int LeetCode::_0583_DeleteOperationForTwoStrings::minDistance(std::string word1, std::string word2) {
    return minDistance_DP_nonLCS_based(word1, word2);
}