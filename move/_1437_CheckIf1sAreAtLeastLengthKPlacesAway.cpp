#include "headers.hpp"

bool LeetCode::_1437_CheckIf1sAreAtLeastLengthKPlacesAway::kLengthApart(std::vector<int>& nums, int k) {
    if(nums.size() == 0) {
        return true;
    }
    int p = 0;
    int cur = p;
    int dis = k + 1;
    while(p < nums.size()) {
        if(nums[p] == 1) {
            if(dis < k) {
                return false;
            } else {
                dis = 0;
            }
        } else {
            ++dis;
        }
        ++p;
    }
    return true;
}