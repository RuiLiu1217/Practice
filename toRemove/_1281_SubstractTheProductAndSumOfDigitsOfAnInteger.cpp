#include "headers.hpp"

int LeetCode::_1281_SubstractTheProductAndSumOfDigitsOfAnInteger::subtractProductAndSum(int n) {
    int sum = 0;
    int prd = 1;
    while(n) {
        int d = n % 10;
        n /= 10;
        sum += d;
        prd *= d;
    }
    return prd - sum;
}