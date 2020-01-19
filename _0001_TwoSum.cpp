#include "headers.hpp"
#include <algorithm>
std::vector<int> LeetCode::_0001_TwoSum::twoSum(std::vector<int> &nums, int target) {
    std::vector<int> res;
    int i = 0;
    for(auto n : nums)
    {
        auto findIdx = std::find(nums.begin(), nums.end(), target - n); // Find the specific number : target - n
        if(!(findIdx == nums.end() || (findIdx - nums.begin()) == i))
        {
            res.push_back(i);
            res.push_back(static_cast<int>(findIdx - nums.begin()));
            break;
        }
        ++i;
    }
    return res;
}