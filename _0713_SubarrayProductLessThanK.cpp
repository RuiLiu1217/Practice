#include "headers.hpp"

int LeetCode::_0713_SubarrayProductLessThanK::numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    if(k <= 1) {
        return 0;
    }
    int res = 0;
    int prod = 1;
    int left = 0;
    for(int i = 0; i < nums.size(); ++i) {
        prod *= nums[i];
        while(left <= i && prod >= k) {
            prod /= nums[left];
            ++left;
        }
        res += i - left + 1;
    }
    return res;
}