#include <gtest/gtest.h>
#include "../LeetCode_TreeProblems.hpp"

TEST(LC, _1485_) {

}

TEST(LC, _0098_ValidateBinarySearchTree) {
    LC::_0098_ValidateBinarySearchTree obj;
    LC::TreeNode* root = new LC::TreeNode(2);
    root->left = new LC::TreeNode(1);
    root->right = new LC::TreeNode(3);
    EXPECT_TRUE(obj.isValidBST(root));
}

TEST(LC, _0100_SameTree) {
    LC::_0100_SameTree obj;
    LC::TreeNode* root = new LC::TreeNode(2);
    root->left = new LC::TreeNode(1);
    root->right = new LC::TreeNode(3);

    LC::TreeNode* root2 = new LC::TreeNode(2);
    root2->left = new LC::TreeNode(1);
    root2->right = new LC::TreeNode(3);
    EXPECT_TRUE(obj.isSameTree(root, root2));

    LC::TreeNode* root3 = new LC::TreeNode(1);
    root3->left = new LC::TreeNode(1);
    root3->right = new LC::TreeNode(4);


    EXPECT_FALSE(obj.isSameTree(root, root3));
}

TEST(LC, _0101_SymmetricTree) {
    LC::_0101_SymmetricTree obj;
    LC::TreeNode* root = new LC::TreeNode(2);
    root->left = new LC::TreeNode(1);
    root->right = new LC::TreeNode(1);
    EXPECT_TRUE(obj.isSymmetric(root));
}

TEST(LC, _0102_BinaryTreeLevelOrderTraversal) {
    LC::_0102_BinaryTreeLevelOrderTraversal obj;
    LC::TreeNode* root = new LC::TreeNode(2);
    root->left = new LC::TreeNode(1);
    root->right = new LC::TreeNode(1);
    std::vector<std::vector<int>> res = obj.levelOrder(root);
    std::vector<std::vector<int>> gth {{2}, {1, 1}};
    EXPECT_EQ(res, gth);
}

TEST(LC, _0103_BinaryTreeZigzagLevelOrderTraversal) {
    LC::_0103_BinaryTreeZigzagLevelOrderTraversal obj;
    LC::TreeNode* root = new LC::TreeNode(2);
    root->left = new LC::TreeNode(1);
    root->right = new LC::TreeNode(1);
    std::vector<std::vector<int>> res = obj.zigzagLevelOrder(root);
    std::vector<std::vector<int>> gth {{2}, {1, 1}};
    EXPECT_EQ(res, gth);
}

TEST(LC, _0104_MaximumDepthOfBinaryTree) {
    LC::_0104_MaximumDepthOfBinaryTree obj;
    LC::TreeNode* root = new LC::TreeNode(2);
    root->left = new LC::TreeNode(1);
    root->right = new LC::TreeNode(1);
    EXPECT_EQ(obj.maxDepth(root), 2);
}

TEST(LC, _0105_ConstructBinaryTreeFromPreorderAndInorderTraversal) {
    EXPECT_TRUE(true);
}

TEST(LC, _0106_ConstructBinaryTreeFromInorderAndPostorderTraversal) {
    EXPECT_TRUE(true);
}

TEST(LC, _0107_BinaryTreeLevelOrderTraversalII) {
    EXPECT_TRUE(true);
}

TEST(LC, _0108_ConvertSortedArrayToBinarySearchTree) {
    EXPECT_TRUE(true);
}

TEST(LC, _0109_ConvertSortedListToBinarySearchTree) {
    EXPECT_TRUE(true);
}

TEST(LC, _0110_BalancedBinaryTree) {
    EXPECT_TRUE(true);
}

TEST(LC, _0112_PathSum) {
    EXPECT_TRUE(true);
}

TEST(LC, _0113_PathSumII) {
    EXPECT_TRUE(true);
}

TEST(LC, _0114_FlattenBinaryTreeToLinkedList) {
    EXPECT_TRUE(true);
}

TEST(LC, _0116_PopulatingNextRightPointerInEachNode) {
    EXPECT_TRUE(true);
}