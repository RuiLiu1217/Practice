#include "headers.hpp"

int LeetCode::_0598_RangeAdditionII::maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
    int M = m;
    int N = n;
    for(int opIdx = 0; opIdx < ops.size(); ++opIdx) {
        M = (ops[opIdx][0] > M)? M : ops[opIdx][0];
        N = (ops[opIdx][1] > N)? N : ops[opIdx][1];
    }
    return M * N;
}