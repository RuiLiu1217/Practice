#include "headers.hpp"

bool LeetCode::_0263_UglyNumber::isUgly(int num) {
    if(num == 0) {
        return false;
    }
    while(!num % 2) {
        num /= 2;
    }
    while(!num%3) {
        num /= 3;
    }
    while(!num%5) {
        num /=5;
    }
    return num == 1;
}