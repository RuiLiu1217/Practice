#include "headers.hpp"
#include <algorithm>
#include <unordered_map>

// 这道题是抄答案的，一下子蒙住了，没想到可以用DP来解。
int LeetCode::_0823_BinaryTreeWithFactors::numFactoredBinaryTrees(std::vector<int>& A) {
    constexpr long kMod = 1000000007;
    std::sort(A.begin(), A.end());
    
    std::unordered_map<int, long> DP;
    for(int i = 0; i < A.size(); ++i) {
        DP[A[i]] = 1;
        for(int j = 0; j < i; ++j) {
            if(A[i] % A[j] == 0 && DP.count(A[i] / A[j])) {
                DP[A[i]] += (DP[A[j]] * DP[A[i] / A[j]]) % kMod;
            }
        }
    }
    long ans = 0;
    for(const auto& kv : DP) {
        ans += kv.second;
    }
    return ans % kMod;
}
