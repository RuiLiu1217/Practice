#include "headers.hpp"

std::vector<int> LeetCode::_0238_ProductOfArrayExceptSelf::productExceptSelf(std::vector<int>& nums) {
    std::vector<int> res(nums.size(), 1);
    for(int i = 1; i < res.size(); ++i) {
        res[i] = nums[i-1] * res[i-1];
    }
    
    int t = 1;
    for(int i = nums.size() - 2; i >= 0; --i) {
        t *= nums[i+1];
        res[i] *= t;
    }
    return res;    
}