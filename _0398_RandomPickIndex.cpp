#include "headers.hpp"

// Facebook

LeetCode::_0398_RandomPickIndex::_0398_RandomPickIndex(std::vector<int>& nums) {
    for(int i = 0; i < nums.size(); ++i) {
        map[nums[i]].push_back(i);
    }
}

int LeetCode::_0398_RandomPickIndex::pick(int target) {
    std::vector<int>& range = map[target];
    int r = std::rand() % range.size();
    return range[r];
}