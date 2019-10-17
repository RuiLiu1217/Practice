#include "headers.hpp"

int LintCode::_1508_ScoreAfterFlippingMatrix::matrixScore(std::vector<std::vector<int>>& A) {
    for(int i = 0; i < A.size(); ++i) {
        if(A[i][0] == 0) {
            flipRow(A, i);
        }
    }
    
    for(int j = 1; j < A[0].size(); ++j) {
        if (countOnes(A, j) < A[0].size() / 2) {
            flipCol(A, j);
        }
    }
    int res = 0;
    for(int i = 0; i < A.size(); ++i) {
        res += toNum(A[i]);
    }
    return res;
}

void LintCode::_1508_ScoreAfterFlippingMatrix::flipRow(std::vector<std::vector<int>>& A, int rowIdx) {
    for(int i = 0; i < A[rowIdx].size(); ++i) {
        if(A[rowIdx][i] == 0) {
            A[rowIdx][i] = 1;
        } else {
            A[rowIdx][i] = 0;
        }
    }
}

void LintCode::_1508_ScoreAfterFlippingMatrix::flipCol(std::vector<std::vector<int>>& A, int colIdx) {
    const int colNum = A.size();
    for(int j = 0; j < colNum; ++j) {
        if (A[j][colIdx] == 0) {
            A[j][colIdx] = 1;
        } else {
            A[j][colIdx] = 0;
        }
    }
}

int LintCode::_1508_ScoreAfterFlippingMatrix::countOnes(std::vector<std::vector<int>>& A, int colIdx) {
    const int colNum = A.size();
    int count = 0;
    for(int j = 0; j < colNum; ++j) {
        if (A[j][colIdx] == 1) {
            ++count;
        }
    }
    return count;
}

int LintCode::_1508_ScoreAfterFlippingMatrix::toNum(std::vector<int>& v) {
    int res = 0;
    for(auto& t : v) {
        res <<= 1;
        res += t;
    }
    return res;
}
