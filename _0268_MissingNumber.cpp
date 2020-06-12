#include "headers.hpp"

int LeetCode::_0268_MissingNumber::missingNumber(std::vector<int>& nums) {
    const int N = nums.size();
    long res = std::accumulate(begin(nums), end(nums), 0);
    long tot = N * (N + 1) / 2;
    return tot - res;
}