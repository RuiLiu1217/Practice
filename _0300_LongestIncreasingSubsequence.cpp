#include "headers.hpp"

int LeetCode::_0300_LongestIncreasingSubsequence::lengthOfLIS(std::vector<int>& nums) {
    return lengthOfLIS_N2(nums);
}

// 递归计算最长子数组, 就是计算最长子数组以 nums[i-1] 结尾的长度。
int LeetCode::_0300_LongestIncreasingSubsequence::lengthOfLIS_N2(std::vector<int>& nums) {
    if(nums.size() == 0) {
        return 0;
    }
    std::vector<int> DP(nums.size(), 0);

    DP[0] = 1;
    int res = 1;
    for(int i = 1; i < nums.size(); ++i) {
        int maxLen = 0;
        for(int j = i - 1; j >= 0; --j) {
            if(nums[i] > nums[j]) {
                maxLen = std::max(maxLen, DP[j]);
            }
        }
        DP[i] = maxLen + 1;
        res = std::max(res, DP[i]);
    }
    return DP.back();
}


/*
NlogN solution:
In this approach, we scan the array from left to right. We also make use 
of a dp array initialized with all 0's. This dp array is meant to store the 
increasing subsequence formed by including the currently encountered element. 
While traversing the numsnums array, we keep on filling the dp array with 
the elements encountered so far. For the element corresponding to the j-th index 
(nums[j]), we determine its correct position in the dp array(say i-th index) by 
making use of Binary Search(which can be used since the dp array is storing 
increasing subsequence) and also insert it at the correct position. 

An important point to be noted is that for Binary Search, we consider only that 
portion of the dp array in which we have made the updates by inserting some elements 
at their correct positions (which remains always sorted). Thus, only the elements 
up to the i-th index in the dp array can determine the position of the current element 
in it. Since, the element enters its correct position(ii) in an ascending order in the 
dp array, the subsequence formed so far in it is surely an increasing subsequence. 
Whenever this position index i becomes equal to the length of the LIS formed so far
(len), it means, we need to update the lenlen as len = len + 1.

Note: dp array does not result in longest increasing subsequence, but length of dp array 
will give you length of LIS.

Consider the example:

input: [0, 8, 4, 12, 2]

dp: [0]
dp: [0, 8]
dp: [0, 4]
dp: [0, 4, 12]
dp: [0, 2, 12] which is not the longest increasing subsequence, but length of dpdp array 
results in length of Longest Increasing Subsequence.
*/
int LeetCode::_0300_LongestIncreasingSubsequence::lengthOfLIS_NlogN(std::vector<int>& nums) {
    std::vector<int> DP(nums.size(), 0);
    int len = 0;
    for(int n : nums) {
        auto it = std::lower_bound(DP.begin(), DP.begin() + len, n);
        *(it) = n;
        
        if(it == DP.begin() + len) {
            ++len;
        }
    }
    return len;
}
