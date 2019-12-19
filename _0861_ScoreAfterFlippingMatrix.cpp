#include "headers.hpp"
#include <cmath>
static void flipRow(std::vector<std::vector<int>>& A) {
    for(int i = 0; i < A.size(); ++i) {
        if(A[i][0] == 0) {
            for(int j = 0; j < A[i].size(); ++j) {
                A[i][j] = A[i][j] ^ 1;
            }
        }
    }
}

int LeetCode::_0861_ScoreAfterFlippingMatrix::matrixScore(std::vector<std::vector<int>>& A) {
    int powIdx = A[0].size();
    int totRowNum = A.size();
    flipRow(A);
    int sum = std::pow(2, powIdx) * totRowNum;
    for(int j = 1; j < A[0].size(); ++j) {
        --powIdx;
        int num0 = 0;
        int num1 = 0;
        for(int i = 0; i < A.size(); ++i) {
            if(A[i][j] == 0) {
                ++num0;
            } else {
                ++num1;
            }
        }
        if(num0 > num1) {
            sum += pow(2, powIdx) * num0;
        } else {
            sum += pow(2, powIdx) * num1;
        }
    }
    return sum>>1;
}