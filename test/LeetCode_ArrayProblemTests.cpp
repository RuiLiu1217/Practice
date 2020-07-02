#include <gtest/gtest.h>
#include "../LeetCode_ArrayProblems.hpp"
#include <vector>
TEST(LC, _0001_TwoSum) {
    LC::_0001_TwoSum obj;
    std::vector<int> src {2, 7, 11, 15};
    std::vector<int> groundTruth{0, 1};
    EXPECT_EQ(obj.twoSum(src, 9), groundTruth);
}

TEST(LC, LC__0004__Test) {
    LC::_0004_MedianOfTwoSortedArrays obj;
    std::vector<int> nums1{1, 3};
    std::vector<int> nums2{2};
    EXPECT_EQ(obj.findMedianOfSortedArrays(nums1, nums2), 2.0);

    nums1 = {1, 2};
    nums2 = {3, 4};
    EXPECT_EQ(obj.findMedianOfSortedArrays(nums1, nums2), 3.5);
}