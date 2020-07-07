#include "headers.hpp"
#include <unordered_set>
// Tag: hash, array operation
// TODO: easy problem but suddenly forget how to solve it.
bool LeetCode::_0219_ContainsDuplicateII::containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_set<int> s;
    if(k <= 0) {
        return false;
    }
    if(k >= nums.size() - 1) {
        k = nums.size() - 1;
    }

    for(int i = 0; i < nums.size(); ++i) {
        if(i > k) {
            s.erase(nums[i - k - 1]);
        }
        if(s.find(nums[i]) != s.end()) {
            return true;
        }
        s.insert(nums[i]);
    }
    return false;
}