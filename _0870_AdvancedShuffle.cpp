#include "headers.hpp"

std::vector<int> LeetCode::_0870_AdvancedShuffle::advantageCount(std::vector<int>& A, std::vector<int>& B) {
    std::sort(begin(A), end(A));
    std::vector<int> res;
    for(int i = 0; i < B.size(); ++i) {
        int idx = binarySearch(A, B[i]);
        res.push_back(A[idx]);
        updateA(A, idx);
    }
    return res;
}

void LeetCode::_0870_AdvancedShuffle::updateA(std::vector<int>& A, int idx) {
    for(int i = idx + 1; i < A.size(); ++i) {
        A[i-1] = A[i];
    }
    A.resize(A.size() - 1);
}

int LeetCode::_0870_AdvancedShuffle::binarySearch(std::vector<int>& A, int v) {
    int s = 0;
    int e = A.size();
    while(s < e) {
        int m = s + (e - s) / 2;
        if(A[m] == v) {
            s = m + 1;
        } else if(A[m] < v) {
            s = m + 1;
        } else {
            e = m;
        }
    }
    if(s == A.size()) {
        return 0; // there is no such value that greater than v, just give a smallest one;
    } else {
        return s;
    }
}