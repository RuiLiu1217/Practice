#include "headers.hpp"
#include <algorithm>
std::vector<int> LeetCode::_0905_SortArrayByParity::sortArrayByParity(std::vector<int>& A) {
    int i = 0;
    int j = A.size() - 1;
    while(i < j) {
        if(A[i] % 2 > A[j] % 2) {
            std::swap(A[i], A[j]);
        }
        if(!(A[i]%2)) {
            ++i;
        }
        if(A[j]%2) {
            --j;
        }
    }   
    return A;
}