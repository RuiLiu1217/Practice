#include "headers.hpp"

_0155_MinStack::_0155_MinStack() {}
void _0155_MinStack::push(int x) {
    mainStack.push(x);
    if(minStack.empty() || minStack.top() >= x) {
        minStack.push(x);
    }
}

void _0155_MinStack::pop() {
    if(!mainStack.empty()) {
        int topV = mainStack.top();
        mainStack.pop();
        if(!minStack.empty() && minStack.top() == topV) {
            minStack.pop();
        }
    }
}

int _0155_MinStack::top() {
    if(!mainStack.empty()) {
        return mainStack.top();
    }
}

int _0155_MinStack::getMin() {
    if(!minStack.empty()) {
        return minStack.top();
    }
}