#include "headers.hpp"

int LeetCode::_1031_MaximumSumOfTwoNonOverlappingSubarrays::maxSumTwoNoOverlap(std::vector<int>& A, int L, int M) {
    if(A.size() < L + M) {
        return 0;
    }
    
    std::vector<int> preSum(A);
    for(int i = 1; i < A.size(); ++i) {
        preSum[i] += preSum[i-1];
    }
    int res = preSum[L + M - 1];
    int maxL = preSum[L - 1];
    int maxM = preSum[M - 1];
    
    for(int i = L + M; i < A.size(); ++i) {
        maxL = std::max(maxL, preSum[i - M] - preSum[i - M - L]);
        maxM = std::max(maxM, preSum[i - L] - preSum[i - L - M]);
        res = std::max(res, std::max(
            maxL + preSum[i] - preSum[i - M],
            maxM + preSum[i] - preSum[i - L]));
    }
    
    return res;
}