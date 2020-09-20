#include "headers.hpp"
#include <unordered_map>
int LeetCode::_1074_NumberOfSubmatricesThatSumToTarget::numSubmatrixSumTarget(std::vector<std::vector<int>>& A, int target) {
    const int M = A.size();
    const int N = A[0].size();
    for(int i = 0; i < M; ++i) {
        for(int j = 1; j < N; ++j) {
            A[i][j] += A[i][j-1];            
        }
    }

    int res = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = i; j < N; ++j) {
            std::unordered_map<int, int> counter; // LeetCode 560
            counter[0] = 1;
            int cur = 0;
            for(int k = 0; k < M; ++k) {
                cur += A[k][j] - (i > 0 ? A[k][i-1] : 0);
                res += counter[cur - target];
                ++counter[cur];
            }
        }
    }
    return res;
}
