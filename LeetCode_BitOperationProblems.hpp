#ifndef LEETCODE_BITOPERATIONPROBLEMS_HPP
#define LEETCODE_BITOPERATIONPROBLEMS_HPP
#include <cstdint>
#include <vector>
#include <string>
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


    /*
    Calculate the sum of two integers a and b, but you 
    are not allowed to use the operator + and -.

    Example 1:
        Input: a = 1, b = 2
        Output: 3
    Example 2:
        Input: a = -2, b = 3
        Output: 1
    */
    class _0371_SumOfTwoIntegers {
    public:
        int getSum(int a, int b);
    };


    /*
    A binary watch has 4 LEDs on the top which represent the hours (0-11), 
    and the 6 LEDs on the bottom represent the minutes (0-59).

    Each LED represents a zero or one, with the least significant bit on the right.

    For example, the above binary watch reads "3:25". Given a non-negative integer 
    n which represents the number of LEDs that are currently on, return all possible 
    times the watch could represent.

    Example:
        Input: n = 1
        Return: ["1:00", "2:00", "4:00", "8:00", "0:01", 
                "0:02", "0:04", "0:08", "0:16", "0:32"]

    Note:
        The order of output does not matter.
        The hour must not contain a leading zero, for example "01:00"
        is not valid, it should be "1:00". The minute must be consist 
        of two digits and may contain a leading zero, for example 
        "10:2" is not valid, it should be "10:02".

    Solution: 
        Thinking about it in the forward way is difficult, it is better 
        to think about it in an inverse way:
        There are total 12 * 60 combinations, why not enum them one by one 
        and pick up all satisfied items:
    */
    class _0401_BinaryWatch {
    public:
        std::vector<std::string> readBinaryWatch(int num);
        std::vector<std::string> readBinaryWatch_Solution2(int num);
    };



    /*
    Given an integer, write an algorithm to convert it to hexadecimal. For 
    negative integer, two’s complement method is used.
    All letters in hexadecimal (a-f) must be in lowercase.
    The hexadecimal string must not contain extra leading 0s. If the number is 
    zero, it is represented by a single zero character '0'; otherwise, the first 
    character in the hexadecimal string will not be the zero character.
    The given number is guaranteed to fit within the range of a 32-bit signed 
    integer.
    You must not use any method provided by the library which converts/formats 
    the number to hex directly.
    Input:  26         Output:  "1a"
    Input:  -1         Output:  "ffffffff"
    */
    class _0405_ConvertANumberToHexadecimal {
    public:
        std::string toHex(int num);
    };

    /* 
    The Hamming distance between two integers is the number of positions 
        at which the corresponding bits are different. Given two integers x and 
        y, calculate the Hamming distance.
        
        Note:
        0 ≤ x, y < 231.
        Example:
        Input: x = 1, y = 4               :            Output: 2
        Explanation:
        1   (0 0 0 1)
        4   (0 1 0 0)
               ↑   ↑
        The above arrows point to positions where the corresponding bits are different.
    */
    class _0461_HammingDistance {
    public:
        int hammingDistance(int x, int y);
    };

    /* The Hamming distance between two integers is the number of positions at 
    which the corresponding bits are different. Now your job is to find the total 
    Hamming distance between all pairs of the given numbers.

    Input: 4, 14, 2
    Output: 6

    Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
    showing the four bits relevant in this case). So the answer will be:
    HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
    Note:
    Elements of the given array are in the range of 0 to 10^9
    Length of the array will not exceed 10^4.
    */
    class _0477_TotalHammingDistance {
    public:
        int totalHammingDistance(std::vector<int>& nums);
    };


    /*
    Every non-negative integer N has a binary representation.  For example, 
    5 can be represented as "101" in binary, 11 as "1011" in binary, and so 
    on. Note that except for N = 0, there are no leading zeroes in any binary 
    representation.
    The complement of a binary representation is the number in binary you get 
    when changing every 1 to a 0 and 0 to a 1. For example, the complement of 
    "101" in binary is "010" in binary.

    For a given number N in base-10, return the complement of it's binary 
    representation as a base-10 integer.

    Input: 5
    Output: 2
    Explanation: 5 is "101" in binary, with complement "010" in binary, which 
    is 2 in base-10.

    Input: 7
    Output: 0
    Explanation: 7 is "111" in binary, with complement "000" in binary, which 
    is 0 in base-10.

    Input: 10
    Output: 5
    Explanation: 10 is "1010" in binary, with complement "0101" in binary, which 
    is 5 in base-10.

    Note:
    0 <= N < 10^9
    This question is the same as 476: https://leetcode.com/problems/number-complement/
    */
    class _1009_CompletementOfBase10Integer {
    public:
        int bitwiseComplement(int N);
    };

    /*
        Given an integer n and an integer start.
        Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.
        Return the bitwise XOR of all elements of nums.

        Input: n = 5, start = 0             :          Output: 8
        Explanation: Array nums is equal to [0, 2, 4, 6, 8] where (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8.
        Where "^" corresponds to bitwise XOR operator.

        Input: n = 4, start = 3             :          Output: 8
        Explanation: Array nums is equal to [3, 5, 7, 9] where (3 ^ 5 ^ 7 ^ 9) = 8.

        Input: n = 1, start = 7             :          Output: 7
        Input: n = 10, start = 5            :          Output: 2
        
        Constraints:

        1 <= n <= 1000
        0 <= start <= 1000
        n == nums.length
    */
    class _1486_XOROperationInAnArray {
    public:
        int xorOperation(int x, int start) {
            int ans = 0;
            for(int i = 0; i < x; ++i) {
                ans ^= (start + i * 2);
            }
            return ans;
        }
    };

}
#endif