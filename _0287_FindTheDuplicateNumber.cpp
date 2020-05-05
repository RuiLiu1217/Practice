#include "headers.hpp"

// Binary Search based
int LeetCode::_0287_FindTheDuplicateNumber::findDuplicate(std::vector<int>& nums) {
    int left = 1, right = nums.size();
    while (left < right){
        int mid = left + (right - left) / 2, cnt = 0;
        for (int num : nums) {
            if (num <= mid) ++cnt;
        }
        if (cnt <= mid) left = mid + 1;
        else right = mid;
    }    
    return right;
}

// Very similar to the "Linked List Cycle II"
// 其核心思想快慢指针在之前的题目 Linked List Cycle II 中就有应用，
// 这里应用的更加巧妙一些，由于题目限定了区间 [1,n]，所以可以巧妙的
// 利用坐标和数值之间相互转换，而由于重复数字的存在，那么一定会形成
// 环，用快慢指针可以找到环并确定环的起始位置，确实是太巧妙了！
static int findDuplicate_LinkListCycleII(std::vector<int>& nums) {
    int slow = 0, fast = 0, t = 0;
    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) break;
    }
    while (true) {
        slow = nums[slow];
        t = nums[t];
        if (slow == t) break;
    }
    return slow;
}

// 思路是遍历每一位，然后对于 32 位中的每一个位 bit，都遍历一遍从0到 n-1，
// 将0到 n-1 中的每一个数都跟 bit 相 ‘与’，若大于0，则计数器 cnt1 自增1。
// 同时0到 n-1 也可以当作 nums 数组的下标，从而让 nums 数组中的每个数字也
// 跟 bit 相 ‘与’，若大于0，则计数器 cnt2 自增1。最后比较若 cnt2 大于 cnt1，
// 则将 bit 加入结果 res 中。这是为啥呢，因为对于每一位，0到 n-1 中所有数
// 字中该位上的1的个数应该是固定的，如果 nums 数组中所有数字中该位上1的个数
// 多了，说明重复数字在该位上一定是1，这样我们把重复数字的所有为1的位都累加
// 起来，就可以还原出了这个重复数字，参见代码如下：
static int findDuplicate_LinkListCycleII(std::vector<int>& nums) {
    int res = 0, n = nums.size();
    for (int i = 0; i < 32; ++i) {
        int bit = (1 << i), cnt1 = 0, cnt2 = 0;
        for (int k = 0; k < n; ++k) {
            if ((k & bit) > 0) ++cnt1;
            if ((nums[k] & bit) > 0) ++cnt2;
        }
        if (cnt2 > cnt1) res += bit;
    }
    return res;
}
