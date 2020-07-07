#include "headers.hpp"

std::vector<int> LeetCode::_0912_SortAnArray::sortArray(std::vector<int>& nums) {
    sortArray(nums, 0, nums.size() - 1);
    return nums;
}

void LeetCode::_0912_SortAnArray::sortArray(std::vector<int>& nums, int start, int end) {
    if(start >= end) {
        return;
    }
    if(end - start == 1) {
        if(nums[start] > nums[end]) {
            std::swap(nums[start], nums[end]);
        }
        return;
    }
    
    int mid = start + (end - start) / 2;
    sortArray(nums, start, mid - 1);
    sortArray(nums, mid, end);
    merge(nums, start, end, mid);
}

void LeetCode::_0912_SortAnArray::merge(std::vector<int>& nums, int start, int end, int mid) {
    int i = start;
    int j = mid;
    std::vector<int> res(end - start + 1, 0);
    int k = 0;
    while(i < mid && j <= end) {
        if(nums[i] < nums[j]) {
            res[k++] = nums[i++];
        } else {
            res[k++] = nums[j++];
        }
    }
    while(i < mid) {
        res[k++] = nums[i++];
    }
    while(j <= end) {
        res[k++] = nums[j++];
    }
    std::copy(res.begin(), res.end(), nums.begin() + start);
}