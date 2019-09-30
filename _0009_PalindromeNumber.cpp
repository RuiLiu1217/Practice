#include "headers.hpp"

bool LeetCode::_0009_PalindromeNumber::isPalindrome(int x) {
    int org = x;
    if(x < 0) {
        return false;
    }

    std::queue<int> q;
    while(x) {
        int v = x % 10;
        q.push(v);
        x = x / 10;
    }
    int par = 0;
    while(!q.empty()) {
        par = par * 10 + q.front();
        q.pop();
    }
    return org == par;
}