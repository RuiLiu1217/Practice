#include "headers.hpp"

void LeetCode::_0280_WiggleSort::wiggleSort(std::vector<int>& nums) {
    if(nums.size() <= 1) {
        return;
    }
    
    bool shouldIncreasing = true;
    for(int i = 1; i < nums.size(); ++i) {
        if (shouldIncreasing && nums[i] < nums[i-1]) {
            std::swap(nums[i], nums[i-1]);                
        } else if(!shouldIncreasing && nums[i] > nums[i-1]) {
            std::swap(nums[i], nums[i-1]);
        }
        shouldIncreasing = !shouldIncreasing;
    }
}