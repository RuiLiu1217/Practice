#include "headers.hpp"
// Totally copy from solution
static int count(std::vector<int>& A, int bound) {
    int res = 0;
    int cur = 0;
    for(int x : A) {
        if(x <= bound) {
            ++cur;
        } else {
            cur = 0;
        }
        res += cur;
    }
    return res;
}

int LeetCode::_0795_NumberofSubarraysWithBoundedMaximum::numSubarrayBoundedMax(std::vector<int>& A, int L, int R) {
    return count(A, R) - count(A, L - 1);
}