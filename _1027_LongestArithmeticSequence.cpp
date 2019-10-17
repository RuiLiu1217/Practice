#include "headers.hpp"

// Copy from the solution.
int LeetCode::_1027_LongestArithmeticSequence::longestArithSeqLength(std::vector<int>& A) {
    // 建立一个hash map，key 是 两个元素之间的差，value 也是一个hash map， 他的key是序列开始的index，他的value就是当前这个序列已经多长了。那么
    using Diff = int;
    using StartIndex = int;
    using Length = int;
    std::unordered_map<Diff, std::unordered_map<StartIndex, Length>> DP;
    int res = 2; // The least length of the series is 2;
    const int N = A.size();
    
    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j < N; ++j) {
            int diff = A[j] - A[i];
            DP[diff][j] = DP[diff].count(i) ? DP[diff][i] + 1 : 2;
            res = std::max(res, DP[diff][j]);
        }
    }
    return res;
}