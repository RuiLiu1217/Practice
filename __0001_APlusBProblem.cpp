#include "headers.hpp"

int LintCode::_0001_APlusBProblem::aplusb(int a, int b) {
    int carry = 0;
    int res = 0;
    for(int i = 0; i < 32; ++i) {
        int t1 = a & 1;
        int t2 = b & 1;
        int tail = (t1 ^ t2 ^ carry);
        if((t1 == 1 && t2 == 1) || 
            (t1 == 1 && carry == 1) ||
            (t2 == 1 && carry == 1)) {
                carry = 1;
            } else {
                carry = 0;
            }
        res |= (tail << i);
        a >>= 1;
        b >>= 1;
    }
    return res;
}