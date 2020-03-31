#include "headers.hpp"

// Facebook

// Copy from the solution
// 用一个哈希表来建立连续子数组之和跟其出现次数之间的映射，
// 初始化要加入 {0,1} 这对映射，这是为啥呢，因为我们的解题
// 思路是遍历数组中的数字，用 sum 来记录到当前位置的累加和，
// 我们建立哈希表的目的是为了让我们可以快速的查找 sum-k 是
// 否存在，即是否有连续子数组的和为 sum-k，如果存在的话，那
// 么和为k的子数组一定也存在，这样当 sum 刚好为k的时候，那
// 么数组从起始到当前位置的这段子数组的和就是k，满足题意，如
// 果哈希表中事先没有 m[0] 项的话，这个符合题意的结果就无法累
// 加到结果 res 中，这就是初始化的用途：
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