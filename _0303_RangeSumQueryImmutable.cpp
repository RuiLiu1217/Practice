#include "headers.hpp"

LeetCode::_0303_RangeSumQuery_Immutable::_0303_RangeSumQuery_Immutable(std::vector<int>& nums) {
    mSum.resize(nums.size() + 1, 0);
    int n = nums.size();
    if(n == 0) return;
    mSum[0] = nums[0];
    for(int i = 1; i < n; ++i) {
        mSum[i] = nums[i] + mSum[i-1];
    }
}

int LeetCode::_0303_RangeSumQuery_Immutable::sumRange(int i, int j) {
    if(i == 0) {
        return mSum[j];
    }
    return mSum[j] - mSum[i-1];
}