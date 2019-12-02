#include "headers.hpp"

int LeetCode::_0540_SingleElementInASortedArray::singleNonDuplicate(std::vector<int>& nums) {
    return singleNoDuplicate(nums, 0, nums.size());
}
int LeetCode::_0540_SingleElementInASortedArray::singleNoDuplicate(std::vector<int>& nums, int beg, int end) {
    if(beg == end && beg >= 0 && beg < nums.size()) {
        return nums[beg];
    }

    int mid = beg + (end - beg) / 2;
    if(mid == beg) {
        return nums[mid];
    }
    if(nums[mid] == nums[mid - 1]) {
        if((end - mid) % 2 != 0) {
            return singleNoDuplicate(nums, beg, mid-1);
        } else {
            return singleNoDuplicate(nums, mid+1, end);
        }
    } else if(nums[mid] == nums[mid + 1]) {
        if((mid - beg) % 2 == 0) {
            return singleNoDuplicate(nums, mid + 2, end);
        } else {
            return singleNoDuplicate(nums, beg, mid);
        }
    } else {
        return nums[mid];
    }
}

