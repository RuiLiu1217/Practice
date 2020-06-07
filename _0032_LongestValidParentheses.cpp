#include "headers.hpp"

int LeetCode::_0032_LongestValidParentheses::longestValidParentheses(std::string s) {
    std::vector<int> dp(s.size(), 0);
    int maxLen = 0;
    for(int i = 1; i < s.size(); ++i) {
        if(s[i] == ')') {
            if(s[i-1] == '(') {
                dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
            } else if(i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(') {
                dp[i] = dp[i-1] + ((i - dp[i-1] >= 2) ? dp[i - dp[i-1] - 2] : 0) + 2;
            }
            maxLen = std::max(maxLen, dp[i]);
        }
    }
    return maxLen;
}
