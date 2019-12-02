#include "headers.hpp"

ListNode<int>* LeetCode::_0002_AddTwoNumbers::addTwoNumbers(ListNode<int>* l1, ListNode<int>* l2) {
    int wi = 0;
    return AddTwoNodes(l1, l2, wi);
    
}

ListNode<int>* LeetCode::_0002_AddTwoNumbers::AddTwoNodes(ListNode<int>* l1, ListNode<int>* l2, int wi)
{
    if(l1 == NULL && l2 == NULL && wi == 0)
    {
        return NULL;
    }
    else if(l1 == NULL && l2 == NULL && wi == 1)
    {
        ListNode<int>* res = new ListNode<int>(wi);
        res->next = NULL;
        return res;
    }
    else if(l1 != NULL && l2 == NULL)
    {
        ListNode<int>* res = new ListNode<int>(l1->val + wi);
        if(res->val < 10)
        {
            res->next = AddTwoNodes(l1->next, NULL, 0);
            return res;
        }
        else{
            res->val -= 10;
            res->next = AddTwoNodes(l1->next, NULL, 1);
            return res;
        }
    }
    else if(l1 == NULL && l2 != NULL)
    {
        ListNode<int>* res = new ListNode<int>(l2->val + wi);            
        if(res->val < 10)
        {
            res->next = AddTwoNodes(NULL, l2->next, 0);
            return res;
        }
        else{
            res->val -= 10;
            res->next = AddTwoNodes(NULL, l2->next, 1);
            return res;
        }
    }
    else
    {
        ListNode<int>* res = new ListNode<int>(l1->val + l2->val + wi);
        if(res->val < 10)
        {
            res->next = AddTwoNodes(l1->next, l2->next, 0);
            return res;
        }
        else
        {
            res->val -= 10;
            res->next = AddTwoNodes(l1->next, l2->next, 1);
            return res;
        }
        
    }
}