#include "headers.hpp"
/*
Google
*/

int LeetCode::_0007_ReverseInteger::reverse(int x) {
    long long res = 0; // Consider the overflow
    while(x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return (res < INT_MIN || res > INT_MAX) ? 0 : res; // The difficulty is the attention of overflow
}
