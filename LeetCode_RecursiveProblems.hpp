#ifndef LEETCODE_RECURSIVEPROBLEMS_HPP
#define LEETCODE_RECURSIVEPROBLEMS_HPP
namespace LC {

/*
Tag: recursive
Note: integer data overflow if n < 0 --> -n but 
      if n is INT_MIN, then...
Implement pow(x, n), which calculates x raised to the power n (x^n).

Input: 2.00000, 10       :           Output: 1024.00000
Input: 2.10000, 3        :           Output: 9.26100
Input: 2.00000, -2       :           Output: 0.25000

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/
class _0050_PowXN {
public:
    double myPow(double x, int n);
};

}
#endif