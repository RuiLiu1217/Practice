#include <gtest/gtest.h>
#include "../LintCode.hpp"

TEST(LINTCODE, _0001_APlusBProblem) {
    LintCode::_0001_APlusBProblem obj;
    
    EXPECT_EQ(obj.aplusb(0, 0), 0);
    EXPECT_EQ(obj.aplusb(1, 1), 2);
    EXPECT_EQ(obj.aplusb(-1, -1), -2);
    EXPECT_EQ(obj.aplusb(1, -1), 0);
    EXPECT_EQ(obj.aplusb(100, 200), 300);
}

TEST(LINTCODE, _0002_TrailingZeros) {
    LintCode::_0002_TrailingZeros obj;
    EXPECT_EQ(obj.trailingZeros(1), 0);
    EXPECT_EQ(obj.trailingZeros(5), 1);
    EXPECT_EQ(obj.trailingZeros(11), 2);
    EXPECT_EQ(obj.trailingZeros(25), 6);
}


TEST(LINTCODE, _0004_UglyNumberII) {
    LintCode::_0004_UglyNumberII obj;
    EXPECT_EQ(obj.nthUglyNumber(9), 10);
    EXPECT_EQ(obj.nthUglyNumber(1), 1);
}

TEST(LINTCODE, _0006_MergeTwoSortedArrays) {
    LintCode::_0006_MergeTwoSortedArrays obj;
    std::vector<int> A {0,3,5,7,9};
    std::vector<int> B {1,3,4,6,7,8,9,10};
    std::vector<int> res = obj.mergeSortedArray(A, B);
    std::vector<int> base{0,1,3,3,4,5,6,7,7,8,9,9,10};
    EXPECT_EQ(res, base);
}

TEST(LINTCODE, _0008_RotateString) {
    LintCode::_0008_RotateString obj;
    std::string testStr = "ABCDEFG";
    obj.rotateString(testStr, 1);
    EXPECT_EQ(testStr, "GABCDEF");

    testStr="abcdefg";
    obj.rotateString(testStr, 3);
    EXPECT_EQ(testStr, "efgabcd");

    testStr = "abcdefg";
    obj.rotateString(testStr, 0);
    EXPECT_EQ(testStr, "abcdefg");

    testStr = "abcdefg";
    obj.rotateString(testStr, 10);
    EXPECT_EQ(testStr, "efgabcd");
}

TEST(LINTCODE, _0009_FizzBuzz) {
    LintCode::_0009_FizzBuzz obj;
    std::vector<std::string> res = obj.fizzBuzz(15);
    std::vector<std::string> base{"1", "2", "fizz", 
    "4", "buzz", "fizz", "7", "8", "fizz", "buzz", "11", "fizz", "13", "14", "fizz buzz"};
    EXPECT_EQ(res, base);
}

TEST(LINTCODE, _1010_MaxIncreaseToKeepCitySkyline) {
    LintCode::_1010_MaxIncreaseToKeepCitySkyline obj;
    std::vector<std::vector<int>> grid{{3,0,8,4}, {2,4,5,7}, {9,2,6,3}, {0,3,1,0}};
    int res = obj.maxIncreaseKeepingSkyline(grid);
    EXPECT_EQ(res, 35);
}

TEST(LINTCODE, _1038_JewelsAndStones) {
    LintCode::_1038_JewelsAndStones obj;
    std::string s1 = "aA";
    std::string s2 = "aAAbbbb";
    std::string s3 = "z";
    std::string s4 = "ZZ";
    EXPECT_EQ(obj.numJewelInStones(s1, s2), 3);
    EXPECT_EQ(obj.numJewelInStones(s3, s4), 0);
}

TEST(LINTCODE, _1104_JudgeRouteCircle) {
    LintCode::_1104_JudgeRouteCircle obj;
    std::string t = "UD";
    EXPECT_TRUE(obj.judgeCircle(t));
    std::string f = "LL";
    EXPECT_FALSE(obj.judgeCircle(f));
}

TEST(LINTCODE, _1115_AverageOfLevelsInBinaryTree) {
    LintCode::_1115_AverageOfLevelsInBinaryTree obj;
    TreeNode<int>* r = new TreeNode<int>(3);
    r->left = new TreeNode<int>(9);
    r->right = new TreeNode<int>(20);
    r->right->left = new TreeNode<int>(15);
    r->right->right = new TreeNode<int>(7);
    std::vector<double> res = obj.averageOfLevels(r);
    std::vector<double> ground{3, 14.5, 11};
    EXPECT_EQ(res, ground);

    delete r->right->right;
    delete r->right->left;
    delete r->right;
    delete r->left;
    delete r;
}

TEST(LINTCODE, _1126_MergeTwoBinaryTrees) {
    TreeNode<int>* t1 = new TreeNode<int>(1);
    t1->left = new TreeNode<int>(3);
    t1->right = new TreeNode<int>(2);
    t1->left->left = new TreeNode<int>(5);

    TreeNode<int>* t2 = new TreeNode<int>(2);
    t2->left = new TreeNode<int>(1);
    t2->left->right = new TreeNode<int>(4);
    t2->right = new TreeNode<int>(3);
    t2->right->right = new TreeNode<int>(7);

    LintCode::_1126_MergeTwoBinaryTrees obj;
    TreeNode<int>* m = obj.mergeTrees(t1, t2);
    EXPECT_EQ(m->val, 3);
    EXPECT_EQ(m->left->val, 4);
    EXPECT_EQ(m->right->val, 5);
    EXPECT_EQ(m->left->left->val, 5);
    EXPECT_EQ(m->left->right->val, 4);
    EXPECT_EQ(m->right->right->val, 7);
    delete t2->right->right;
    delete t2->right;
    delete t2->left->right;
    delete t2->left;
    delete t2;

    delete t1->left->left;
    delete t1->right;
    delete t1->left;
    delete t1;
}

TEST(LINTCODE, _1317_CountCompleteTreeNode) {
    LintCode::_1317_CountCompleteTreeNodes obj;

    TreeNode<int>* t2 = new TreeNode<int>(2);
    t2->left = new TreeNode<int>(1);
    t2->left->right = new TreeNode<int>(4);
    t2->right = new TreeNode<int>(3);
    t2->right->right = new TreeNode<int>(7);

    EXPECT_EQ(obj.countNodes(t2), 5);
}

TEST(LINTCODE, _1332_NumberOf1Bits) {
    LintCode::_1332_NumberOf1Bits obj;
    EXPECT_EQ(obj.hammingWeight(11), 3);
}

TEST(LINTCODE, _1355_PascalsTriangle) {
    LintCode::_1355_PascalsTriangle obj;
    std::vector<std::vector<int>> res {{1}, {1,1}, {1,2,1}, {1,3,3,1}, {1,4,6,4,1}};
    EXPECT_EQ(res,  obj.generate(5));
}

TEST(LINTCODE, _1508_ScoreAfterFlippingMatrix) {
    LintCode::_1508_ScoreAfterFlippingMatrix obj;
    std::vector<std::vector<int>> A{{0,0,1,1,},{1,0,1,0},{1,1,0,0}};
    EXPECT_EQ(39, obj.matrixScore(A));
}


TEST(LINTCODE, _1511_MirrorReflection) {
    LintCode::_1511_MirrorReflection obj;
    EXPECT_EQ(2, obj.mirrorReflection(2, 1));
    EXPECT_EQ(1, obj.mirrorReflection(3, 1));
}

TEST(LINTCODE, _1535_ToLowerCase) {
    LintCode::_1535_ToLowerCase obj;
    std::string A = "AAABCD";
    std::string a = "aaabcd";
    EXPECT_EQ(obj.toLowerCase(A), a);
}

TEST(LINTCODE, _1592_FindAndReplacePattern) {
    LintCode::_1592_FindAndReplacePattern obj;
    std::vector<std::string> A{"abc","deq","mee","aqq","dkd"};
    
    std::string pattern1 = "abb";
    std::vector<std::string> res1{"mee", "aqq"};

    std::vector<std::string> B{"a","b","c"};
    std::string pattern2 = "a";
    std::vector<std::string> res2{"a","b","c"};
    EXPECT_EQ(res1, obj.findAndReplacePattern(A, pattern1));
    EXPECT_EQ(res2, obj.findAndReplacePattern(B, pattern2));    
}