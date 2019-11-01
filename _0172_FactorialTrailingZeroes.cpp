#include "headers.hpp"

int LeetCode::_0172_FactorialTrailingZeroes::trailingZeroes(int n) {
    int rc = 0;
    while (n = n / 5) rc += n; 
    return rc;
    /*
    int maxSmall5 = n;
    while (maxSmall5 % 5)
    {
        maxSmall5--;
    }
    int zeroNum = 0;
    int idxNum = maxSmall5;
    while (maxSmall5)
    {
        idxNum = maxSmall5;
        while (!(idxNum % 5))
        {
            zeroNum++;
            idxNum /= 5;
        }
        maxSmall5 -= 5;
    }
    return zeroNum;
    */

}