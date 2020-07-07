#include "headers.hpp"

// 这是一道数学题，需要仔细分析到底这道题在考什么
// 1337 只有两个因子: 7 和 191, 
// phi of them is itself - 1, 这时候可以用欧拉定理
// https://en.wikipedia.org/wiki/Euler's_theorem, 
// it's just Fermat's little theorem if the mod n is prime.
// see how 1140 is calculated out:
// phi(1337) = phi(7) * phi(191) = 6 * 190 = 1140

// 这道题一下子蒙住了，完全灭有想法，实际上这道题是之前求一个大数的大幂的扩展。

// 这道题题让我们求一个数的很大的次方对1337取余的值，
// 那么这道题和之前那道Pow(x, n)的解法很类似，我们都得
// 对半缩小，不同的是后面都要加上对1337取余
static int myPow(int x, int n) {
    if (n == 0) {
        return 1;
    }
    if(n == 1) {
        return x % 1337;
    }
    return myPow(x % 1337, n / 2) * myPow(x % 1337, n - n / 2) % 1337;
}


int LeetCode::_0372_SuperPow::superPow(int a, std::vector<int>& b) {
    long long res = 1;
    for(int i = 0; i < b.size(); ++i) {
        res = myPow(res, 10) * myPow(a, b[i]) % 1337;
    }
    return res;
}
