#include "headers.hpp"

LeetCode::_0155_MinStack::_0155_MinStack() {}

void LeetCode::_0155_MinStack::push(int x) {
    mainStack.push(x);
    if(minStack.empty() || minStack.top() >= x) {
        minStack.push(x);
    }
}

void LeetCode::_0155_MinStack::pop() {
    if(!mainStack.empty()) {
        int topV = mainStack.top();
        mainStack.pop();
        if(!minStack.empty() && minStack.top() == topV) {
            minStack.pop();
        }
    }
}

int LeetCode::_0155_MinStack::top() {
    if(!mainStack.empty()) {
        return mainStack.top();
    } else {
        return -1;
    }

}

int LeetCode::_0155_MinStack::getMin() {
    if(!minStack.empty()) {
        return minStack.top();
    } else {
        return -1;
    }
}