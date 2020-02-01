#include "headers.hpp"
#include <algorithm>
// DP 题目，但是完全没有想法
// 抄答案的：
// 让我们求这样一个子集合，集合中的任意两个数相互取余均为0，而且提示中说明了要使用DP来解。
// 那么我们考虑，较小数对较大数取余一定不为0，那么问题就变成了看较大数能不能整除这个较小数
// 。那么如果数组是无序的，处理起来就比较麻烦，所以我们首先可以先给数组排序，这样我们每次
// 就只要看后面的数字能否整除前面的数字。定义一个动态数组dp，其中
// dp[i]表示到数字nums[i]位置最大可整除的子集合的长度，
// 还需要一个一维数组parent，来保存上一个能整除的数字的位置，
// 两个整型变量 mx 和 mx_idx 分别表示最大子集合的长度和起始数字的位置，
// 我们可以从后往前遍历数组，对于某个数字再遍历到末尾，
// 在这个过程中，如果nums[j]能整除nums[i], 且dp[i] < dp[j] + 1的话，更新dp[i]和parent[i]，
// 如果dp[i]大于mx了，还要更新mx和mx_idx，最后循环结束后，我们来填res数字，根据parent数组来找到每一个数字，参见代码如下：
std::vector<int> LeetCode::_0368_LargestDivisibleSubset::largestDivisibleSubset(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> dp(nums.size(), 0);
    std::vector<int> parent(nums.size(), 0);
    std::vector<int> res;
    int mx = 0;
    int mx_idx = 0;

    for(int i = nums.size() - 1; i >= 0; --i) {
        for(int j = i; j < nums.size(); ++j) {
            if(nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
                if(mx < dp[i]) {
                    mx = dp[i];
                    mx_idx = i;
                }
            }
        }
    }

    for(int i = 0; i < mx; ++i) {
        res.push_back(nums[mx_idx]);
        mx_idx = parent[mx_idx];
    }
    
    return res;
}