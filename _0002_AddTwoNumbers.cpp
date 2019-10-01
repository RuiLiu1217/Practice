#include "headers.hpp"

ListNode<int>* LeetCode::_0002_AddTwoNumbers::addTwoNumbers(ListNode<int>* l1, ListNode<int>* l2) {
    return AddTwoNodes(l1, l2, 0);
}

ListNode<int>* AddTwoNodes(ListNode<int>* l1, ListNode<int>* l2, int wi) {
    if(l1 == nullptr && l2 == nullptr && wi == 0) {
        return nullptr;
    } else if(l1 == nullptr && l2 == nullptr && wi != 0) {
        ListNode<int>* res = new ListNode<int>(wi);
        res->next = nullptr;
        return res;
    } else if(l1 != nullptr && l2 == nullptr) {
        ListNode<int>* res = new ListNode(l1->val + wi);
        if(res->val < 10) {
            res->next = AddTwoNodes(l1->next, nullptr, 0);
            return res;
        } else {
            res->val -= 10;
            res->next = AddTwoNodes(l1->next, nullptr, 1);
            return res;
        }
    } else if(l1 == nullptr && l2 != nullptr) {
        ListNode<int>* res = new ListNode(l2->val + wi);
        if(res->val < 10) {
            res->next = AddTwoNodes(nullptr, l2->next, 0);
            return res;
        } else {
            res->val -= 10;
            res->next = AddTwoNodes(nullptr, l2->next, 1);
            return res;
        }
    } else {
        ListNode<int>* res = new ListNode<int>(l1->val + l2->val + wi);
        if(res->val < 10) {
            res->next = AddTwoNodes(l1->next, l2->next, 0);
            return res;
        } else {
            res->val -= 10;
            res->next = AddTwoNodes(l1->next, l2->next, 1);
            return res;
        }
    }
}
