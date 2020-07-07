#include "headers.hpp"
#include <algorithm>

int LeetCode::_0561_ArrayPartitionI::arrayPairSum(std::vector<int>& nums) {
    std::vector<int> nnums = nums;
    std::sort(nnums.begin(), nnums.end());
    int sum = 0;
    for(int i = 0; i != nnums.size(); i = i + 2)
    {
        sum += nnums[i];
    }
    return sum;
}