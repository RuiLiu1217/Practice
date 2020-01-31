#include "headers.hpp"
#include <algorithm>
std::vector<std::vector<int>> LeetCode::_0015_3Sum::threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    if(nums.empty() || nums.size() < 3 || nums.front() > 0 || nums.back() < 0) {
        return {};
    }

    for(int k = 0; k < nums.size() - 2; ++k) {
        if(nums[k] > 0) {
            break;
        }
        if(k > 0 && nums[k] == nums[k-1]) {
            continue;
        }

        int i = k + 1;
        int j = nums.size() - 1;
        int target = -nums[k];
        while(i < j) {
            if(nums[i] + nums[j] == target) {
                res.push_back({nums[k], nums[i], nums[j]});
                while(i < j && nums[i] == nums[i+1]) {
                    ++i;
                }
                while(i < j && nums[j] == nums[j-1]) {
                    --j;
                }
                ++i;
                --j;
            } else if(nums[i] + nums[j] > target) {
                --j;
            } else {
                ++i;
            }
        }
    }
    return res;
}