#include "headers.hpp"

int LeetCode::_0162_FindPeakElement::findPeakElement(std::vector<int>& nums) {
    if(nums.size() == 1) {
        return 0;
    } else if(nums.size() == 2) {
        if(nums[0] > nums[1]) {
            return 0;
        } else {
            return 1;
        }
    }
    int i = 1;
    for(; i < nums.size() - 1; ++i) {
        if(i == 1 && nums[i-1] > nums[i]) {
            return 0;
        }
        if(i == nums.size() - 2 && nums[i] < nums[i+1]) {
            return i+1;
        }
        if(nums[i-1] < nums[i] && nums[i] > nums[i+1]) {
            return i;
        }
    }
    return i;
}