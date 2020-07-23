#include "LeetCode_MathProblems.hpp"
#include <cmath>
#include <climits>
#include <cstdlib>
/*
Google
*/
int LC::_0007_ReverseInteger::reverse(int x) {
    long long res = 0; // Consider the overflow
    while(x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return (res < INT_MIN || res > INT_MAX) ? 0 : res; // The difficulty is the attention of overflow
}


// Google
bool LC::_0009_PalindromeNumber::isPalindrome(int x) {
   if(x < 0) {
        return false;
    }
    
    int t = x;
    long res = 0;
    while(t) {
        res = res * 10 + t % 10;
        t /= 10;
    }
    return res == x;
}



//! TODO: 
// Facebook
int LC::_0029_DivideTwoIntegers::divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    if(divisor == 1) {
        return dividend;
    }
    long dvd = std::labs(dividend); // LONG DATATYPE ABSOLUTE VALUE
    long dvs = std::labs(divisor);
    long ans = 0;
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    
    while (dvd >= dvs) {
        long temp = dvs, m = 1;
        while (temp << 1 <= dvd) {
            temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        ans += m;
    }
    return sign * ans;
}
