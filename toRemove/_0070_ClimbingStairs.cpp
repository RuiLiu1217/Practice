#include "headers.hpp"

int LeetCode::_0070_ClimbingStairs::climbStairs(int n) {
    if(n < 3) {
        return n;
    }
    int f1 = 1;
    int f2 = 2;
    int f;
    for(int i = 3; i <= n; ++i) {
        f = f1 + f2;

        f1 = f2;
        f2 = f;
    }
    return f;
}