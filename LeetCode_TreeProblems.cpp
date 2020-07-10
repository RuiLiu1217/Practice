#include "LeetCode_TreeProblems.hpp"
#include <queue>
#include <stack>

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
bool LC::_0098_ValidateBinarySearchTree::isValidBST(TreeNode* root) {
    if(!root) {
        return true;
    }
    if(root->left == nullptr && root->right == nullptr) {
        return true;
    }

    TreeNode* p = root;
    std::stack<TreeNode*> st;
    int preV = INT_MIN;
    bool notfound = true;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            st.push(p);
            p = p->left;
        } else {
            TreeNode* q = st.top();
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

LC::_1485_CloneBinaryTreeWithRandomPointer::NodeCopy* LC::_1485_CloneBinaryTreeWithRandomPointer::copyRandomBinaryTree(LC::_1485_CloneBinaryTreeWithRandomPointer::Node* root) {
    if(!root) {
        return nullptr;
    }
    if(map.find(root) != map.end()) {
        return map[root];
    }
    LC::_1485_CloneBinaryTreeWithRandomPointer::NodeCopy *newroot = new LC::_1485_CloneBinaryTreeWithRandomPointer::NodeCopy(root->val);
    map[root] = newroot;        
    if(root->left) {
        newroot->left = copyRandomBinaryTree(root->left);
    }
    if(root->right) {
        newroot->right = copyRandomBinaryTree(root->right);
    }
    if(root->random) {
        newroot->random = copyRandomBinaryTree(root->random);
    }
    return newroot;
}



bool LC::_0100_SameTree::isSameTree(TreeNode *p, TreeNode *q) {
    if (p==nullptr && q==nullptr) {
        return true;
    }
    if ((p == nullptr && q != nullptr) ||(p != nullptr && q == nullptr)) {
        return false;
    }
    
    if(p->val != q->val) {
        return false;
    } else {
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
    
}
