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

}

#endif