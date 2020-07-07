#include "headers.hpp"

int LeetCode::_0746_MinCostClimbingStairs::minCostClimbingStairs(std::vector<int>& cost) {
    std::vector<int> DP(cost.size() + 1, 0);
    DP[0] = 0;
    DP[1] = 0;
    for(int i = 2; i <= cost.size(); ++i) {
        DP[i] = std::min(DP[i-1] + cost[i-1], DP[i-2] + cost[i-2]);
    }
    return DP[cost.size()];
}