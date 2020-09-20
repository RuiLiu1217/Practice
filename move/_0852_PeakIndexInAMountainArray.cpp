#include "headers.hpp"

int LeetCode::_0852_PeakIndexInAMountainArray::peakIndexInMountainArray(std::vector<int>& A) {
    int i = -1;
    for(i = 0; i < A.size() - 2; ++i) {
        if(A[i+1] < A[i] && A[i] > A[i-1]) {
            return i;
        }
    }
    return i;
}