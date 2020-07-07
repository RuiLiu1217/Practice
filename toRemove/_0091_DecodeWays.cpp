#include "headers.hpp"
int LeetCode::_0091_DecodeWays::numDecodings(std::string s) {
    if(s.size() == 0 || s[0] == '0') {
        return 0;
    }
    std::vector<int> DP(s.size(), 0);
    DP[0] = 1;
    for(int i = 1; i < s.size(); ++i) {
        int n = s[i] - '0';
        int pre = s[i-1] - '0';

        // Current digit is from 1~9, then the current number of ways
        // of decoding the message is at least the number of ways
        // calculated until the previous one
        if(n >= 1 && n <= 9) {
            DP[i] += DP[i-1];
        }

        // Check whether the adjacent two digits are from 10~26, including
        // 10 and 20
        if(pre != 0) {
            int twoDigits = std::stoi(s.substr(i-1, 2));
            if(twoDigits >= 1 && twoDigits <= 26) {
                DP[i] = (i==1) ? (DP[i]+1) : (DP[i] + DP[i-2]);
            }
        }
    }
    return DP.back();
}

