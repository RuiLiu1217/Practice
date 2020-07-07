#include "headers.hpp"
/*
Type: Array
*/
int LeetCode::_0035_SearchInsertPosition::searchInsert(std::vector<int>& nums, int target) {
    if(nums.size() == 0) {
        return 1;
    }

    int mid = 0;
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right) {
        mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            return mid;
        }
        else if(target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}