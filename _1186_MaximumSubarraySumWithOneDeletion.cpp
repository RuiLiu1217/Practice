#include "headers.hpp"

/*
    1. This problem is kind a modified version vrom Kanade's algorithm.
    2. We calculate the maximum subarray sum forward and backward
    3. arr: [-2, -3, 4, -1, -2, 1, 5, -3]
        fw: [-2, -3, 4,  3,  1, 2, 7,  4]
        bw: [ 2,  4, 7,  3,  4, 6, 5, -3]
    We either add value for max subarray sum, or just ditch the value and
    reaccumulate, then we have overallMax = 7 from a subarray [4, -1, -2, 1, 5]
    And finally update answer as
         [-2,  -3,  4,  {3},  1,   2,   7,  4] 
         [ 2,   4,  7,   3,   4,  {6},  5, -3]
                         |         |
                         v         v
        from 0 ~ 3 max : 3         6 : from 5 ~ end
                          \       /
                            3 + 6 = 9 
          Combine we have 3 + 6 = 9  with central arr[4] removed.
    
    */
int LeetCode::_1186_MaximumSubarraySumWithOneDeletion::maximumSum(std::vector<int>& arr) {
    int res = 0;
    const int n = arr.size();

    int curMax = arr[0];
    int overallMax = arr[0];
    std::vector<int> forward(n);
    std::vector<int> backward(n);
    forward[0] = arr[0];
    for(int i = 1; i < n; ++i) {
        curMax = std::max(arr[i], curMax + arr[i]);
        overallMax = std::max(overallMax, curMax);
        forward[i] = curMax;
    }

    curMax = overallMax = backward[n-1] = arr[n-1];
    for(int i = n - 2; i >= 0; --i) {
        curMax = std::max(arr[i], curMax + arr[i]);
        overallMax = std::max(overallMax, curMax);
        backward[i] = curMax;
    }
    
    res = overallMax;
    for(int i = 1; i < n - 1; ++i) {
        res = std::max(res, forward[i-1] + backward[i+1]);
    }
    return res;
}