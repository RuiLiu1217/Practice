#include "headers.hpp"

int LeetCode::_0016_3SumCloset::threeSumCloset(std::vector<int>& nums, int target) {
    int closet = nums[0] + nums[1] + nums[2];
    int diff = std::abs(closet - target);
    if(diff == 0) {
        return closet;
    }
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 2; ++i) {
        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int newDif = std::abs(sum - target);
            if(newDif < diff) {
                diff = newDif;
                closet = sum;
            }
            if(sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }
}