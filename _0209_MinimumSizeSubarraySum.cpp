#include "headers.hpp"
#include <algorithm>

// 滑动窗口算法
int LeetCode::_0209_MinimumSizeSubarraySum::minSubArrayLen(int s, std::vector<int>& nums) {
    int l = 0;
    int r = 0;
    int n = nums.size();
    int sum = 0;
    int len = INT_MAX;
    while(r < n) {
        sum += nums[r++];
        while(sum >= s) {
            len = std::min(len, r - l);
            sum -= nums[l++];
        }
    }
    return len == INT_MAX ? 0 : len;
}

// nlogn的算法反而比较tricky
// 这个算法利用presum和二分搜索
// 1. sums[0] = 0
// 2. sums[i] = nums[0] + ... + nums[i-1] for  i > 0
// 对于每个 sum[i] >= s, 我们用二分搜索找到这样的 j : sums[j] > sums[i] - s (j < i), 同样 sums[j - 1] <= sums[i] - s.
// 将定义带入公式:
// nums[0] + ... + nums[j-1] > nums[0] + ... + nums[j - 1] + nums[j] + ... + nums[i-1] - s
// nums[0] + ... + nums[j-2] <= nums[0] + ... + nums[j - 2] + nums[j - 1] + ... + nums[i - 1] - s
// 这样就有：
// nums[j - 1] + ... + nums[i - 1] >= s
// nums[j] + ... + nums[i - 1] < s
// 那么 {nums[j-1], ... nums[i-1]} 就是以nums[i-1]结尾的最短的subarray，其和不小于s
// 然后我们遍历所有的 i 
// 需要注意的是，我们要在数组的开头放一个 0， 这是为了以防: nums[3] = 3, s = 3; 这样的情况

static int minSubArrayNlogN(int s, std::vector<int>& nums) {
    int n = nums.size();
    int len = INT_MAX;
    std::vector<int> sums(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        sums[i] = sums[i-1] + nums[i-1];
    }

    for(int i = n; i >= 0 && sums[i] >= s; --i) {
        int j = std::upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
        len = std::min(len, i - j + 1);
    }
    return len == INT_MAX ? 0 : len;
}

