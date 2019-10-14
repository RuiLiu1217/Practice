#include "headers.hpp"

int LintCode::_1511_MirrorReflection::mirrorReflection(int p, int q) {
    int g = gcd(p, q);
    int lcm = p * (q / g);
    int x = lcm / p;
    int y = lcm / q;
    if( y % 2) {
        if(x % 2) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 2;
    }
}

int LintCode::_1511_MirrorReflection::gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}