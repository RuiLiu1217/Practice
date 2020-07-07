#include "headers.hpp"
// 完全抄答案的，没有任何想法，也想不通为啥
std::vector<int> LeetCode::_0442_FindAllDuplicatesInAnArray::findDuplicates(std::vector<int>& nums) {
    std::vector<int> res;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] != nums[nums[i] - 1]) {
            std::swap(nums[i], nums[nums[i] - 1]);
            --i;
        }
    }

    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] != i + 1) {
            res.push_back(nums[i]);
        }
    }
    return res;
}