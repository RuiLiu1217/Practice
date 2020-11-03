#ifndef TREE_HPP
#define TREE_HPP
#include <stack>
// Tree Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(const int v) : val(v), left(nullptr), right(nullptr) {}
};

// Morris Traversal
std::vector<int> inorderMorrisTraversal(TreeNode* root) {
    std::vector<int> res;
    if(!root) { return {}; }
    TreeNode* cur = root;
    TreeNode* pre;
    while(cur) {
        if(!cur->left) {
            res.push_back(cur->val);
            cur = cur->right;
        } else {
            pre = cur->left;
            while(pre->right && pre->right != cur) {
                pre = pre->right;
            }
            if(!pre->right) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return res;
}


void inorderTraversal(TreeNode* root) {
    TreeNode* p = root;
    TreeNode* pre = nullptr;
    std::stack<TreeNode*> st;
    std::vector<int> res;
    while(p != nullptr || !st.empty()) {
        while(p) {
            st.push(p);
            p = p->left;
        }

        p = st.top(); st.pop();

        res.push_back(p->val);

        pre = p; // The traversal methods that we can know its previous node.
        p = p->right;
    }
}



#endif