#ifndef LEETCODE_BINARYSEARCHPROBLEM_HPP
#define LEETCODE_BINARYSEARCHPROBLEM_HPP
#include "HeaderFiles.hpp"
namespace LC {


/*
Tag: binary search
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element. You may assume no duplicate exists in the array.

Input: [3,4,5,1,2] 
Output: 1

Input: [4,5,6,7,0,1,2]
Output: 0
*/
class _0153_FindMinimumInRotatedSortedArray {
public:
    /* 
    ! Important problem
        Classic binary search problem.
        Looking at subarray with index [start,end]. We can find out that if 
        the first member is less than the last member, there's no rotation 
        in the array. So we could directly return the first element in this 
        subarray.

        If the first element is larger than the last one, then we compute 
        the element in the middle, and compare it with the first element. 
        If value of the element in the middle is larger than the first 
        element, we know the rotation is at the second half of this array. 
        Else, it is in the first half in the array.
    */
    int findMin(std::vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while(start < end) {
            if(nums[start] < nums[end]) {
                return nums[start];
            }
            int mid = start + (end - start) / 2;

            if(nums[mid] >= nums[start]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[start];
    }
};

/*
Suppose an array sorted in ascending order is rotated at some pivot 
unknown to you beforehand.
(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Find the minimum element.
! The array may contain duplicates.

Input: [1,3,5]
Output: 1

Input: [2,2,2,0,1]
Output: 0
Note:
This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?
*/
class _0154_FindMinimumInRotatedSortedArrayII {
public:
    int findMin(std::vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
private:
    int findMin(std::vector<int>& nums, int start, int end) {
        if(start + 1 >= end) {
            return std::min(nums[start], nums[end]);
        }
        if(nums[start] < nums[end]) { // ! 说明已经是有序的数组
            return nums[start];
        }
        int mid = start + (end - start) / 2;
        return std::min(findMin(nums, start, mid - 1),  findMin(nums, mid, end));
    }
};

/*
Facebook

You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. Since 
each version is developed based on the previous version, all the versions after 
a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad 
one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version 
is bad. Implement a function to find the first bad version. You should minimize 
the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
*/
class _0278_FirstBadVersion {
public:
    int firstBadVersion(int n);
};

}
#endif