#include "headers.hpp"
#include <algorithm>

/*

Type: Array

*/

std::vector<std::vector<int>> LeetCode::_0090_SubsetII::subsetsWithDup(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> subset;
    std::vector<std::vector<int>> res;
    generateAllSubsets(nums,subset, 0, res);
    return res;
}
    
void LeetCode::_0090_SubsetII::generateAllSubsets(std::vector<int>& nums, std::vector<int>& subset,
                        int index, std::vector<std::vector<int>>& res) {
    res.push_back(subset);
    for(int i = index; i < nums.size();) {
        subset.push_back(nums[i]);
        generateAllSubsets(nums, subset, i + 1, res);
        int j = i;
        while(j < nums.size() && nums[i] == nums[j]) {
            ++j;
        }
        if(j != i) {
            i = j;
        } else {
            ++i;
        }            
        subset.pop_back();
    }
}

// Remove duplicate
// std::sort(begin(nums), end(nums));
static void subset(std::vector<std::vector<int>>& res, std::vector<int>& tmp,
            std::vector<int>& nums, int pos) {
    res.push_back(tmp);
    for(int i = pos; i < nums.size(); ++i) {
        if(i != pos && nums[i] == nums[i-1]) {
            continue;
        }
        tmp.push_back(nums[i]);
        subset(res, tmp, nums, i + 1); // i + 1, not pos + 1
        tmp.pop_back();
    }
}