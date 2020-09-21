#ifndef LEETCODE_BITOPERATIONPROBLEMS_HPP
#define LEETCODE_BITOPERATIONPROBLEMS_HPP
#include <cstdint>
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


    
    /*
    Tag: bit operation
    Reverse bits of a given 32 bits unsigned integer.
    Example 1:
    Input: 00000010100101000001111010011100
    Output : 00111001011110000010100101000000
    Explanation : The input binary string 00000010100101000001111010011100 
    represents the unsigned integer 43261596, so return 964176192 which 
    its binary representation is 00111001011110000010100101000000.
    Example 2 :
    Input : 11111111111111111111111111111101
    Output : 10111111111111111111111111111111
    Explanation : The input binary string 11111111111111111111111111111101 
    represents the unsigned integer 4294967293, so return 3221225471 which 
    its binary representation is 10101111110010110010011101101001.

    Note :
    Note that in some languages such as Java, there is no unsigned integer 
    type. In this case, both input and output will be given as signed integer 
    type and should not affect your implementation, as the internal binary 
    representation of the integer is the same whether it is signed or unsigned.
    In Java, the compiler represents the signed integers using 2's complement 
    notation. Therefore, in Example 2 above the input represents the signed 
    integer -3 and the output represents the signed integer -1073741825.
    */
    class _0190_ReverseBits {
    public:
        uint32_t reverseBits(uint32_t n);
    };


    /*
        Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).
    */
    class _0191_NumberOf1Bits {
    public:
        int hammingWeight(uint32_t n);
    };



    /*
    TODO: n & (n-1) trick
    Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

    Input: [5,7]
    Output: 4
    Example 2:

    Input: [0,1]
    Output: 0
    */
    class _0201_BitwiseANDofNumbersRange {
    public:
        int rangeBitwiseAnd(int m, int n);
    };



    /*
        Given an array of numbers nums, in which exactly two elements 
        appear only once and all the other elements appear exactly twice.
        Find the two elements that appear only once.
        
        Example:
            Input:  [1,2,1,3,2,5]
            Output: [3,5]
        Note:
        The order of the result is not important. So in the above example, 
        [5, 3] is also correct. Your algorithm should run in linear runtime 
        complexity. Could you implement it using only constant space 
        complexity?
    */
    class _0260_SingleNumberII {
    public:
        std::vector<int> singleNumber(const std::vector<int> &nums);
    };



}
#endif