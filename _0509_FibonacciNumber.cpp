#include "headers.hpp"

int LeetCode::_0509_FibonacciNumber::fib(int N) {
    if (N == 0) {
        return 0;
    }
    if (N == 1) {
        return 1;
    }
    int A[2] = { 0, 1 };
    int ii = 2;
    int tmp = 0;
    while (ii <= N) {
        tmp = A[0] + A[1];
        A[0] = A[1];
        A[1] = tmp;
        ++ii;
    }
    return tmp;
}