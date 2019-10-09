#include "headers.hpp"
void LeetCode::_0075_SortColors::sortColors(std::vector<int>& nums) {
    int start1Idx = 0;
    int start2Idx = 0;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] == 0) {
            nums[i] = nums[start2Idx];
            nums[start2Idx] = nums[start1Idx];
            nums[start1Idx] = 0;
            ++start2Idx;
            ++start1Idx;
        } else if(nums[i] == 1) {
            nums[i] = nums[start2Idx];
            nums[start2Idx] = 1;
            ++start2Idx;
        } else {
            
        }
    }
}
