#include "headers.hpp"
#include <algorithm>

/* Type: Array */
static int maxSubArray(std::vector<int>& nums) {
    std::vector<int> DP(nums.size(), 0);
    DP[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
        DP[i] = DP[i-1] > 0 ? (nums[i] + DP[i-1]) : nums[i];
    }
    return *std::max_element(DP.begin(), DP.end());
}

int LeetCode::_0053_MaximumSubarray::maxSubArray(std::vector<int>& nums) {
    return maxSubArrayHelp(nums, 0, nums.size()  - 1);
}

int LeetCode::_0053_MaximumSubarray::maxSubArrayHelp(std::vector<int>& nums, int start, int end) {
    if(end - start < 1) {
        return nums[start];
    } else {
        int mid = start + (end - start) / 2;
        int incMid = includeMid(nums, start, end, mid);
        int lftSub = maxSubArrayHelp(nums, start, mid - 1);
        int rghSub = maxSubArrayHelp(nums, mid+1, end);
        int v = std::max(std::max(incMid, lftSub), rghSub);
        return v;
    }
}

int LeetCode::_0053_MaximumSubarray::includeMid(std::vector<int>& nums, int start, int end, int mid) {
    int sum = nums[mid];
    int lft = mid - 1;
    int rgh = mid + 1;

    int lftSum = 0;
    int rghSum = 0;

    int curMaxLft = 0;
    int curMaxRgh = 0;

    while(lft >= start) {
        lftSum += nums[lft];
        if(curMaxLft < lftSum) {
            curMaxLft = lftSum;
        }
        --lft;
    }
    while(rgh <= end) {
        rghSum += nums[rgh];
        if(curMaxRgh < rghSum) {
            curMaxRgh = rghSum;
        }
        ++rgh;
    }
    return (curMaxLft + curMaxRgh + sum);
}

