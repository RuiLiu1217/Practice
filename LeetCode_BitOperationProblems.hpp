#ifndef LEETCODE_BITOPERATIONPROBLEMS_HPP
#define LEETCODE_BITOPERATIONPROBLEMS_HPP

#include <vector>
namespace LC {
    /*
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



    /*
    Given a non-empty array of integers, every element appears three times except for one, which appears 
    exactly once. Find that single one.

    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

    Example 1:

    Input: [2,2,3,2]
    Output: 3
    Example 2:

    Input: [0,1,0,1,0,1,99]
    Output: 99
    */
    class _0137_SingleNumberII {
    public:
        int singleNumber(std::vector<int>& nums);
        int singleNumberV1(std::vector<int>& nums);
        int singleNumberV2(std::vector<int>& nums);
        int singleNumberV3(std::vector<int>& nums);
    };

}
#endif