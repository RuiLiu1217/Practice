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

// Nary tree serialize and deserialize, hard to test
TEST(LC, _0428_SerializeAndDeserializeNAryTree) {
    EXPECT_TRUE(true);
}

TEST(LC, _0235_LowestCommonAncestorOfABinarySearchTree) {
    LC::_0235_LowestCommonAncestor obj;
    LC::TreeNode* r = new LC::TreeNode(6);
    r->left = new LC::TreeNode(2);
    r->right = new LC::TreeNode(8);
    r->right->left = new LC::TreeNode(7);
    r->right->right = new LC::TreeNode(9);
    r->left->left = new LC::TreeNode(0);
    r->left->right = new LC::TreeNode(4);
    r->left->right->left = new LC::TreeNode(3);
    r->left->right->right = new LC::TreeNode(5);

    LC::TreeNode* p = r->left;
    LC::TreeNode* q = r->right;
    EXPECT_EQ(obj.lowestCommonAncestorIterative(r, p, q), r);
    EXPECT_EQ(obj.lowestCommonAncestorRecursive(r, p, q), r);

    LC::TreeNode* p1 = r->left->right->left;
    LC::TreeNode* q1 = r->left->left;
    EXPECT_EQ(obj.lowestCommonAncestorIterative(r, p1, q1), r->left);
    EXPECT_EQ(obj.lowestCommonAncestorRecursive(r, p1, q1), r->left);

}
TEST(LC, _0236_LowestCommonAncestorBinaryTree) {
    LC::_0236_LowestCommonAncestorBinaryTree obj;
    LC::TreeNode* r = new LC::TreeNode(3);
    r->left = new LC::TreeNode(5);
    r->right = new LC::TreeNode(1);
    r->left->left = new LC::TreeNode(6);
    r->left->right = new LC::TreeNode(2);
    r->left->right->left = new LC::TreeNode(7);
    r->left->right->right = new LC::TreeNode(4);
    r->right->left = new LC::TreeNode(0);
    r->right->right = new LC::TreeNode(8);
    LC::TreeNode* p = r->right->left;
    LC::TreeNode* q = r->left->right->right;
    EXPECT_EQ(obj.lowestCommonAncestor(r, p, q), r);
}

TEST(LC, _0255_VerifyPreorderSequenceInBinarySearchTree) {
    LC::_0255_VerifyPreorderSequenceInBinarySearchTree obj;
    std::vector<int> t{5,2,6,1,3};
    EXPECT_FALSE(obj.verifyPreorder(t));
}