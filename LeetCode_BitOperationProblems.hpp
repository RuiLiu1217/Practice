#ifndef LEETCODE_BITOPERATIONPROBLEMS_HPP
#define LEETCODE_BITOPERATIONPROBLEMS_HPP

#include <vector>
namespace LC {
    /*
    Tag: Bit operation
    Given a non-empty array of integers, every element appears twice except for one. 
    Find that single one.
    Your algorithm should have a linear runtime complexity. Could you implement it 
    without using extra memory?

    Input: [2,2,1]
    Output: 1

    Input: [4,1,2,1,2]
    Output: 4
    */
    class _0136_SingleNumber {
    public:
        int singleNumber(std::vector<int>& nums);
    };

}
#endif