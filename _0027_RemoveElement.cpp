#include "headers.hpp"
/*
Type : Array
*/
int LeetCode::_0027_RemoveElement::removeElement(std::vector<int>& nums, int val) {
    int slowIdx = 0;
    int fastIdx = 0;
    while(fastIdx != nums.size())
    {
        if(nums[fastIdx] == val)
        {
            ++fastIdx;
        } else {
            nums[slowIdx++] = nums[fastIdx++];
        }
    }
    return slowIdx;      
}