#include "headers.hpp"
#include <queue>

int LeetCode::_0215_KthLargestElementInAnArray::findKthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int> q;
    for(int i = 0; i < nums.size(); ++i) {
        q.push(nums[i]);
    }
    int t = k;
    int m = 0;
    while(t) {
        m = q.top();
        q.pop();
        --t;
    }
    return m;
}