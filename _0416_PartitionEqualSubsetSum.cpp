#include "headers.hpp"
#include <algorithm>
#include <numeric>
bool LeetCode::_0416_PartitionEqualSubsetSum::canPartition(std::vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if(sum % 2) {
        return false;
    }
    sum /= 2;
    const int n = nums.size();
    std::vector<std::vector<bool>> DP(n+1, std::vector<bool>(sum+1, false));
    DP[0][0] = true;
    for(int i = 1; i < n + 1; ++i) {
        DP[i][0] = true;
    }
    for(int j = 1; j < sum + 1; ++j) {
        DP[0][j] = false;
    }
    
    for(int i = 1; i < n + 1; ++i) {
        for(int j = 1; j < sum + 1; ++j) {
            DP[i][j] = DP[i-1][j];
            if(j >= nums[i-1]) {
                DP[i][j] = (DP[i][j] || DP[i-1][j-nums[i-1]]);
            }
        }
    }
    return DP[n][sum];
}