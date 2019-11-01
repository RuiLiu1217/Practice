#include "headers.hpp"
#include <algorithm>
// There is better solution without sorting. (TODO)
int LeetCode::_0169_MajorityElement::majorityElement(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}