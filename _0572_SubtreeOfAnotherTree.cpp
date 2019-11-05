#include "headers.hpp"

bool LeetCode::_0572_SubtreeOfAnotherTree::isSubtree(TreeNode<int>* s, TreeNode<int>* t) {
    TreeNode<int>* p = s;
    std::stack<TreeNode<int>*> st;
    while(p != nullptr || !st.empty()) {
        if(p != nullptr) {
            if(isSame(p, t)) {
                return true;
            }
            st.push(p);
            p = p->left;
        } else {
            TreeNode<int>* q = st.top();
            st.pop();
            p = q->right;
        }
    }
    return false;
}

bool LeetCode::_0572_SubtreeOfAnotherTree::isSame(TreeNode<int>* s, TreeNode<int>* t) {
    if(s == nullptr && t == nullptr) {
        return true;
    }
    TreeNode<int>* p1 = s;
    TreeNode<int>* p2 = t;
    std::stack<TreeNode<int>*> st1;
    std::stack<TreeNode<int>*> st2;
    while(p1 != nullptr || !st1.empty()) {
        if(p1 == nullptr && p2 != nullptr) {
            return false;
        }
        if(p1 != nullptr) {
            if (p2 == nullptr) {
                return false;
            }
            if(p1->val != p2->val) {
                return false;
            }
            
            st1.push(p1);
            st2.push(p2);
            p1 = p1->left;
            p2 = p2->left;
        } else {
            TreeNode<int>* q1 = st1.top();
            st1.pop();
            if(st2.empty()) {
                return false;
            }
            TreeNode<int>* q2 = st2.top();
            st2.pop();
            p1 = q1->right;
            p2 = q2->right;
        }
    }
    return st2.empty();
}