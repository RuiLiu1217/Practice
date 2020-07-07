#include "headers.hpp"


std::vector<int> LeetCode::_0239_SlidingWindowMaximum::maxSlidingWindow(std::vector<int>& nums, int k) {
    if(k == 1) {
        return nums;
    }
    std::deque<int> qIndex;
    std::vector<int> result;
    for(int i = 0; i < nums.size(); ++i) {
        if(qIndex.empty()) {
            qIndex.push_back(i);
        } else {
            while(!qIndex.empty() && nums[qIndex.back()] < nums[i]) {
                qIndex.pop_back();
            }
            qIndex.push_back(i);
        }
        
        while(!qIndex.empty() && i - qIndex.front() >= k) {
            qIndex.pop_front();
        }
        if(i >= k - 1) {
            result.push_back(nums[qIndex.front()]);
        }
        
    }
    return result;
}

// There is also dynamic programming solution which is very elegant: 
// https://leetcode.com/problems/sliding-window-maximum/solution/