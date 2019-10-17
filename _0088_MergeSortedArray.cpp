#include "headers.hpp"

// 换一种思路，从后往前放，这样就不会有问题了;
void LeetCode::_0088_MergeSortedArray::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int pos = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    while(j >= 0) {
        nums1[pos--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
}