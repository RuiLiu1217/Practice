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
Tag: Sliding Windows
Google, Facebook
TODO: ending edge cases, which is not easy to debug

Given a string S and a string T, find the minimum window in S which will 
contain all the characters in T in complexity O(n).

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
*/
class _0076_MinimumWindowSubstring {
public:
    std::string minWindow(std::string s, std::string t);
};

/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/
class _0159_LongestSubstringWithAtMostTwoDistinctCharacters {
public:
    int lengthOfLongestSubstringTwoDistinct(std::string s);
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

/*
In a row of trees, the i-th tree produces fruit with type tree[i].
You start at any tree of your choice, then repeatedly perform the following steps:

1. Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
2. Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.

Note that you do not have any choice after the initial choice of starting tree: you must 
perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.
You have two baskets, and each basket can carry any quantity of fruit, but you want each 
basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

Input: [1,2,1]
Output: 3
Explanation: We can collect [1,2,1].

Input: [0,1,2,2]
Output: 3
Explanation: We can collect [1,2,2].
If we started at the first tree, we would only collect [0, 1].

Input: [1,2,3,2,2]
Output: 4
Explanation: We can collect [2,3,2,2].
If we started at the first tree, we would only collect [1, 2].

Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5
Explanation: We can collect [1,2,1,1,2].
If we started at the first tree or the eighth tree, we would only collect 4 fruits.

1 <= tree.length <= 40000
0 <= tree[i] < tree.length
*/
class _0904_FruitInoBackets {
public:
    int totalFruit(std::vector<int>& tree);
};


/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one 
occurrence of all these characters a, b and c.

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one 
occurrence of the characters a, b and c are "abc", "abca", 
"abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" 
and "abc" (again). 

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one 
occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Input: s = "abc"
Output: 1

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/
class _1358_NumberOfSubstringsContainingAllThreeCharacters {
private:
    int count[3];
    bool contains3() {
        return count[0] >= 1 && count[1] >= 1 && count[2] >= 1;
    }
public:
    int numberOfSubstrings(std::string s);
};


}
#endif
