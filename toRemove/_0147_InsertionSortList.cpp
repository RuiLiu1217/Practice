#include "headers.hpp"

ListNode<int>* LeetCode::_0147_InsertionSortList::insertionSortList(ListNode<int>* head) {
    ListNode<int>* nh = new ListNode<int>(INT_MIN);
    nh->next = head;
    ListNode<int>* toSort = head;
    while(toSort) {
        ListNode<int>* nxt = toSort->next;
        toSort->next = nullptr;
        ListNode<int>* p = nh;
        while(p->next && (p->next->val < toSort->val)) {
            p = p->next;
        }
        if (p->next != toSort) {
            toSort->next = p->next;
            p->next = toSort;
        }
        toSort = nxt;
    }
    head = nh->next;
    delete nh;
    nh = nullptr;
    return head;
}

