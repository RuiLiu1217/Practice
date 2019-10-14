#include "headers.hpp"
int LintCode::_1332_NumberOf1Bits::hammingWeight(unsigned int n) {
   
    int res = 0;
    while(n) {
        res += (n & 1);
        n >>= 1;
    }
    return res;
}