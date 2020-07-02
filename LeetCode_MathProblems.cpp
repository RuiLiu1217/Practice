#include "LeetCode_MathProblems.hpp"
#include <climits>
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

/*
Google
*/
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