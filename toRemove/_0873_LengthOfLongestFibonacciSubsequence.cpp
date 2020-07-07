#include "headers.hpp"
#include <unordered_map>

// 这道题可以想到是DP，可是比较难以想到要用二维DP
// DP[i][j] 表示以i个数和第j个数为斐波那契数列结尾的序列最长长度。
int LeetCode::_0873_LengthOfLongestFibonacciSubsequence::lenLongestFibSubseq(std::vector<int>& A) {
    std::unordered_map<int, int> m; // 数到其index的映射
    int N = A.size();
    int res = 0;
    std::vector<std::vector<int>> DP(N, std::vector<int>(N, 0));
    for(int j = 0; j < N; ++j) {
        m[A[j]] = j; 
        for(int i = 0; i < j; ++i) {
            // 当前序列以 ... A[i], A[j] 这样结尾，那么前一个数就是 A[j] - A[i]
            // 因此要求 A[j] - A[i] < A[i], 如果这个数在map中，那么 DP[i][j] = DP[m[A[j] - A[i]]][i] + 1;  --> ..., A[j] - A[i], A[i], A[j]
            int k = m.find(A[j] - A[i]) == m.end() ? -1 : m[A[j] - A[i]]; 
            DP[i][j] = (A[j] - A[i] < A[i] && k >= 0) ? DP[k][i] + 1 : 2;
            res = std::max(res, DP[i][j]);
        }
    }
    return res;
}