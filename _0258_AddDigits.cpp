#include "headers.hpp"

// 一个数各个位置的数相加得到一个新的数，
// 如此往复一直加到个位数，快速计算这个个
// 位数的办法有个公式，如果这个数是0，就
// 直接返回0，否则将原先的数mod 9， 如果
// 能被 9 整除，则返回9， 否则返回这个余数

int LeetCode::_0258_AddDigits::addDigits(int num) {
    if(num == 0) {
        return 0;
    }
    int v = (num % 9);
    return v == 0 ? 9 : v;
}