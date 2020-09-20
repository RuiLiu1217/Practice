#include "headers.hpp"
// !!! Copy from the solution !!!
// Binary Search

// Facebook

bool isBadVersion(int ver) {
    return false;
}

int LeetCode::_0278_FirstBadVersion::firstBadVersion(int n) {
    int lower = 1, upper = n, mid;
    while(lower < upper) {
        mid = lower + (upper - lower) / 2;  // Use this to calculate the mid version to avoid the overflow of (small+large) / 2 
        if(!isBadVersion(mid)) lower = mid + 1;   /* Only one call to API */
        else upper = mid;
    }
    return lower;   /* Because there will alway be a bad version, return lower here */
}