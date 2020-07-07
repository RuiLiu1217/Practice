#include "headers.hpp"

int LeetCode::_0325_MaximumSizeSubarraySumEqualsK::maxSubArrayLen(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> presumIndex;
    presumIndex[0] = -1;
    int sum = 0;
    int length = 0;
    for(int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if(presumIndex.find(sum) == presumIndex.end()) {
            presumIndex[sum] = i;
        } 
        if(presumIndex.find(sum - k) != presumIndex.end()) {
            length = std::max(length, i - presumIndex[sum - k]);
        }
    }
    return length;
}