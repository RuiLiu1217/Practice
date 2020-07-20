#include "LeetCode_BitOperationProblems.hpp"

int LC::_0136_SingleNumber::singleNumber(std::vector<int>& nums) {
    int v = nums[0];
    for(int i = 1; i != nums.size(); ++i)
    {
        v ^= nums[i];
    }
    return v;
}