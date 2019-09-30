#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0015_3Sum::threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    if(nums.empty() || nums.back() < 0 || nums.front() > 0) {
        return {};
    }

    for(int k = 0; k < nums.size() - 2; ++k) {
        if(nums[k] > 0) {
            break;
        }

        if(k > 0 && nums[k] == nums[k - 1]) { // avoid repeated results.
            continue;
        }
    }
}