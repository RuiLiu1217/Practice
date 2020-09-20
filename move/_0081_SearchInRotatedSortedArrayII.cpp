#include "headers.hpp"
/*
Type: Array
*/
bool LeetCode::_0081_SearchInRotatedSortedArrayII::search(std::vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(nums[mid] == target) {
            return true;
        }
        // Remove duplicate
        if(nums[mid] == nums[start] && nums[mid] == nums[end]) {
            ++start;
            --end;
        } else {
            if(nums[start] <= nums[mid]) {
                if(target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if(target >= nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
    }
    return false;
}