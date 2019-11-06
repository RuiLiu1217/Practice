#include "headers.hpp"

// https://leetcode.com/problems/range-sum-query-mutable/solution/
// https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/
// https://leetcode.com/problems/range-sum-query-mutable/discuss/75753/Java-using-Binary-Indexed-Tree-with-clear-explanation

LeetCode::_0307_RangeSumQuery_Mutable::_0307_RangeSumQuery_Mutable(std::vector<int>& nums) {
    arrayLength = nums.size();
    data.resize(nums.size()*2);
    std::copy(nums.begin(), nums.end(), data.begin() + arrayLength);
    
    for(int idx = arrayLength - 1; idx >= 1; --idx) {
        data[idx] = (data[idx * 2] + data[idx * 2 + 1]); 
    }
}

    
void LeetCode::_0307_RangeSumQuery_Mutable::update(int i, int val) {
    i = i + arrayLength;
    data[i] = val;
    while(i > 1) {
        i >>= 1;
        data[i] = (data[i * 2] + data[i * 2 + 1]);   
    }        
}


int LeetCode::_0307_RangeSumQuery_Mutable::sumRange(int i, int j) {
    j = j + 1;
    i = i + arrayLength;
    j = j + arrayLength;
    int sum = 0;
    while(i < j) {
        if(i % 2) {
            sum += data[i];
            i = i + 1;
        }
        if(j % 2) {
            j = j - 1;
            sum += data[j];
        }
        i >>= 1;
        j >>= 1;
    }
    return sum;
}
