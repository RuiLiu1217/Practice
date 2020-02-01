#include "headers.hpp"


std::vector<std::vector<int>> LeetCode::_0047_PermutationsII::permuteUnique(std::vector<int>& nums) {
        std::unordered_map<int, int> Map;
        for(auto n : nums) {
            ++Map[n];
        }
        std::vector<int> tmp;
        std::vector<std::vector<int>> res;
        genPermute(Map, nums.size(), tmp, res);
        return res;
}

void LeetCode::_0047_PermutationsII::genPermute(std::unordered_map<int, int>& Map, int N, 
                    std::vector<int>& tmp,
                    std::vector<std::vector<int>>& res) {
    if(N == 0) {
        res.push_back(tmp);
        return;
    }
    
    for(auto& m : Map) {
        if(m.second > 0) {
            m.second--;
            tmp.push_back(m.first);
            genPermute(Map, N - 1, tmp, res);
            tmp.pop_back();
            m.second++;
        }
    }
}
/*
Better solution
vector<vector<int>> permuteUnique(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    gen(nums, 0, nums.size() - 1, res);
    return res;
}
void gen(std::vector<int> nums, int start, int end, std::vector<std::vector<int>>& res) {
    if(start == end) {
        res.push_back(nums);
        return;
    }
    for(int i = start; i <= end; ++i) {
        if(i != start && nums[i] == nums[start]) { // remove duplicates
            continue;
        }
        std::swap(nums[i], nums[start]);
        gen(nums, start + 1, end, res);
    }
}
*/