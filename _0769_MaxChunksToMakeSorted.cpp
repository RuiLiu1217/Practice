#include "headers.hpp"

// 这道题如果知道背后的想法会很简单，如果想不到，属于感觉无从下手类型的.
// 我们先看这样的一个例子，比如原始的数组如下:
// original :  0, 2, 1, 4, 3, 5, 7, 6
// 既然是个全排列的数组，那么长度就是最大值 + 1 = 8
// 我们用一个数组 max 保存从左往右以次观察时候遇到的最大值，
// max      :  0, 2, 2, 4, 4, 5, 7, 7
// 然后对这个数组做一个排序
// sorted   :  0, 1, 2, 3, 4, 5, 6, 7
// 核心算法就是：如果排序后的数组对应位置上的值跟max数组中看到的最大值相同，就需要加一个chunk
int LeetCode::_0769_MaxChunksToMakeSorted::maxChunksToSorted(std::vector<int>& arr) {
    int count = 0;
    int maxV = arr[0];
    for(int i = 0; i < arr.size(); ++i) {
        maxV = std::max(maxV, arr[i]);
        if(maxV == i) {
            ++count;
        }
    }
    return count;
}