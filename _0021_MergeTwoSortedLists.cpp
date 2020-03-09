#include "headers.hpp"

/*
Google
*/
ListNode<int>* LeetCode::_0021_MergeTwoSortedLists::mergeTwoLists(
    ListNode<int>* l1, ListNode<int>* l2) {
    if(l1 == nullptr && l2 == nullptr) {
        return nullptr;
    } else if(l1 == nullptr && l2 != nullptr) {
        return l2;
    } else if(l2 == nullptr && l1 != nullptr) {
        return l1;
    } else {
        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
}