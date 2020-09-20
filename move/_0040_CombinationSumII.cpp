#include "headers.hpp"
#include <algorithm>
/*
Type: Array
*/
void LeetCode::_0040_CombinationSumII::choose(std::vector<int>& candidates, int target, int begin) {
    if(target == 0) {
        res.push_back(temp);
        return;
    }

    if(target < 0) {
        return;
    }

    for(int i = begin; i < candidates.size(); ++i) {
        temp.push_back(candidates[i]);
        choose(candidates, target - candidates[i], i + 1);
        while(i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {
            ++i;
        }
        temp.pop_back();
    }
}

std::vector<std::vector<int>> LeetCode::_0040_CombinationSumII::combinationSum2(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    choose(candidates, target, 0);
    return res;
}


/* Another solution
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::unordered_map<int,int> mp;
        for(int i = 0; i < candidates.size(); ++i) {
            ++mp[candidates[i]];
        }
        std::vector<int> tmp;
        std::vector<std::vector<int>> res;
        combinationSum2(mp, target, tmp, res);
        return res;
        
    }
    void combinationSum2(std::unordered_map<int, int>& candidates, int target, std::vector<int>& tmp, std::vector<std::vector<int>>& res) {
        if(target < 0) {
            return;
        }
        if(target == 0) {
            res.push_back(tmp);
        }
        
        for(auto& c : candidates) {
            if(c.second > 0) {
                if(tmp.empty() || (!tmp.empty() && tmp.back() <= c.first)) {
                    --c.second;
                    tmp.push_back(c.first);
                    combinationSum2(candidates, target - c.first, tmp, res);
                    tmp.pop_back();
                    ++c.second;
                }
            }
        }
    }
};
*/