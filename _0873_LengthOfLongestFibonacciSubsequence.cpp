#include "headers.hpp"
#include <unordered_map>
int LeetCode::_0873_LengthOfLongestFibonacciSubsequence::lenLongestFibSubseq(std::vector<int>& A) {
    std::unordered_map<int, int> m;
    int N = A.size();
    int res = 0;
    std::vector<std::vector<int>> DP(N, std::vector<int>(N, 0));
    for(int j = 0; j < N; ++j) {
        m[A[j]] = j;
        for(int i = 0; i < j; ++i) {
            int k = m.find(A[j] - A[i]) == m.end() ? -1 : m[A[j] - A[i]];
            DP[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? DP[k][i] + 1 : 2;
            res = std::max(res, DP[i][j]);
        }
    }
    return res;
}