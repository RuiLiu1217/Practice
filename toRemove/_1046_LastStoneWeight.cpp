#include "headers.hpp"
#include <queue>
int LeetCode::_1046_LastStoneWeight::lastStoneWeight(std::vector<int>& stones) {
    std::priority_queue<int> pq;
    for(auto s : stones) {
        pq.push(s);
    }
    while(pq.size() >= 2) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        if(a == b) {
            continue;
        } else {
            pq.push(a - b);
        }
    }
    if(pq.empty()) {
        return 0;
    }
    return pq.top();
}