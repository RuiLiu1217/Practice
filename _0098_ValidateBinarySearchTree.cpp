#include "headers.hpp"

// Facebook

/*
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        auto [min, max, isValid] = isValidBSTImpl(root);
        return isValid;
    }
    
    std::tuple<double, double, bool> isValidBSTImpl(TreeNode* root) {
        if(!root) {
            return {INT_MAX + 1.0, INT_MIN - 1.0, true};
        } else if(root->left == nullptr && root->right == nullptr) {
            return {root->val, root->val, true};
        } else {
            auto [lmin, lmax, leftBST] = isValidBSTImpl(root->left);
            auto [rmin, rmax, rightBST] = isValidBSTImpl(root->right);
            double val = root->val;
            bool isValid = lmax < val && rmin > val && leftBST && rightBST;
            return {std::min(lmin, val), std::max(rmax, val), isValid};
        }
    }
};
*/

bool LeetCode::_0098_ValidateBinarySearchTree::isValidBST(TreeNode<int>* root) {
    if(!root) {
        return true;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return true;
    }

    TreeNode<int>* p = root;
    std::stack<TreeNode<int>*> st;
    int preV = INT_MIN;
    bool notfound = true;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            TreeNode<int>* q = st.top();
            st.pop();
            // Make the decision, if it is the first time get the value, just let it go
            // if not, we need to compare whether the current value is larger than
            // the previous value.
            if(notfound) {
                preV = q->val;
                notfound = false;
            } else {
                if(q->val <= preV) {
                    return false;
                } else {
                    preV = q->val;
                }
            }
            p = q->right;
        }
    }
    return true;
}