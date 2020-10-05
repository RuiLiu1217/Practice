#ifndef LEETCODE_SLIDINGWINDOWPROBLEMS_HPP
#define LEETCODE_SLIDINGWINDOWPROBLEMS_HPP
#include <string>
#include <vector>
namespace LC {
/* 
    Tag : sliding Window, hash, string
    Given a string, find the length of the longest substring without repeating characters.

    Input: "abcabcbb"     :      Output: 3 
    Explanation: The answer is "abc", with the length of 3. 
    Input: "bbbbb"        :      Output: 1
    Explanation: The answer is "b", with the length of 1.
    Input: "pwwkew"       :      Output: 3
    Explanation: The answer is "wke", with the length of 3. 
    Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class _0003_LongestSubstringWithoutRepeatingCharacters {
public:
    int lengthOfLongestSubstring(std::string s);
};

/*
You are given an array of integers nums, there is a sliding window of size k which is 
moving from the very left of the array to the very right. You can only see the k numbers 
in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Input: nums = [1], k = 1
Output: [1]

Input: nums = [1,-1], k = 1
Output: [1,-1]

Input: nums = [9,11], k = 2
Output: [11]

Input: nums = [4,-2], k = 2
Output: [4]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/
class _0239_SlidingWindowMaximum {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k);
private:
    std::vector<int> maxSlidingWindow_Deque(std::vector<int>& nums, int k);
    std::vector<int> maxSlidingWindow_MultiSet(std::vector<int>& nums, int k);
    std::vector<int> maxSlidingWindow_Monotic(std::vector<int>& nums, int k);
};


/*
Facebook

Given a string, find the length of the longest substring T that contains at most k 
distinct characters.

Input: s = "eceba", k = 2          :           Output: 3
Explanation: T is "ece" which its length is 3.

Input: s = "aa", k = 1             :           Output: 2
Explanation: T is "aa" which its length is 2.
*/
class _0340_LongestSubstringWithAtMostKDistintCharacters {
public:
    int lengthOfLongestSubstringKDistinct(std::string s, int k);
};

/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note:
You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.
Answers within 10^-5 of the actual value will be accepted as correct.
*/
class _0480_SlidingWindowMedian {
public:
    std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k);
private:
    std::vector<double> medianSlidingWindowMultiSetBased(std::vector<int>& nums, int k);
    std::vector<double> medianSlidingWindowInsertionSortBased(std::vector<int>& nums, int k);
};


/*
Your are given an array of positive integers nums.
Count and print the number of (contiguous) subarrays where the product 
of all the elements in the subarray is less than k.

Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.
*/
class _0713_SubarrayProductLessThanK {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int K);
};

}



#endif
