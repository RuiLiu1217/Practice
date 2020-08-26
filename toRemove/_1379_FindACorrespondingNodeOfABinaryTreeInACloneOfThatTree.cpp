#include "headers.hpp"

TreeNode<int>* _1379_FindACorrespondingNodeOfABinaryTreeInACloneOfThatTree::getTargetCopy(TreeNode<int>* original, TreeNode<int>* cloned, TreeNode<int>* target) {
    TreeNode<int>* p1 = original;
    TreeNode<int>* p2 = cloned;
    std::stack<TreeNode<int>*> st1;
    std::stack<TreeNode<int>*> st2;
    while(p1 != nullptr || !st1.empty()) {
        if(p1 != nullptr) {
            if(p1->val == target->val) {
                return p2;
            }
            st1.push(p1);
            st2.push(p2);
            p1 = p1->left;
            p2 = p2->left;
        } else {
            TreeNode<int>* q1 = st1.top();
            st1.pop();
            TreeNode<int>* q2 = st2.top();
            st2.pop();
            p1 = q1->right;
            p2 = q2->right;
        }
    }
    return nullptr;
}