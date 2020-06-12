#include "headers.hpp"

void LeetCode::_0283_MoveZeros::moveZeroes(std::vector<int>& nums) {
    int slow = 0;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] != 0) {
            nums[slow++] = nums[i];
        }
    }
    for(; slow < nums.size(); ++slow) {
        nums[slow] = 0;
    }
}