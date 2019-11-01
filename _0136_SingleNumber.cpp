#include "headers.hpp"

int LeetCode::_0136_SingleNumber::singleNumber(std::vector<int>& nums) {
    int v = nums[0];
    for(int i = 1; i != nums.size(); ++i)
    {
        v ^= nums[i];
    }
    return v;
}