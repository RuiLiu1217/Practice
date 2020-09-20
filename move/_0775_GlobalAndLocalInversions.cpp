#include "headers.hpp"

bool LeetCode::_0775_GlobalAndLocalInversions::isIdealPermutation(std::vector<int>& A) {
    std::vector<int> tmp = A;
    for(int i = 1; i < A.size(); ++i) {
        if(A[i] < A[i-1]) {
            std::swap(tmp[i], tmp[i-1]);
        }
    }
    for(int i = 0; i < tmp.size(); ++i) {
        if(tmp[i] != i) {
            return false;
        }
    }
    return true;
}