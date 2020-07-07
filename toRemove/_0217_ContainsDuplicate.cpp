#include "headers.hpp"
// Tag: hash
bool LeetCode::_0217_ContainsDuplicate::containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> se;
    for(auto n : nums) {
        if(se.find(n) != se.end()) {
            return true;
        }
        se.insert(n);
    }
    return false;
}