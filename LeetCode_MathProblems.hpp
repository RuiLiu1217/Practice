#ifndef LEETCODE_MATHPROBLEMS_HPP
#define LEETCODE_MATHPROBLEMS_HPP
namespace LC {
/*
Tag: stack, numeric
Given a 32-bit signed integer, reverse digits of an integer.

Input: 123       :       Output: 321
Input: -123      :       Output: -321
Input: 120       :       Output: 21
*/
class _0007_ReverseInteger {
public:
    int reverse(int x);
};

/* Tag: string, palindrome
Determine whether an integer is a palindrome. An integer is a 
palindrome when it reads the same backward as forward.

Input: 121             Output: true
Input: -121            Output: false
Explanation: From left to right, it reads -121. From right to left, 
it becomes 121-. Therefore it is not a palindrome.

Input: 10              Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/
class _0009_PalindromeNumber {
public:
    bool isPalindrome(int x);
};


//! TODO: need review it again
/*
Tag: Binary search, math
Given two integers dividend and divisor, divide two integers without 
using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.

Input: dividend = 10, divisor = 3
Output: 3

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store 
integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. 
For the purpose of this problem, assume that your function returns 
2^31 − 1 when the division result overflows.
*/
class _0029_DivideTwoIntegers {
public:
    int divide(int dividend, int divisor);
};

}



#endif