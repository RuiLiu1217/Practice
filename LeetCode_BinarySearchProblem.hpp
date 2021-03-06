#ifndef LEETCODE_BINARYSEARCHPROBLEM_HPP
#define LEETCODE_BINARYSEARCHPROBLEM_HPP
#include "HeaderFiles.hpp"
namespace LC {
    /*
Tag: Binary search.
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer 
part of the result is returned.

Input: 4           :          Output: 2
Input: 8           :          Output: 2

Explanation: The square root of 8 is 2.82842..., and since
the decimal part is truncated, 2 is returned.
*/
class _0069_SqrtX {
public:
    // The sqrt of N is just to get the solution of f(x) = x^2 - N when y = 0;
    // f'(x) = 2x, therefore the slope of f(x) when x = x_n is 2x_n;
    // Therefore the slope line is f(x) - (x_n^2 - N) = 2 x_n (x - x_n);, let f(x) = 0,
    // we have:  x_n+1 = (x_n + N / x_n) / 2
    // ! Newton's method
    int mySqrt(int x) {
        if(x == 0) {
            return 0;
        }
        double g = x / 2.0;
        int lasRes = g;
        int curRes = lasRes + 1;
        while(curRes != lasRes) {
            lasRes = curRes;
            g = (g + x / g) * 0.5;
            curRes = g;
        }
        return curRes;
    }
};

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

/*
You are given a sorted array consisting of only integers where every 
element appears exactly twice, except for one element which appears 
exactly once. Find this single element that appears only once.

Input: [1,1,2,3,3,4,4,8,8]
Output: 2

Input: [3,3,7,7,10,11,11]
Output: 10
*/
class _0540_SingleElementInASortedArray {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        return singleNonDuplicate(nums, 0, nums.size()); 
    }
    int singleNonDuplicate(std::vector<int>& nums, int start, int end) {
        if(start + 1 == end) {
            return nums[start];
        }
        if(start + 3 == end) {
            int num = nums[start];
            num ^= nums[start + 1];
            num ^= nums[start + 2];
            return num;
        }
        int mid = start + (end - start) / 2;
        if(nums[mid] == nums[mid-1]) {
            if((mid - start) % 2 == 0) {
                return singleNonDuplicate(nums, start, mid + 1);
            } else {
                return singleNonDuplicate(nums, mid + 1, end);
            }
        } else if(nums[mid] == nums[mid+1]) {
            if((end - mid) % 2) {
                return singleNonDuplicate(nums, mid, end);
            } else {
                return singleNonDuplicate(nums, start, mid);
            }            
        } else {
            return nums[mid];
        }
    }
};


/*
Koko loves to eat bananas. There are N piles of bananas, the i-th pile has piles[i] bananas. 
The guards have gone and will come back in H hours.

Koko can decide her bananas-per-hour eating speed of K. Each hour, she chooses some pile of 
bananas, and eats K bananas from that pile. If the pile has less than K bananas, she eats all 
of them instead, and won't eat any more bananas during this hour.

Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
Return the minimum integer K such that she can eat all the bananas within H hours.

Input: piles = [3,6,7,11], H = 8
Output: 4

Input: piles = [30,11,23,4,20], H = 5
Output: 30

Input: piles = [30,11,23,4,20], H = 6
Output: 23
 
Note:

1 <= piles.length <= 10^4
piles.length <= H <= 10^9
1 <= piles[i] <= 10^9
*/
class _0875_KokoEatingBananas {
public:
    int minEatingSpeed(std::vector<int>& piles, int H) {
        int l = 1;
        int r = *std::max_element(begin(piles), end(piles));
        while(l < r) {
            int m = l + (r - l) / 2;
            int useHours = std::accumulate(begin(piles), end(piles), 0, [=](int init, int pN) {
                return init + (pN + m - 1) / m;
            });
            if(useHours > H) {
                l = m + 1; // 吃快点
            } else {
                r = m;
            }
        }
        return l;
    }
};



}
#endif