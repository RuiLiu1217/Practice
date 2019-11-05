#include "headers.hpp"
// 做过，但是一时想不起来了，需要再看几遍. 这道题跟 cloneGraph 很像
LeetCode::_0138_CopyListWithRandomPointer::Node* LeetCode::_0138_CopyListWithRandomPointer::copyRandomList(LeetCode::_0138_CopyListWithRandomPointer::Node* head) {
    if(head == nullptr) {
        return nullptr;
    }
    if(visit.find(head) != visit.end()) {
        return visit[head];
    }
    LeetCode::_0138_CopyListWithRandomPointer::Node* res = new LeetCode::_0138_CopyListWithRandomPointer::Node();
    res->val = head->val;
    res->next = copyRandomList(head->next);   // 跟 cloneGraph 一个意思只不过没那么多而已;
    res->random = copyRandomList(head->random);
    visit[head] = res;

    return res;
}