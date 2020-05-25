#include "headers.hpp"

// 这是一道典型的Greedy 算法题目。
// 把问题拆分成 (A[i] + i) + (A[j] - j); 保持寻找 使得 A[i] + i 更大的i与当前 A[j] - j 相加 得到最大值
int LeetCode::_1014_BestSightseeingPair::maxScoreSightseeingPair(std::vector<int>& A) {
    int prei = 0;
    int res = 0;
    for(int j = 1; j < A.size(); ++j) {
        res = std::max(res, A[j] - j + prei + A[prei]);
        if(A[j] + j > A[prei] + prei) {
            prei = j;
        }
    }
    return res;
}