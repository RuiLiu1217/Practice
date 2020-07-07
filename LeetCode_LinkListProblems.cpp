#include "LeetCode_LinkListProblems.hpp"
#include <vector>
#include <queue>
#include <climits>
#include <functional>
LC::ListNode* LC::_0002_AddTwoNumbers::addTwoNumbers(LC::ListNode* l1, LC::ListNode* l2) {
    return addImpl(l1, l2, 0);
}

LC::ListNode* LC::_0002_AddTwoNumbers::addImpl(LC::ListNode* l1, LC::ListNode* l2, int carry) {
    if(l1 == nullptr && l2 == nullptr) {
        if(carry == 0) {
            return nullptr;
        } else {
            return new LC::ListNode(1);
        }
    } else {
        int va = l1 ? l1->val : 0;
        int vb = l2 ? l2->val : 0;
        int v = va + vb + carry;
        
        if(v >= 10) {
            v -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        LC::ListNode* t = new LC::ListNode(v);
        t->next = addImpl(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, carry);
        return t;
    }
    
}


LC::ListNode* LC::_0019_RemoveNthNodeFromEndToList::removeNthFromEnd(ListNode* head, int n) {
    ListNode* plst = head;
    for(int i = 0; i != n; ++i) {
        plst = plst->next;
    }
    if(plst == nullptr) {
        plst = head->next;
        delete head;
        return plst;
    }
    ListNode* pnxt = head;
    while(plst->next) {
        plst = plst->next;
        pnxt = pnxt->next;
    }
    ListNode* toRe = pnxt->next;
    pnxt->next = pnxt->next->next;
    delete toRe;
    return head;
}



/*
Google
*/
LC::ListNode* LC::_0021_MergeTwoSortedLists::mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr && l2 == nullptr) {
        return nullptr;
    } else if(l1 == nullptr && l2 != nullptr) {
        return l2;
    } else if(l2 == nullptr && l1 != nullptr) {
        return l1;
    } else {
        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
}



/*
Google, Facebook
*/
LC::ListNode* LC::_0023_MergeKeSortedLists::mergeKLists(std::vector<ListNode*>& lists) {
    p = new ListNode(-1);
    fh = p;
    auto Comp = [](ListNode* a, ListNode* b) { return a->val > b->val;};
    
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(Comp)> pq{Comp};
    for(int i = 0; i < lists.size(); ++i) {
        if(lists[i]) {
            pq.push(lists[i]);
        }
    }
    while(!pq.empty()) {
        ListNode* n = pq.top();
        pq.pop();
        if(n->next) {
            pq.push(n->next);
        }
        n->next = nullptr;
        p->next = n;
        p = p->next;
    }
    return fh->next;
}


// swap nodes in pairs
LC::ListNode* LC::_0024_SwapNodesInPairs::swapPairs(ListNode* head) {
    if(!head) {
        return nullptr;
    }
    ListNode* cur = head;
    ListNode* nxt = cur->next;
    if(!nxt) {
        return cur;
    }
    ListNode* res = swapPairs(cur->next->next);
    nxt->next = cur;
    cur->next = res;
    head = nxt;
    return head;
}




LC::ListNode* LC::_0025_ReverseNodeInKGroup::reverseGroup(ListNode* head, int k) {
    // Create a fake head;
    ListNode* fh = new ListNode(INT_MIN);
    fh->next = head;

    int t = k;
    ListNode* p = fh;
    while(t && p) {
        p = p->next;
        --t;
    }

    std::function<LC::ListNode*(LC::ListNode*)> reverse = [](LC::ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nex = head->next;
        while(cur) {
            cur->next = pre;
            pre = cur;
            cur = nex;
            if(nex) {
                nex = nex->next;
            }
        }
        return pre;
    };

    if(t != 0 || p == nullptr) {
        return head; // not sufficient for one group, just directly return;
    } else {
        ListNode* pn = p->next;
        p->next = nullptr;
        fh->next = nullptr; delete fh;
        ListNode* newHead = reverse(head);
        ListNode* tmp = newHead;
        while(tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = reverseGroup(pn, k);
        return newHead;
    }
}
