#include "headers.hpp"

ListNode<int>* LeetCode::_0092_ReverseLinkedListII::reverseBetween(ListNode<int>* head, int m, int n) {
    if(m == n) {
        return head;
    }
    ListNode<int>* newHead = new ListNode<int>(-1);
    newHead->next = head;
    ListNode<int>* pre = newHead;
    ListNode<int>* cur = head;
    ListNode<int>* nex = cur->next;
    ListNode<int>* startNode = nullptr;
    int count = 0;
    // Reverse
    while(cur) {
        if(count + 1 == m) {
            startNode = pre;
        }
        if(count + 1 >= m && count + 1 <= n) {
            cur->next = pre;
        }
        if(count + 1 == n) {
            startNode->next->next = nex;
            startNode->next = cur;
            break;
        }
        pre = cur;
        cur = nex;
        nex = nex->next;
        ++count;
    }
    head = newHead->next;
    newHead->next = nullptr;
    delete newHead;
    return head;
}