#include "headers.hpp"
#include <algorithm>
#include <numeric>

/*
抄答案来的：
Because it's guaranteed that only one number will appear more than 25% times, 
that number will definitely appear at one of the three positions in the array: 
quarter, half, and three quarters. We see them as candidates, and then using 
binary search to check each of them.

Time complexity: O(logn)
Space complexity: O(1)
*/
int LeetCode::_1287_ElementAppearingMoreThan25PercentInSortedArray::findSpecialInteger(std::vector<int>& arr) {
    int sz = arr.size();
    std::vector<int> candidates = {arr[sz/4], arr[sz/2], arr[sz*3/4]};
    for (auto cand : candidates) {
        auto st = std::lower_bound(arr.begin(), arr.end(), cand);
        auto ed = std::upper_bound(arr.begin(), arr.end(), cand);
        if (4 * (std::distance(st, ed)) > sz)
            return cand;
    }
    return -1;
}