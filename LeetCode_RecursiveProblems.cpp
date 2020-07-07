#include "LeetCode_RecursiveProblems.hpp"

double LC::_0050_PowXN::myPow(double x, int n) {
    if(n == 0) {
        return 1;
    }
    if(n == 1) {
        return x;
    }
    if(n == -1) {
        return 1.0 / x;
    }
    if(n % 2 == 0) {
        return myPow(x * x, n / 2);
    } else {
        if(n > 0) {
            return myPow(x * x, n / 2) * x;
        } else {
            return myPow(x * x, n / 2) / x;
        }
    }
}