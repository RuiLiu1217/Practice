#include "headers.hpp"

int LeetCode::_0560_SubarraySumEqualsK::subarraySum(std::vector<int>& nums, int k) {
    if(nums.size() == 0) {
        return 0;
    }

    int preSum = 0;
    int count = 0;
    std::unordered_map<int, int> myMap;
    myMap[0] = 1;
    for(int i = 0; i < nums.size(); ++i) {
        preSum += nums[i];
        count += myMap[preSum - k];
        ++myMap[preSum];
    }
    return count;
}
