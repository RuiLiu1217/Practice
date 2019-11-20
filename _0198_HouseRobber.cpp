#include "headers.hpp"

/*
It is a typical DP problem. We design a DP vector, DP[i] means the maximum value that we can get from 
nums[0] to nums[i].

DP[0] = nums[0];
DP[1] = max(nums[0], nums[1]);
DP[2] = max(DP[0] + nums[0], nums[1]); 


Therefore, DP[i] = max(DP[i-2] + nums[i], DP[i-1]);
*/

static int rob_DP(std::vector<int>& nums) {
    if(nums.size() == 0) {
        return 0;
    }
    std::vector<int> DP(nums.size()+1, 0);
    DP[0] = nums[0];
    if(nums.size() == 1) {
        return nums[0];
    }
    DP[1] = std::max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); ++i) {
        DP[i] = std::max(DP[i-2] + nums[i], DP[i-1]);
    }
    
    return DP[nums.size()-1];
    
}

int LeetCode::_0198_HouseRobber::rob(std::vector<int>& nums) {
    return  rob_DP(nums);
}
