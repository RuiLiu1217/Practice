#include "headers.hpp"

ListNode<int>* LeetCode::_0083_RemoveDuplicatesFromSortedList::deleteDuplicates(ListNode<int>* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode<int>* h = head;
    ListNode<int>* t = h->next;
    while(t != nullptr) {
        if(h->val == t-> val) {
            h->next = t->next;
            t = h->next;
            continue;
        } else {
            h = t;
            t = t->next;
        }
    }
    return head;
}