#include "headers.hpp"
// 本身不难，但是懵住的一道题

void LeetCode::_0716_MaxStack::push(int x) {
    normal.push(x);
    int max = maximu.empty() ? x : maximu.top();
    maximu.push(max > x ? max : x);
}

int LeetCode::_0716_MaxStack::pop() {
    maximu.pop();
    int v = normal.top();
    normal.pop();
    return v;
}

int LeetCode::_0716_MaxStack::top() {
    return normal.top();
}

int LeetCode::_0716_MaxStack::peekMax() {
    return maximu.top();
}

int LeetCode::_0716_MaxStack::popMax() {
    int max = peekMax();
    std::stack<int> temp;
    while(top() != max) {
        temp.push(pop());
    }
    pop();
    while(!temp.empty()) {
        push(temp.top());
        temp.pop();
    }
    return max;
}
