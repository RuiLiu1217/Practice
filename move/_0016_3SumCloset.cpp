#include "headers.hpp"
#include <algorithm>
#include <cassert>
/*
Google

Type : Array

https://leetcode.com/problems/3sum-closest/
*/
int LeetCode::_0016_3SumCloset::threeSumCloset(std::vector<int>& nums, int target) {
    assert(nums.size() >= 3);
    int closet = nums[0] + nums[1] + nums[2];
    int diff = std::abs(closet - target);
    if(diff == 0) {
        return closet;
    }
    
    std::sort(nums.begin(), nums.end());
    for(int k = 0; k < nums.size() - 2; ++k) {
        int left = k + 1;
        int right = nums.size() - 1;
        while(left < right) {
            int sum = nums[k] + nums[left] + nums[right];
            int newDiff = std::abs(sum - target);
            if(newDiff == 0) {
                return sum;
            }
            if(newDiff < diff) {
                diff = newDiff;
                closet = sum;
            }
            if(sum > target) {
                --right;
            } else {
                ++left;
            }
        }
    }
    return closet;
}