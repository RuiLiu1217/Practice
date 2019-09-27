#include "headers.hpp"

// double LeetCode::_0004_MedianOfTwoSortedArrays::findMedianOfSortedArrays(
//     std::vector<int>& nums1,
//     std::vector<int>& nums2) {
//         const int N1 = nums1.size();
//         const int N2 = nums2.size();
//         if(N1 > N2) {
//             return findMedianOfSortedArrays(nums2, nums1);
//         }

//         const int K = (N1 + N2 + 1) / 2; // Calculate the median index of two sorted arrays
//         int l = 0;
//         int r = N1;

//         while(l < r) {
//             const int M1 = l + (r - l) / 2; // Assume that we need M1 elements from the first array
//             const int M2 = K - M1; // Then we need K - M1 elements in the second array;

//             // If the M1_th number in nums1 is smaller than the previous number of 
//             // the selected M2-1_th number in nums2, it means we need more in nums1
//             if(nums1[M1] < nums2[M2 - 1]) { 
//                 l = M1 + 1; 
//             } else {
//                 r = M1; // else we select too many values in nums1, we should return back some
//             }
//         }

//         const int M1 = l;
//         const int M2 = K - 1;

//         const int C1 = std::max(M1 <= 0 ? INT_MIN : nums1[M1-1], M2 <= 0 ? INT_MIN : nums2[M2 - 1]);

//         if((N1 + N2) % 2 == 1) { // The total number of arrays is an odd number.
//             return C1;
//         }

//         const int C2 = std::min(M1 >= N1 ? INT_MAX : nums1[M1], M2 >= N2 ? INT_MAX : nums[M2]);
//         return (C1 + C2) * 0.5;

//     }