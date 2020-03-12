#include "headers.hpp

// Tag: Binary Search. 
// Camouflag as a DP, but actually it is a binary search

// Google
int LeetCode::_1011_CapacityToShipPackagesWithinDDays::shipWithinDays(std::vector<int>& weights, int D) {
    int left = 0;
    int right = 25000000;
    for (int w: weights)
        left = std::max(left, w);
    while(left < right) {
        int mid = left + (right - left) / 2;
        int need = 1;
        int cur = 0;
        for(int i = 0; i < weights.size() && need <= D; cur += weights[i++]) {
            if(cur + weights[i] > mid) {
                cur = 0;
                ++need;
            }
        }
        if(need > D) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}