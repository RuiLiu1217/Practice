#include "headers.hpp"
#include <algorithm>
std::vector<int> LeetCode::_0321_CreateMaximumNumber::maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    std::vector<int> res;
    const int N1 = nums1.size();
    const int N2 = nums2.size();

    for(int k1 = 0; k1 <= k; ++k1) {
        int k2 = k - k1;
        if(k1 > N1 || k2 > N2) {
            continue;
        }
        res = std::max(res, maxNumber(maxNumber(nums1,k1), maxNumber(nums2,k2)));
    }
    return res;
}

std::vector<int> LeetCode::_0321_CreateMaximumNumber::maxNumber(const std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> ans;
    auto start1 = nums1.cbegin();
    auto start2 = nums2.cbegin();
    auto end1 = nums1.cend();
    auto end2 = nums2.cend();
    while(start1 != end1 || start2 != end2) {
        ans.push_back(
            std::lexicographical_compare(start1, end1, start2, end2)? *start2++:*start1++
        );
    }
    return ans;
}

std::vector<int> LeetCode::_0321_CreateMaximumNumber::maxNumber(const std::vector<int>& nums, int k) {
    if(k == 0) {
        return {};
    }
    std::vector<int> res;
    int canPop = nums.size() - k;
    for(const int num : nums) {
        while(!res.empty() && res.back() < num && canPop > 0) {
            res.pop_back();
            --canPop;
        }
        res.push_back(num);
    }
    res.resize(k);
    return res;   
}