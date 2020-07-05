#include "LeetCode_ArrayProblems.hpp"
#include <algorithm>
#include <unordered_map>
#include <climits>
std::vector<int> LC::_0001_TwoSum::twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); ++i)
    {
        int n = nums[i];
        if(map.find(target - n) != map.end()) {
            return {map[target - n], i};
        }
        map[n] = i;
    }
    return {};
}

// ReviewLater
// Company: Google
// Type: Array
// 一道二分搜索法的极致变形
double LC::_0004_MedianOfTwoSortedArrays::findMedianOfSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    const int N1 = nums1.size();
    const int N2 = nums2.size();
    if(N1 > N2) {
        return findMedianOfSortedArrays(nums2, nums1); // 总是考虑 第一个数组相对来说较短的情况
    }

    const int K = (N1 + N2 + 1) / 2; // Calculate the median index of two sorted arrays 所谓中位数所在的index
    int l = 0;
    int r = N1;

    while(l < r) {
        const int M1 = l + (r - l) / 2; // Assume that we need M1 elements from the first array // 假设需要M1个元素从nums1中，
        const int M2 = K - M1; // Then we need K - M1 elements in the second array; // 因此需要在nums2中找  K - M1 个元素

        // 如果在nums1中的第M1个数比在nums2中的M2-1个数还要小，说明我们还要从nums1中拿更多的数
        // 否则这意味着我们在nums1中拿太多的数字了，需要返回一部分。
        if(nums1[M1] < nums2[M2 - 1]) { 
            l = M1 + 1; 
        } else {
            r = M1; 
        }
    }

    const int M1 = l;
    const int M2 = K - 1;

    const int C1 = std::max(M1 <= 0 ? INT_MIN : nums1[M1-1], M2 <= 0 ? INT_MIN : nums2[M2 - 1]);

    if((N1 + N2) % 2 == 1) { // The total number of arrays is an odd number.
        return C1;
    }

    const int C2 = std::min(M1 >= N1 ? INT_MAX : nums1[M1], M2 >= N2 ? INT_MAX : nums2[M2]);
    return (C1 + C2) * 0.5;
}


/*
Google
Tag: Array Binary search
*/
std::vector<std::vector<int>> LC::_0015_3Sum::threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    if(nums.empty() || nums.size() < 3 || nums.front() > 0 || nums.back() < 0) {
        return {};
    }

    for(int k = 0; k < nums.size() - 2; ++k) {
        if(nums[k] > 0) {
            break;
        }
        if(k > 0 && nums[k] == nums[k-1]) {
            continue;
        }

        int i = k + 1;
        int j = nums.size() - 1;
        int target = -nums[k];
        while(i < j) {
            if(nums[i] + nums[j] == target) {
                res.push_back({nums[k], nums[i], nums[j]});
                while(i < j && nums[i] == nums[i+1]) {
                    ++i;
                }
                while(i < j && nums[j] == nums[j-1]) {
                    --j;
                }
                ++i;
                --j;
            } else if(nums[i] + nums[j] > target) {
                --j;
            } else {
                ++i;
            }
        }
    }
    return res;
}