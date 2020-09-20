#include "headers.hpp"

int LeetCode::_0525_ContiguousArray::findMaxLength(std::vector<int>& nums) {
    if(nums.size() == 0) {
        return 0;
    }
    std::unordered_map<int, int> firstIdx; // Record the first index that we meet the accumulated value
    firstIdx[0] = -1; // Assume that we meet the accumulated 0 is at a virtual place -1
    const int V = nums[0];
    int c = 0;
    int len = INT_MIN;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] == V) {
            ++c;
        } else {
            --c;
        }

        if(firstIdx.count(c)) {
            len = std::max(len, i - firstIdx[c]);
        } else {
            firstIdx[c] = i;
        }
    }
    return len == INT_MIN ? 0 : len;
}