#include "headers.hpp"
#include <algorithm>
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
