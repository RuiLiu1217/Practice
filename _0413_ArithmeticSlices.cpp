#include "headers.hpp"

int LeetCode::_0413_ArighmeticSlices::numberOfArithmeticSlices(std::vector<int>& A) {
    if(A.size() < 3) {
        return 0;
    }
    std::vector<int> diff(A.size(), INT_MAX);
    int cache = A[1] - A[0];
    int count = 0;
    int sum = 0;
    for(int i = 0; i < A.size() - 1; ++i) {
        if(A[i+1] - A[i] == cache) {
            count++;
        } else {
            if(count >= 2) {
                sum += numberOfSubArith(count + 1);
            }
            count = 1;
            cache = A[i+1] - A[i];
        }
    }
    if(count >= 2) {
        sum += numberOfSubArith(count + 1);
    }
    return sum;
}

int LeetCode::_0413_ArighmeticSlices::numberOfSubArith(int N) {
    return N * (N - 3) / 2 + 1;
}