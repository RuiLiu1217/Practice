#include "headers.hpp"
#include <algorithm>

std::vector<int> LeetCode::_1238_CicularPermutationInBinaryRepresentation::circularPermutation(int n, int start) {
    std::vector<int> initialVal = grayVector(n);
    auto iter = std::find(initialVal.begin(), initialVal.end(), start);
    std::vector<int> res(iter, initialVal.end());
    for(auto it = initialVal.begin(); it != iter; ++it) {
        res.push_back(*it);
    }
    return res;
}

std::vector<int> LeetCode::_1238_CicularPermutationInBinaryRepresentation::grayVector(int n) {
    if(n == 1) {
        return {0, 1};
    }
    std::vector<int> parRes = grayVector(n-1);
    const int N = parRes.size();
    parRes.resize(N * 2);
        
    for(int i = N - 1; i >= 0; --i) {
        parRes[(2 * N - 1) - i] = parRes[i] | (1 << (n - 1));
    }
    return parRes;
}
