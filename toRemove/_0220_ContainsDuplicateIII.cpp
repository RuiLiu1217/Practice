#include "headers.hpp"
#include <set>
// Tag: multiset, special
// TODO: Copy from the solution
// 认真学习这里面的各种multiset 以及 prev， next, begin，end 迭代器函数的用法
// Maintaining a sliding window of sorted numbers of k + 1. 
// After the i-th number was inserted into the sliding window, 
// check whether its left and right neighbors satisfy 
//  abs(nums[i] – neighbor) <= t
bool LeetCode::_0220_ContainsDuplicateIII::containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
    std::multiset<long> s;
    for(int i = 0; i < nums.size(); ++i) {
        if(i > k) {
            s.erase(s.find(nums[i - k - 1]));
        }

        auto it = s.insert(nums[i]);
        if(it != begin(s) && *it - *prev(it) <= t) {
            return true;
        }
        if(next(it) != end(s) && *next(it) - *it <= t) {
            return true;
        }
    }
    return false;
}