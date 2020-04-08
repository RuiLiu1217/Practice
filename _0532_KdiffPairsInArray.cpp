#include "headers.hpp"

int LeetCode::_0532_KdiffPairsInAnArray::findPairs(std::vector<int>& nums, int k) {
    if (k < 0) {
        return 0;
    }
    int res = 0;
    int numsSize = nums.size();
    std::unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i) {
        mp[nums[i]]++;
    }

    for (auto a : mp) {
        if (k == 0 && a.second > 1) {
                res++;
        }
        if (k > 0 && mp.count(a.first + k) > 0) {
            res++;
        }
    }
    return res;
}