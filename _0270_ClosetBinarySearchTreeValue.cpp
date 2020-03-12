#include "headers.hpp"

int LeetCode::_0270_ClosetBinarySearchTreeValue::closestValue(TreeNode<int>* root, double target) {
    TreeNode<int>* minV = root;
    TreeNode<int>* preV = root;
    while(minV) {
        preV = minV;
        minV = minV->left;
    }
    int minVal = preV->val;
    
    if(target < minVal) {
        return minVal;
    }
    
    preV = root;
    TreeNode<int>* maxV = root;
    while(maxV) {
        preV = maxV;
        maxV = maxV->right;
    }
    int maxVal = preV->val;
    if(target > maxVal) {
        return maxVal;
    }
    
    TreeNode<int>* p = root;
    double minDiff = INT_MAX;
    int res;
    while(p) {
        double diff = std::abs(static_cast<double>(p->val) - target);
        if(diff < minDiff) {
            res = p->val;
            minDiff = diff;
        }
        if(p->val < target) {
            p = p->right;
        } else if(p->val > target) {
            p = p->left;
        } else {
            return p->val;
        }
    }
    return res;
}