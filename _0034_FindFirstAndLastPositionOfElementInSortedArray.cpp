#include "headers.hpp"

std::vector<int> LeetCode::_0034_FindFirstAndLastPositionOfElementInSortedArray::searchRange(std::vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end) {
        if(nums[start] == target && nums[end] == target) {
            return {start, end};
        }

        int mid = start + (end - start) / 2;
        if(nums[mid] < target) {
            start = mid + 1;
        } else if(nums[mid] > target) {
            end = mid - 1;
        } else {
            if(nums[start] < target) {
                ++start;
            }
            if(nums[end] > target) {
                --end;
            }
        }
    }
    return {-1, -1};
}