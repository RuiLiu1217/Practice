#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0077_Combinations::combine(int n, int k) {
    std::vector<int> nums(n, 0);
    for(int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }

    std::vector<int> used(n, 0);
    std::vector<int> tmp;
    std::vector<std::vector<int>> res;
    combine(nums, used, 0, k, tmp, res);
    return res;
}

void LeetCode::_0077_Combinations::combine(std::vector<int>& nums, std::vector<int>& used, int s, int k, std::vector<int>& tmp, std::vector<std::vector<int>>& res) {
    if(s == k) {
        res.push_back(tmp);
        return;
    }
    for(int i = 0; i < nums.size(); ++i) {
        if(!used[i]) {
            if(!tmp.empty() && tmp.back() < nums[i] || tmp.empty()) {
                used[i] = 1;
                tmp.push_back(nums[i]);
                combine(nums, used, s + 1, k, tmp, res);
                tmp.pop_back();
                used[i] = 0;
            }
        }
    }
}