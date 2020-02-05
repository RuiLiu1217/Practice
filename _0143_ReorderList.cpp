#include "headers.hpp"
#include <vector>
// 我的做法是“拆开重新组装”
void LeetCode::_0143_ReorderList::reorderList(ListNode<int>* head) {
    std::vector<ListNode<int>*> vec;
    ListNode<int>* p = head;
    while(p) {
        vec.push_back(p);
        p = p->next;
    }

    int i = 0;
    int j = vec.size() - 1;
    int count = 1;
    ListNode<int>* nh = new ListNode<int>(-1);
    ListNode<int>* q = nh;
    while(i < j) {
        if(count % 2) {
            q->next = vec[i];
            ++i;
        } else {
            q->next = vec[j];
            --j;
        }
        q = q->next;
        ++count;
    }
    if(i == j) {
        q->next = vec[i];
        q = q->next;
    }
    q->next = nullptr;
    head = nh->next;
    delete nh;
    nh = nullptr;
}


/*
recursive solution but very slow:

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* p = head;
        while(p && p->next) {
            p->next = reverse(p->next);
            p = p->next;
        }
    }
    
    ListNode* reverse(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        if(head->next == nullptr) {
            return head;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nex = cur->next;
        while(cur) {
            cur->next = pre;
            pre = cur;
            cur = nex;
            if(nex) {
                
                nex = nex->next;
            }
        }
        return pre;
        
    }
};
*/