#include "headers.hpp"

LeetCode::_0519_RandomFlipMatrix::_0519_RandomFlipMatrix(int n_rows, int n_cols) {
    M = n_rows;
    N = n_cols;
    len = M * N;
    index.resize(len);
    for(int i = 0; i < len; ++i) {
        index[i] = i;
    }
}
    
std::vector<int> LeetCode::_0519_RandomFlipMatrix::flip() {
    int r = rand() % len;
    --len;
    int v = index[r];
    std::swap(index[r], index[len]);
    int m = v / N;
    int n = v % N;
    return {m, n};
}

void LeetCode::_0519_RandomFlipMatrix::reset() {
    len = M * N;
    for(int i = 0; i < len; ++i) {
        index[i] = i;
    }
}