#include "headers.hpp"

static bool isInIncreasingOrder(std::vector<std::string>& A, int idx) {
    for(int i = 1; i < A.size(); ++i) {
        if(A[i][idx] < A[i-1][idx]) {
            return false;
        }
    }
    return true;
}

int LeetCode::_0944_DeleteColumnsToMakeSorted::minDeletionSize(std::vector<std::string>& A) {
    int totNum = 0;
    for(int i = 0; i < A[0].size(); ++i) {
        if(!isInIncreasingOrder(A, i)){
            totNum++;
        }
    }
    return totNum;
}
