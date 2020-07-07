#include "headers.hpp"

/*
Type: Array
*/

// 这里维护一个栈，用来保存递增序列，相当于上面那种方法的找局部峰值。
// 我们可以看到，直方图矩形面积要最大的话，需要尽可能的使得连续的矩形
// 多，并且最低一块的高度要高。有点像木桶原理一样，总是最低的那块板子
// 决定桶的装水量。那么既然需要用单调栈来做，首先要考虑到底用递增栈，
// 还是用递减栈来做。我们想啊，递增栈是维护递增的顺序，当遇到小于栈顶
// 元素的数就开始处理，而递减栈正好相反，维护递减的顺序，当遇到大于栈
// 顶元素的数开始处理。那么根据这道题的特点，我们需要按从高板子到低板
// 子的顺序处理，先处理最高的板子，宽度为1，然后再处理旁边矮一些的板子
// ，此时长度为2，因为之前的高板子可组成矮板子的矩形 ，因此我们需要一
// 个递增栈，当遇到大的数字直接进栈，而当遇到小于栈顶元素的数字时，就
// 要取出栈顶元素进行处理了，那取出的顺序就是从高板子到矮板子了，于是
// 乎遇到的较小的数字只是一个触发，表示现在需要开始计算矩形面积了，为
// 了使得最后一块板子也被处理，这里用了个小 trick，在高度数组最后面加
// 上一个0，这样原先的最后一个板子也可以被处理了。由于栈顶元素是矩形的
// 高度，那么关键就是求出来宽度，那么跟之前那道 Trapping Rain Water 
// 一样，单调栈中不能放高度，而是需要放坐标。由于我们先取出栈中最高的板
// 子，那么就可以先算出长度为1的矩形面积了，然后再取下一个板子，此时根
// 据矮板子的高度算长度为2的矩形面积，以此类推，知道数字大于栈顶元素为
// 止，再次进栈：
int LeetCode::_0084_LargestRectangleInHistogram::largestRectangleArea(std::vector<int>& heights) {
    int res = 0;
    heights.push_back(0); // 确保最后的bar可以被用到，不需要在循环结束后加上额外的判别条件
    std::stack<int> idx;
    for(int i = 0; i < heights.size(); ++i) {
        while(!idx.empty() && heights[idx.top()] >= heights[i]) { //这里的逻辑有点绕
            int h = heights[idx.top()];
            idx.pop();
            int sidx = idx.empty() ? -1 : idx.top();
            if(h * (i - sidx - 1) > res) {
                res = h * (i - sidx - 1);
            }
        }
        idx.push(i);
    }
    return res;
}

static int largestRectangleArea(std::vector<int>& height) {
    int res = 0;
    std::stack<int> st;
    height.push_back(0);
    for(int i = 0; i < height.size(); ++i) {
        if(st.empty() || height[st.top()] < height[i]) {
            st.push(i);
        } else {
            int cur = st.top(); 
            st.pop();
            res = std::max(res, height[cur] * (st.empty() ? i : (i - st.top() - 1)));
            --i; // need to revert one index
        }
    }
    return res;
}