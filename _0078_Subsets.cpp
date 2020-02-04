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

/*
Shorter solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        std::vector<std::vector<int>> res = subsets(nums, nums.size());
        return res;
    }
    std::vector<std::vector<int>> subsets(std::vector<int>& nums, int length) {
        if(length == 0) {
            std::vector<std::vector<int>> res;
            std::vector<int> t;
            res.push_back(t);
            return res;
        }
        std::vector<std::vector<int>> tmp = subsets(nums, length-1);
        std::vector<std::vector<int>> res;
        for(int i = 0; i < tmp.size(); ++i) {
            res.push_back(tmp[i]);
            tmp[i].push_back(nums[length-1]);
            res.push_back(tmp[i]);
        }
        return res;
    }
};
*/