#include "headers.hpp"

std::vector<std::vector<int>> LeetCode::_0078_Subsets::subsets(std::vector<int>& nums) {
    if(nums.size() == 0) {
        std::vector<std::vector<int>> res;
        res.push_back(std::vector<int>());
        return res;
    }
    return subsets(nums, 0, nums.size());
}

std::vector<std::vector<int>> LeetCode::_0078_Subsets::subsets(std::vector<int>& nums, int beg, int end) {
    if(beg == end) {
        std::vector<std::vector<int>> res;
        res.push_back(std::vector<int>());
        return res;
    }

    int num = nums[beg];
    std::vector<std::vector<int>> sub1 = subsets(nums, beg+1, end);
    std::vector<std::vector<int>> res;
    res.reserve(sub1.size() * 2);
    for(int i = 0; i < sub1.size(); ++i) {
        auto t = sub1[i];
        res.push_back(t);
        t.push_back(num);
        res.push_back(t);
    }
    return res;
}
