#ifndef TREE_HPP
#define TREE_HPP
// Tree Node
template <typename T>
struct TreeNode
{
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(const T &v) : val(v), left(nullptr), right(nullptr) {}
};


/*
void preorderMorrisTraversal(TreeNode<int>* root) {
    TreeNode<int>* cur = root;
    TreeNode<int>* prev = nullptr;
    while(cur != nullptr) {
        if(cur->left == nullptr) {
            // access cur->val;
            cur = cur->right;
        } else {
            prev = cur->left;
            while(prev->right != nullptr && prev != cur) {
                prev = prev->right;
            }
            if(prev->right == nullptr) {
                // Access cur->val;
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
}

void inordermorrisTraversal(TreeNode<int>* root) {
    TreeNode<int>* cur = root;
    TreeNode<int>* prev = nullptr;
    while(cur != nullptr) {
        if(cur->left == nullptr) {
            // access cur->val;
            cur = cur->right;
        } else {
            prev = cur->left;
            while(prev->right != nullptr && prev != cur) {
                prev = prev->right;
            }
            if(prev->right == nullptr) {
                prev->right = cur;
                cur = cur->left;
            } else {
                // Access cur->val;
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
}
*/






#endif