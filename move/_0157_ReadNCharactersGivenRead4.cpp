#include "headers.hpp"
// !!! Copy from the solution
// Facebook
int LeetCode::_0157_ReadNCharactersGivenRead4::read(char* buf, int n) {
    int res = 0;
    for(int i = 0; i <= n / 4; ++i) {
        int t = read4(buf + res);
        if(t == 0) {
            break;
        }
        res += t;
    }
    return std::min(res, n);
}