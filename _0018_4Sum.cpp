#include "headers.hpp"
#include <algorithm>

std::vector<std::vector<int>> LeetCode::_0018_4Sum::fourSum(std::vector<int>& nums, int target) {
    if(nums.size() < 4) {
        return {};
    }
    std::vector<std::vector<int>> res;
    const int n = nums.size();
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < n - 3; ++i) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j = i + 1; j < n - 2; ++j) {
            if(j > i + 1 && nums[j] == nums[j-1]) continue;
            int left = j + 1;
            int right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target) {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]) {
                        ++left;                           
                    }
                    while(left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                } if(sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
    }
    return res;
}