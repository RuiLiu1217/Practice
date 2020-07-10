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



LC::ListNode *LC::_0061_RotateList::rotateRight(ListNode* head, int k)
{
    if (!head) {
        return nullptr;
    }

    ListNode *p = head;
    int count = 1;
    while (p->next != nullptr) {
        p = p->next;
        ++count;
    }

    k = k % count;
    if (k == 0) {
        return head;
    }

    ListNode *q = head;
    while (k) {
        q = q->next;
        --k;
    }
    ListNode *t = head;
    while (q->next != nullptr) {
        t = t->next;
        q = q->next;
    }
    ListNode *nh = t->next;
    t->next = nullptr;
    q->next = head;

    return nh;
}


LC::ListNode*  LC::_0082_RemoveDuplicatesFromSortedListII::deleteDuplicates(ListNode* head) {
    ListNode* nh = new ListNode(INT_MAX);
    nh->next = head;
    ListNode* p = nh;
    while(p->next && p->next->next) {
        if(p->next->val == p->next->next->val) { // Found duplicates
            ListNode* q = p->next->next;
            while(q && q->val == p->next->val) {
                q = q->next;
            }
            // Delete duplicate lists
            ListNode* t = p->next;
            while(t != q) {
                ListNode* m = t;
                t = t->next;
                delete m;
            }
            
            // re-point to the next position
            p->next = q;
        } else {
            p = p->next;
        }
    }
    head = nh->next;
    delete nh;
    return head;
}


LC::ListNode* LC::_0083_RemoveDuplicatesFromSortedList::deleteDuplicates(ListNode* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* h = head;
    ListNode* t = h->next;
    while(t != nullptr) {
        if(h->val == t-> val) {
            h->next = t->next;
            t = h->next;
            continue;
        } else {
            h = t;
            t = t->next;
        }
    }
    return head;
}


LC::ListNode* LC::_0086_PartitionList::partition(ListNode* head, int x) {
    ListNode node1(0);
    ListNode node2(0);
    ListNode* p1 = &node1;
    ListNode* p2 = &node2;
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


LC::ListNode* LC::_0092_ReverseLinkedListII::reverseBetween(ListNode* head, int m, int n) {
    if(m == n) {
        return head;
    }
    ListNode* newHead = new ListNode(-1);
    newHead->next = head;
    ListNode* pre = newHead;
    ListNode* cur = head;
    ListNode* nex = cur->next;
    ListNode* startNode = nullptr;
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