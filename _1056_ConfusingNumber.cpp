#include "headers.hpp"

bool LeetCode::_1056_ConfusingNumber::confusingNumber(int N) {
    int n = N;
    int res = 0;
    while(n) {
        int d = n % 10;
        if(d == 2 || d == 3 || d == 4 || d == 5 || d == 7) {
            return false;
        }
        
        if(d == 0) {
            res = res * 10 + d;
        } else if(d == 1) {
            res = res * 10 + d;
        } else if (d == 6) {
            res = res * 10 + 9;
        } else if(d == 8) {
            res = res * 10 + 8;
        } else if(d == 9) {
            res = res * 10 + 6;
        }
        n /= 10;
    }
    return res != N;
}