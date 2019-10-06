#include "headers.hpp"

std::vector<int> LeetCode::_0350_IntersectionOfTwoArraysII::intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    if(nums2.size() > nums1.size()) {
        return intersect(nums2, nums1);
    }
    
    std::unordered_map<int, int> Map;
    for(auto n : nums1) {
        ++Map[n];
    }
    
    std::vector<int> res;
    for(auto n : nums2) {
        if(Map.find(n) != Map.end() && Map[n] != 0) {
            --Map[n];
            res.push_back(n);
        }
    }
    return res;
}