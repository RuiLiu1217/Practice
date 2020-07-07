#include "headers.hpp"
int LeetCode::_1131_MaximumOfAbsoluteValueExpression::maxAbsValExpr(
    std::vector<int>& arr1, std::vector<int>& arr2) {
    const int N = arr1.size();
    std::vector<std::vector<int>> cache(4, std::vector<int>(N));
    std::vector<int> minimum(4, INT_MAX);
    std::vector<int> maximum(4, INT_MIN);
    for(int i = 0; i < N; ++i) {
        cache[0][i] = arr1[i] + arr2[i] + i;
        cache[1][i] = arr1[i] - arr2[i] + i;
        cache[2][i] = -arr1[i] + arr2[i] + i;
        cache[3][i] = -arr1[i] - arr2[i] + i;
        
        for(int k = 0; k < 4; ++k) {
            minimum[k] = std::min(minimum[k], cache[k][i]);
            maximum[k] = std::max(maximum[k], cache[k][i]);
        }
    }
    int res = INT_MIN;
    for(int i = 0; i < 4; ++i) {
        res = std::max(maximum[i] - minimum[i], res);
    }
    return res;
}