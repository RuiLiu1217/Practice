#include "headers.hpp"
std::vector<std::vector<int>> LeetCode::_0046_Permutations::permute(std::vector<int> &nums)
{
    std::vector<std::vector<int>> result;
    permuteRecursive(nums, 0, result);
    return result;
}

void LeetCode::_0046_Permutations::permuteRecursive(std::vector<int> &nums, int begin, std::vector<std::vector<int>> &result)
{
    if (begin == nums.size() - 1) {
        result.push_back(nums);
        return;
    }

    for (int i = begin; i < nums.size(); ++i) {
        std::swap(nums[begin], nums[i]);
        permuteRecursive(nums, begin + 1, result);
        std::swap(nums[begin], nums[i]);
    }
}