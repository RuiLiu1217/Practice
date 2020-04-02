#include "headers.hpp"
#include <queue>
#include <algorithm>

// Facebook

int LeetCode::_0215_KthLargestElementInAnArray::findKthLargest(std::vector<int>& nums, int k) {
    std::nth_element(begin(nums), begin(nums) + k-1, end(nums), std::greater<int>());
    return nums[k-1];
}