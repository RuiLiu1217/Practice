#include "headers.hpp"
// Tag: single linked list operation
// TODO: recursive is harder to understand


ListNode<int>* reverseList(ListNode<int>* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    // (x[head])-->(o)-->(.)-->(.)-->(*)
    ListNode<int>* newHead = reverseList(head->next);
    // (*[newHead])-->(.)-->(.)-->(o)<--(x[head])
    head->next->next = head; // (*[newHead])-->(.)-->(.)-->(o)<-->(x[head])
    head->next = nullptr;// (*[newHead])-->(.)-->(.)-->(o)-->(x[head])
    return newHead;
}