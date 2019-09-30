#include "headers.hpp"

int LeetCode::_0033_SearchInRotatedSortedArray::search(std::vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(nums[mid] == target) {
            return mid;
        } else if(nums[start] <= nums[mid]) { // Edge condition is very important "<=" not "<"
            if(target >= nums[start] && target < nums[mid]) { // target ">=" nums[start] not ">"
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else if(target > nums[mid] && target <= nums[end]) { // target "<=" nums[end] not "<"
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
};

