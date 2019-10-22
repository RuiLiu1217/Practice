#include "headers.hpp"
std::vector<int> LintCode::_0006_MergeTwoSortedArrays::mergeSortedArray(std::vector<int> &A, std::vector<int> &B) {
    std::vector<int> res(A.size() + B.size(), 0);
    int i = 0; 
    int j = 0;
    int t = 0;
    while(i < A.size() && j < B.size()) {
        if(A[i] < B[j]) {
            res[t++] = A[i++];
        } else {
            res[t++] = B[j++];
        }
    }
        
    if(i < A.size()) {
        std::copy(A.begin()+i, A.end(), res.begin()+t);
    } else if(j < B.size()) {
        std::copy(B.begin() +j, B.end(), res.begin()+t);
    }
    return res;
}
