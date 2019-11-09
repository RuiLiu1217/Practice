#include "headers.hpp"

ListNode<int>* LeetCode::_0328_OddEvenLinkedList::oddEvenList(ListNode<int>* head) {
    ListNode<int>* p1 = head;
    if(!p1) {
        return p1;
    }
    if(!p1->next) {
        return p1;
    }
    if(!p1->next->next) {
        return p1;
    }

    ListNode<int>* p2 = p1->next;
    ListNode<int>* m1 = p1;
    ListNode<int>* m2 = p2;
    while(m2 && m2->next) {
        m1->next = m2->next;
        m2->next = m2->next->next;
        m1 = m1->next;
        m2 = m2->next;
    }
    m1->next = p2;
    return p1;

}
