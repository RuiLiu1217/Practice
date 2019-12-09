#include "headers.hpp"
// 用一个栈存放所有的index， index中对应的值呈递增形式。
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
}