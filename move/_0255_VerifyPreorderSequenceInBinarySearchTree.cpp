#include "headers.hpp"

bool LeetCode::_0255_VerifyPreorderSequenceInBinarySearchTree::verifyPreorder(std::vector<int>& preorder) {
    if(preorder.size() == 0) {
        return true;
    }
    return isPreorder(preorder, 0, preorder.size());
}

bool LeetCode::_0255_VerifyPreorderSequenceInBinarySearchTree::isPreorder(std::vector<int>& preorder, int startIdx, int endIdx) {
    if(startIdx == endIdx) {
        return true;
    }
    
    if(endIdx - startIdx == 1) {
        return true;
    }
    
    int v = preorder[startIdx];
    int newLeftEndIdx = startIdx + 1;
    while(newLeftEndIdx < endIdx && preorder[newLeftEndIdx] < v) {
        ++newLeftEndIdx;
    }
    int testIdx = newLeftEndIdx;
    while(testIdx < endIdx) {
        if(preorder[testIdx] < v) {
            return false;
        }
        ++testIdx;
    }
    
    return isPreorder(preorder, startIdx + 1, newLeftEndIdx) && isPreorder(preorder, newLeftEndIdx, endIdx);
}

// Concise solution
static int i = 0;
static bool verifyPreorder(vector<int>& A, int left=INT_MIN, int right=INT_MAX) {
    if (i == A.size() || A[i] > right) return true;
    int mid = A[i++];
    return mid > left && verifyPreorder(A, left, mid) && verifyPreorder(A, mid, right);
}