#include "headers.hpp"

// Facebook

bool LeetCode::_0523_ContinuousSubarraySum::checkSubarraySum(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> remain{{0, -1}};
    int sum = 0;
    for(int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        int t = (k == 0) ? sum : (sum % k);
        if(remain.count(t)) {
            if(i - remain[t] > 1) {
                return true;
            }
        } else {
            remain[t] = i;
        }
    }
    return false;
}