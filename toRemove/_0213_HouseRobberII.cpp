#include "headers.hpp"
// Tag: dynamic programming, two times calculation, {0~N-1, 1~N}
// 
int LeetCode::_0213_HouseRobberII::rob(std::vector<int>& nums) {
    if(nums.size() == 0) {
        return 0;
    }
    if(nums.size() == 1) {
        return nums[0];
    }
    if(nums.size() == 2) {
        return std::max(nums[0], nums[1]);
    }
    
    std::vector<int> A(nums.begin(), nums.end() - 1);
    std::vector<int> B(nums.begin() + 1, nums.end());
    int rA = robHelp(A);
    int rB = robHelp(B);
    return std::max(rA, rB);        
}

int LeetCode::_0213_HouseRobberII::robHelp(std::vector<int>& nums) {
    if(nums.size() == 1) {
        return nums[0];
    }
    if(nums.size() == 2) {
        return std::max(nums[0], nums[1]);
    }
    
    std::vector<std::vector<int>> DP(2, std::vector<int>(nums.size(), 0));
    DP[0][0] = 0;
    DP[1][0] = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        DP[0][i] = std::max(DP[0][i-1], DP[1][i-1]);
        DP[1][i] = DP[0][i-1] + nums[i];
    }
    return std::max(DP[0].back(), DP[1].back());
}