#include "headers.hpp"
int LeetCode::_0343_IntegerBreak::intergerBreak(int n) {
    if(n == 1) {
        return 0;
    } 
    if(n == 2) {
        return 1;
    }
    std::vector<int> DP(n+1, 0);
    
    DP[0] = 0;
    DP[1] = 0;
    DP[2] = 1;
    for(int i = 3; i <= n; ++i) {
        int maxV = INT_MIN;
        for(int j = 1; j < i; ++j) {
            int v = std::max(DP[j], j) * std::max(DP[i-j], i-j);
            if(v > maxV) {
                maxV = v;
            }
        }
        DP[i] = maxV;
    }
    return DP[n];
}
