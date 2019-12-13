#include "headers.hpp"
#include <algorithm>
#include <numeric>
// Note:
// The length of nums is at most 20000.
// Each element nums[i] is an integer in the range [1, 10000].
// This problem is almost the same as the house robber one.
int LeetCode::_0740_DeleteAndEarn::deleteAndEarn(std::vector<int>& nums) {
    if(nums.size() == 1) {
        return nums[0];
    }
    std::vector<int> series(10000, 0);

    for(int i = 0; i < nums.size(); ++i) {
        series[nums[i]] += nums[i];
    }

    std::vector<int> DP(series.size() + 1, 0);
    DP[0] = series[0];
    DP[1] = std::max(series[0], series[1]);
    for(int i = 2; i < series.size(); ++i) {
        DP[i] = std::max(DP[i-2] + series[i], DP[i-1]);
    }

    auto it = std::max_element(DP.begin(), DP.end());
    return *it;
}