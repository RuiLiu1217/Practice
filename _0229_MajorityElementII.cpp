#include "headers.hpp"
#include <algorithm>
// Moore Vote Algorithm: 先设定两个备选值，然后每个备选值都有个计数，
// 从头到尾访问一下，如果跟备选值一样，就加一个计数，如果计数是0，则当前
// 这个数更新为新的计数，并开始计数为1，否则都减去一个计数;
std::vector<int> LeetCode::_0229_MajorityElementII::majorityElement(std::vector<int>& nums) {
    int maj1 = 0;
    int maj2 = 0;
    int count1 = 0;
    int count2 = 0;
    for(auto n : nums) {
        if(n == maj1) {
            ++count1;
        } else if(n == maj2) {
            ++count2;
        } else if(count1 == 0) {
            maj1 = n;
            count1 = 1;
        } else if(count2 == 0) {
            maj2 = n;
            count2 = 1;
        } else {
            --count1;
            --count2;
        }
    }
    
    count1 = 0;
    count2 = 0;
    for(auto n : nums) {
        if(n == maj1) {
            ++count1;
        } else if(n == maj2) {
            ++count2;
        }
    }
    
    std::vector<int> res;
    if(count1 > nums.size() / 3) {
        res.push_back(maj1);
    }
    if(count2 > nums.size() / 3) {
        res.push_back(maj2);
    }
    return res;
}