#ifndef LEETCODE_ARRAYPROBLEMS_HPP
#define LEETCODE_ARRAYPROBLEMS_HPP

#include <vector>

namespace LC {
/*  Tag: array, Hash
    Given an array of integers, return indices of the two 
    numbers such that they add up to a specific target.
    You may assume that each input would have exactly one 
    solution, and you may not use the same element twice.
    Example:
        Given nums = [2, 7, 11, 15], target = 9,
        Because nums[0] + nums[1] = 2 + 7 = 9,
    Return [0, 1].
    */
class _0001_TwoSum {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target);
};


/* Tag : Binary Search, array
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
*/
class _0004_MedianOfTwoSortedArrays {
public:
    double findMedianOfSortedArrays(
        std::vector<int>& nums1,
        std::vector<int>& nums2);
};


}

#endif