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

/*
much faster solution:

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    int i = 0;
    vector<int> p(k, 0);
    while (i >= 0) {
        p[i]++;
        if (p[i] > n) --i;
        else if (i == k - 1) result.push_back(p);
        else {
            ++i;
            p[i] = p[i - 1];
        }
    }
    return result;


// Much better solution
  class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> res;
        if(n < k) {
            return res;
        }
        std::vector<int> temp;
        combine(res,temp,0,0,n,k);
        return res;
        
    }
    void combine(std::vector<std::vector<int>> &res, std::vector<int> &temp, int start, int num, int n, int k){
        if(num == k){
            res.push_back(temp);
            return;
        }
        for(int i = start;i<n;i++){
            temp.push_back(i+1);
            combine(res,temp,i+1,num+1,n,k);
            temp.pop_back();
            }
        }
};

*/