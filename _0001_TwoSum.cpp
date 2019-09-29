#include "headers.hpp"
#include <unordered_map>

std::vector<int> LeetCode::_0001_TwoSum::twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;
    for(int i = 0 ; i < nums.size(); ++i) {
        if(map.find(nums[i]) != map.end()) {
            return {map[nums[i]], i};
        } else {
            map[target - nums[i]] = i;
        }
    }
    return {};
}