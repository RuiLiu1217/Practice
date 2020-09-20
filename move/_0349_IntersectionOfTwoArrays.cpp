#include "headers.hpp"
#include <unordered_set>
#include <unordered_map>

// Facebook

std::vector<int> LeetCode::_0349_IntersectionOfTwoArrays::intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set(begin(nums1),end(nums1));
    std::vector<int> res;
    for(int n : nums2) {
        if(set.count(n)) {
            res.push_back(n);
            set.erase(n);
        }
    }
    return res;
}