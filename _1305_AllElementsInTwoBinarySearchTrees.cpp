#include "headers.hpp"

std::vector<int> LeetCode::_1305_AllElementsInTwoBinarySearchTrees::getAllElements(TreeNode<int>* root1, TreeNode<int>* root2) {
    std::vector<int> res;
    TreeNode<int>* p1 = root1;
    std::stack<TreeNode<int>*> st1;
    TreeNode<int>* p2 = root2;
    std::stack<TreeNode<int>*> st2;

    while(p1 != nullptr || p2 != nullptr || !st1.empty() || !st2.empty()) {
        if(p1 != nullptr || p2 != nullptr) {
            if(p1 != nullptr) {
                st1.push(p1);
                p1 = p1->left;
            }
            if(p2 != nullptr) {
                st2.push(p2);
                p2 = p2->left;
            }
        } else {
            TreeNode<int>* q1 = nullptr;
            TreeNode<int>* q2 = nullptr;
            if(!st1.empty()) {
                q1 = st1.top();
            }
            if(!st2.empty()) {
                q2 = st2.top();
            }
            if(q1 && q2) {
                if(q1->val < q2->val) {
                    res.push_back(q1->val);
                    st1.pop();
                    p1 = q1->right;
                } else {
                    res.push_back(q2->val);
                    st2.pop();
                    p2 = q2->right;
                }
            } else if(q1 && !q2) {
                res.push_back(q1->val);
                st1.pop();
                p1 = q1->right;
            } else if(!q1 && q2) { 
                res.push_back(q2->val);
                st2.pop();
                p2 = q2->right;
            }
        }
    }
    return res;
}