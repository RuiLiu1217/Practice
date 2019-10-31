#include "headers.hpp"

TreeNode<int>* LeetCode::_0106_ConstructBinaryTreeFromInorderAndPostorderTraversal::buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
}


TreeNode<int>* LeetCode::_0106_ConstructBinaryTreeFromInorderAndPostorderTraversal::buildTree(std::vector<int>& inorder, int inStart, int inEnd, 
                       std::vector<int>& postorder, int postStart, int postEnd) {
    if(postStart >= postEnd) {
        return nullptr;
    }
    
    TreeNode<int>* root = new TreeNode<int>(postorder[postEnd - 1]);
    if(postEnd - postStart == 1) {            
        return root;
    }

    auto iter = std::find(inorder.begin() + inStart, inorder.begin() + inEnd, root->val);
    int lftLength = std::distance(inorder.begin() + inStart, iter);
    
    root->left = buildTree(inorder, inStart, inStart + lftLength,
                            postorder, postStart, postStart + lftLength);
    root->right = buildTree(inorder, inStart + lftLength + 1, inEnd,
                            postorder, postStart + lftLength, postEnd - 1); // 这道题的index计算折磨了半天
    
    return root;
}

