#include "headers.hpp"

int LeetCode::_0974_SubarraySumsDivisibleByK::subarrayDivByK(std::vector<int>& A, int K) {
    std::vector<int> count(K); // 所得余数的个数;
    count[0] = 1;
    int prefix = 0, res = 0;
    for (int a : A) {
        prefix = (prefix + a % K + K) % K; // + (a%K + K) 为了避免负数
        res += count[prefix]++;
    }
    return res;
}