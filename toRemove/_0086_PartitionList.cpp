#include "headers.hpp"

ListNode<int>* LeetCode::_0086_PartitionList::partition(ListNode<int>* head, int x) {
    std::queue<ListNode<int>*> les;
    std::queue<ListNode<int>*> big;

    ListNode<int>* nh = new ListNode<int>(INT_MIN);
    while(head) {
        if(head->val < x) {
            les.push(head);
        } else {
            big.push(head);
        }
        head = head->next;
    }

    ListNode<int>* p = nh;
    while(!les.empty()) {
        p->next = les.front();
        p = p->next;
        les.pop();
    }
    while(!big.empty()) {
        p->next = big.front();
        p = p->next;
        big.pop();
    }
    p->next = nullptr;
    head = nh->next;
    delete nh;
    return head;
}

/*
Better solution
*/
static ListNode<int>* partition(ListNode<int>* head, int x) {
    ListNode<int> node1(0);
    ListNode<int> node2(0);
    ListNode<int>* p1 = &node1;
    ListNode<int>* p2 = &node2;
    while(head) {
        if(head->val < x) {
            p1 = p1->next = head;
        } else {
            p2 = p2->next = head;
        }
        head = head->next;
    }
    p2->next = nullptr;
    p1->next = node2.next;
    return node1.next;
}
