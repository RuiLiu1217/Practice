#include "headers.hpp"

int LeetCode::_1167_MinimumCostToConnectSticks::connectSticks(std::vector<int>& sticks) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(int stick : sticks) {
        pq.push(stick);
    }
    int res = 0;
    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        res += (a + b);
        pq.push(a + b);
    }
    return res;       
}