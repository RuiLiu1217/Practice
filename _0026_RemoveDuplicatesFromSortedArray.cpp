#include "headers.hpp"

int LeetCode::_0026_RemoveDuplicatesFromSortedArray::removeDuplicates(std::vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    int slow = 0;
    int fast = 0;
    while(fast < nums.size()) { // How to compare int with size_t, this is not safe
        if(nums[slow] == nums[fast]) {
            ++fast;
        } else {
            ++slow;
            nums[slow] = nums[fast];
            ++fast;
        }
    }
    
    return slow + 1;
}