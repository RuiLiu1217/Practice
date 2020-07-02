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