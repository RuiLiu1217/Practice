#include "headers.hpp"
#include <algorithm>

int LeetCode::_0164_MaximumGap::maximumGap(std::vector<int>& nums) {
    const int n = nums.size();
    // Find max and min value
    const auto maxmin = std::minmax_element(begin(nums), end(nums));
    const int range = *maxmin.second - *maxmin.first;
    // bucket size = (max - min) / n + 1
    const int bucketSize = range / n + 1;
    // number of buckets
    const int numBucket = range / bucketSize + 1;
    
    std::vector<int> minBucket(numBucket, INT_MAX);
    std::vector<int> maxBucket(numBucket, INT_MIN);
    for(auto num : nums) {
        int index = (num - *maxmin.first) / bucketSize;
        minBucket[index] = std::min(minBucket[index], num);
        maxBucket[index] = std::max(maxBucket[index], num);
    }
    int res = 0;
    int pre = 0;
    for(int i = 1; i < numBucket; ++i) {
        if(minBucket[i] == INT_MAX || maxBucket[i] == INT_MIN) {
            continue;
        }
        
        res = std::max(res, minBucket[i] - maxBucket[pre]);
        pre = i;
    }
    return res;
}