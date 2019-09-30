#include "headers.hpp"

ListNode<int>* LeetCode::_0019_RemoveNthNodeFromEndToList::removeNthFromEnd(ListNode<int>* head, int n) {
    if(!head->next && n == 1) {
        delete head;
        head = nullptr;
        return head;
    }
    ListNode<int>* front = head;
    while(n)
    {
        front = front->next;
        n--;
    }
    if(front == nullptr)
    {
        ListNode<int>* p = head;
        head = head->next;
        delete p;
        return head;
    }
    ListNode<int>* del = head;
    while(front->next){
        del = del->next;
        front = front->next;
    }
    ListNode<int>* p = del->next;
    del->next = p->next;
    delete p;
    return head;
}