#include "headers.hpp"

int LeetCode::_1009_CompletementOfBase10Integer::bitwiseComplement(int N) {
    int v = 1;
    while(v < N) {
        v = (v << 1) + 1;
    }
    return v - N;
}