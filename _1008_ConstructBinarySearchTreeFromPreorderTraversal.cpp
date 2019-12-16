#include "headers.hpp"
#include <algorithm>

TreeNode<int>* LeetCode::_1008_ConstructBinarySearchTreeFromPreorderTraversal::bstFromPreorderImpl(std::vector<int>& preorder, int bound) {
    if(i == preorder.size() || preorder[i] > bound) {
        return nullptr;
    }

    TreeNode<int>* root = new TreeNode<int>(preorder[i++]);
    root->left = bstFromPreorderImpl(preorder, root->val);
    root->right = bstFromPreorderImpl(preorder, bound);
    return root;
}

static TreeNode<int>* bstFromPreorderImpl(
    std::vector<int>& preorder, 
    std::vector<int>& inorder) {
    if(preorder.size() == 0) {
        return nullptr;
    }
    TreeNode<int>* root = new TreeNode<int>(preorder[0]);
    if(preorder.size() == 1) {
        return root;
    }
    
    auto inorderIter = std::find(inorder.begin(), inorder.end(), preorder[0]);
    int idx = inorderIter - inorder.begin(); 
    
    std::vector<int> preorder_left(preorder.begin() + 1, preorder.begin() + 1 + idx);
    std::vector<int> preorder_right(preorder.begin()+1+idx, preorder.end());
    std::vector<int> inorder_left(inorder.begin(), inorderIter);
    std::vector<int> inorder_right(inorderIter + 1, inorder.end());
    
    root->left = bstFromPreorderImpl(preorder_left, inorder_left);
    root->right = bstFromPreorderImpl(preorder_right, inorder_right);
    return root;
}

TreeNode<int>* LeetCode::_1008_ConstructBinarySearchTreeFromPreorderTraversal::bstFromPreorder(std::vector<int>& preorder) {
    std::vector<int> inorder(preorder);
    std::sort(inorder.begin(), inorder.end());
    return bstFromPreorderImpl(preorder, INT_MAX);
}