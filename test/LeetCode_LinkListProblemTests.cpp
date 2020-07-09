#include <gtest/gtest.h>
#include "../LeetCode_LinkListProblems.hpp"

TEST(LC, LC__0002_Test) {
    LC::_0002_AddTwoNumbers obj;
    LC::ListNode* p1 = new LC::ListNode(2);
    p1->next = new LC::ListNode(4);
    p1->next->next = new LC::ListNode(3);

    LC::ListNode* p2 = new LC::ListNode(5);
    p2->next = new LC::ListNode(6);
    p2->next->next = new LC::ListNode(4);

    LC::ListNode* res = obj.addTwoNumbers(p1, p2);

    EXPECT_EQ(res->val, 7);
    EXPECT_EQ(res->next->val, 0);
    EXPECT_EQ(res->next->next->val, 8);

    delete p2->next->next;
    delete p2->next;
    delete p2;

    delete p1->next->next;
    delete p1->next;
    delete p1;
    
    delete res->next->next;
    delete res->next;
    delete res;
}

TEST(LC, _0019_RemoveNthNodeFromEndToList) {
    LC::_0019_RemoveNthNodeFromEndToList obj;
    LC::ListNode* p1 = new LC::ListNode(1);
    p1->next = new LC::ListNode(2);
    p1->next->next = new LC::ListNode(3);
    p1->next->next->next = new LC::ListNode(4);
    p1->next->next->next->next = new LC::ListNode(5);
    LC::ListNode* res = obj.removeNthFromEnd(p1, 2);
    EXPECT_EQ(res->val, 1);
    EXPECT_EQ(res->next->val, 2);
    EXPECT_EQ(res->next->next->val, 3);
    EXPECT_EQ(res->next->next->next->val, 5);

    delete res->next->next->next;
    delete res->next->next;
    delete res->next;
    delete res;    
}

TEST(LC, _0021_MergeTwoSortedLists) {
    LC::_0021_MergeTwoSortedLists obj;

    LC::ListNode* p1 = new LC::ListNode(1);
    p1->next = new LC::ListNode(2);
    p1->next->next = new LC::ListNode(4);

    LC::ListNode* p2 = new LC::ListNode(1);
    p2->next = new LC::ListNode(3);
    p2->next->next = new LC::ListNode(4);
    
    LC::ListNode* res = obj.mergeTwoLists(p1, p2);
    EXPECT_EQ(res->val, 1);
    EXPECT_EQ(res->next->val, 1);
    EXPECT_EQ(res->next->next->val, 2);
    EXPECT_EQ(res->next->next->next->val, 3);
    EXPECT_EQ(res->next->next->next->next->val, 4);
    EXPECT_EQ(res->next->next->next->next->next->val, 4);
}


TEST(LC, _0023_MergeKeSortedLists) {
    std::vector<LC::ListNode*> lists(3);
    lists[0] = new LC::ListNode(1);
    lists[0]->next = new LC::ListNode(3);
    lists[0]->next->next = new LC::ListNode(5);

    lists[1] = new LC::ListNode(2);
    lists[1]->next = new LC::ListNode(4);
    lists[1]->next->next = new LC::ListNode(6);

    lists[2] = new LC::ListNode(3);
    lists[2]->next = new LC::ListNode(6);
    lists[2]->next->next = new LC::ListNode(9);
    LC::_0023_MergeKeSortedLists obj;
    LC::ListNode* res = obj.mergeKLists(lists);
    std::vector<int> v{1, 2, 3, 3, 4, 5, 6, 6, 9};
    LC::ListNode* p = res;
    for(int i = 0; i < 9; ++i) {
        EXPECT_EQ(p->val, v[i]);
        p = p->next;
    }
}

TEST(LC, _0024_) {
    LC::_0024_SwapNodesInPairs obj;
    LC::ListNode* h = new LC::ListNode(1);
    h->next = new LC::ListNode(2);
    h->next->next = new LC::ListNode(3);
    h->next->next->next = new LC::ListNode(4);

    LC::ListNode* res = obj.swapPairs(h);
    EXPECT_EQ(res->val, 2);
    EXPECT_EQ(res->next->val, 1);
    EXPECT_EQ(res->next->next->val, 4);
    EXPECT_EQ(res->next->next->next->val, 3);
}

/*
Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
Note:
Only constant extra memory is allowed.
*/

TEST(LC, _0025_ReverseNodeInKGroup) {
    LC::_0025_ReverseNodeInKGroup obj;
    LC::ListNode* h = new LC::ListNode(1);
    h->next = new LC::ListNode(2);
    h->next->next = new LC::ListNode(3);
    h->next->next->next = new LC::ListNode(4);
    h->next->next->next->next = new LC::ListNode(5);
    LC::ListNode* n = obj.reverseGroup(h, 2);
    EXPECT_EQ(n->val, 2);
    EXPECT_EQ(n->next->val, 1);
    EXPECT_EQ(n->next->next->val, 4);
    EXPECT_EQ(n->next->next->next->val, 3);
    EXPECT_EQ(n->next->next->next->next->val, 5);
}


TEST(LC, _0061_RotateList) {
    LC::_0061_RotateList obj;
    LC::ListNode* h = new LC::ListNode(1);
    h->next = new LC::ListNode(2);
    h->next->next = new LC::ListNode(3);
    h->next->next->next = new LC::ListNode(4);
    h->next->next->next->next = new LC::ListNode(5);
    LC::ListNode* n = obj.rotateRight(h, 2);
    EXPECT_EQ(n->val, 4);
    EXPECT_EQ(n->next->val, 5);
    EXPECT_EQ(n->next->next->val, 1);
    EXPECT_EQ(n->next->next->next->val, 2);
    EXPECT_EQ(n->next->next->next->next->val, 3);
}