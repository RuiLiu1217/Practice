#include "headers.hpp"
#include <unordered_set>

// Facebook

std::vector<std::vector<int>> LeetCode::_0311_SparseMatrixMultiplication::multiply(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B) {
    const int MA = A.size();
    if(MA == 0) {
        return {};
    }
    const int NA = A[0].size();
    if(NA == 0) {
        return {};
    }
    
    std::vector<std::unordered_set<int>> colA(MA);
    for(int i = 0; i < MA; ++i) {
        for(int j = 0; j < NA; ++j) {
            if(A[i][j]) {
                colA[i].insert(j);
            }
        }
    }
    
    const int MB = B.size();
    if(MB == 0) {
        return {};
    }
    const int NB = B[0].size();
    if(NB == 0) {
        return {};
    }
    
    std::vector<std::vector<int>> res(MA, std::vector<int>(NB));
    for(int i =0; i < MA; ++i) {
        std::unordered_set<int>& idxA = colA[i];
        for(int j = 0; j < NB; ++j) {
            int sum = 0;    
            for(int k = 0; k < MB; ++k) {
                if(idxA.count(k) && B[k][j]) {
                    sum += A[i][k] * B[k][j];
                }
            }
        
            res[i][j] = sum;
        }
    }
    return res;
}
 