#include "headers.hpp"

int LeetCode::_0276_PaintFence::numWays(int n, int k) {
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return k;
    }
    if(n == 2) {
        return k * k;
    }
    std::vector<int> DP(n+1, 0);
    DP[0] = 0;
    DP[1] = k;
    DP[2] = k * k;
    for(int i = 3; i <= n; ++i) {
        DP[i] = DP[i-1] * (k-1) + DP[i-2] * (k-1);
    }
    return DP[n];
}