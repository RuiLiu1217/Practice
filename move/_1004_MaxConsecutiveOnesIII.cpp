#include "headers.hpp"

int LeetCode::_1004_MaxConsecutiveOnesIII::longestOnes(std::vector<int>& A, int K) {
    const int N = A.size();
    int front = 0;
    int back = 0;
    int availableK = K;
    int length = INT_MIN;
    while(front < N) {
        if(A[front] == 0) {
            --availableK;
        }
        if(availableK < 0) {
            length = std::max(length, front - back);
            while(back <= front && availableK < 0) {
                if(A[back] == 0) {
                    ++availableK;
                }
                ++back;
            }
        }
        ++front;
    }
    return std::max(length, front - back);
}