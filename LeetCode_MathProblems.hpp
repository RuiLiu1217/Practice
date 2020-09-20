#ifndef LEETCODE_MATHPROBLEMS_HPP
#define LEETCODE_MATHPROBLEMS_HPP
#include <string>
#include <vector>
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


/*
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
*/
class _0171_ExcellSheetColumnNumber {
public:
    int titleToNumber(std::string s);
};

/*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.
*/
class _0172_FactorialTrailingZeroes {
public:
    int trailingZeroes(int n);
};

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"
*/
class _0168_ExcelSheetColumnTitle {
public:
    std::string convertToTitle(int n);
};



/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive 
integer, replace the number by the sum of the squares of its digits, and repeat the 
process until the number equals 1 (where it will stay), or it loops endlessly in a cycle 
which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/
class _0202_HappyNumber {
private:
    int gat(int n);
public:
    bool isHappy(int n);
};



/*
Count the number of prime numbers less than a non-negative number, n.
Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
class _0204_CountPrimes {
public:
    int countPrimes(int n);
};

/*
Find the total area covered by two rectilinear rectangles 
in a 2D plane. Each rectangle is defined by its bottom left 
corner and top right corner as shown in the figure.
*/
class _0223_RectangleArea {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);
};



/*
Given an integer, write a function to determine if it is a power of two.

Input: 1
Output: true 
Explanation: 20 = 1

Input: 16
Output: true
Explanation: 24 = 16

Input: 218
Output: false
*/
class _0231_PowerOfTwo {
public:
    bool isPowerOfTwo(int n);
};


/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:

Input: 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: 8
Output: true
Explanation: 8 = 2 × 2 × 2
Example 3:

Input: 14
Output: false 
Explanation: 14 is not ugly since it includes another prime factor 7.
Note:

1 is typically treated as an ugly number.
Input is within the 32-bit signed integer range: [−231,  231 − 1].
*/
class _0263_UglyNumber {
public:
    bool isUgly(int num);
};


/*
Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) 
such that the denominator is less-than-or-equal-to n. The fractions can be in any order.

Input: n = 2
Output: ["1/2"]
Explanation: "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.

Input: n = 3
Output: ["1/2","1/3","2/3"]

Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]
Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".

Input: n = 1
Output: []

Constraints:

1 <= n <= 100
*/
class _1447_SimplifiedFractions {
public:
    std::vector<std::string> simplifiedFractions(int n);
};

}
#endif