#ifndef LEETCODE_RECURSIVEPROBLEMS_HPP
#define LEETCODE_RECURSIVEPROBLEMS_HPP
#include <vector>

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


/*
Tag: recursive
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the 
sequence of gray code. A gray code sequence must begin with 0.


Input: 2   Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

Example 2:
Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0. A gray code sequence of n has 
size = 2n, which for n = 0 the size is 20 = 1. Therefore, for n = 0 the gray code sequence is [0].
*/
class _0089_GrayCode{
public:
    std::vector<int> grayCode(int n);
};

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class _0096_UniqueBinarySearchTree {
private:
    std::vector<int> DP;
public:
    int numTrees(int n);
    int numTreesN(int n);
};



}
#endif