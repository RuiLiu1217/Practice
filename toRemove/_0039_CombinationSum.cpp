#include "headers.hpp"
/*
Type: Array
*/
std::vector<std::vector<int>> LeetCode::_0039_CombinationSum::combinationSum(std::vector<int>& candidates, int target) {
    std::vector<int> tmp;
    std::vector<std::vector<int>> res;
    combinationSum(candidates, target, tmp, res);
    return res;
}

void LeetCode::_0039_CombinationSum::combinationSum(std::vector<int>& candidates, int target, std::vector<int>& tmp, std::vector<std::vector<int>>& res) {
    if(target < 0) {
        return;
    }
    if(target == 0) {
        res.push_back(tmp);
    }

    for(int i = 0; i < candidates.size(); ++i) {
        if(tmp.empty() || (!tmp.empty() && tmp.back() <= candidates[i])) { // <= is to avoid reselect for example, after 1, 2 are generated, we should not generate 2, 1 again.
            tmp.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], tmp, res);
            tmp.pop_back();
        }
    }
}
    