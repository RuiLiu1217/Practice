#include "headers.hpp"
// Tag: array, binary search, recursive, complexity analysis
// TODO
int LeetCode::_0154_FindMinimumInRotatedSortedArrayII::findMin(std::vector<int>& nums) {
    return findMin(nums, 0, nums.size() - 1);
}

int LeetCode::_0154_FindMinimumInRotatedSortedArrayII::findMin(std::vector<int>& nums, int start, int end) {
    if(start + 1 >= end) {
        return std::min(nums[start], nums[end]);
    }
    if(nums[start] < nums[end]) {
        return nums[start];
    }
    int mid = start + (end - start) / 2;
    return std::min(findMin(nums, start, mid - 1),  findMin(nums, mid, end));
}