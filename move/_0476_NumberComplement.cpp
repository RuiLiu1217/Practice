#include "headers.hpp"

int LeetCode::_0476_NumberComplement::findComplement(int num) {
    int n = num;
    int bits = 0;
    int v = 0;
    while(n) {
        v |= (1<<bits);
        n >>= 1;
        ++bits;
    }
    return num ^ v;
}