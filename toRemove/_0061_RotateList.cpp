#include "headers.hpp"

ListNode<int> *LeetCode::_0061_RotateList::rotateRight(ListNode<int> *head, int k)
{
    if (!head)
    {
        return nullptr;
    }
    ListNode<int> *p = head;
    int count = 1;
    while (p->next != nullptr)
    {
        p = p->next;
        ++count;
    }
    k = k % count;
    if (k == 0)
    {
        return head;
    }

    ListNode<int> *q = head;
    while (k)
    {
        q = q->next;
        --k;
    }
    ListNode<int> *t = head;
    while (q->next != nullptr)
    {
        t = t->next;
        q = q->next;
    }
    ListNode<int> *nh = t->next;
    t->next = nullptr;
    q->next = head;

    return nh;
}