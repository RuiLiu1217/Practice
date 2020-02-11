#include "headers.hpp"

void LeetCode::_0225_ImplementStackUsingQueues::push(int x) {
    int len = nums.size();
    nums.push(x);
    for(int i = 0; i != len; ++i) { // keep it last in first out structure
        nums.push(nums.front());
        nums.pop();
    }
}

// Removes the element on top of the stack;
int LeetCode::_0225_ImplementStackUsingQueues::pop() {
    int c = nums.front();
    nums.pop();
    return c;
}

// get the top element
int LeetCode::_0225_ImplementStackUsingQueues::top() {
    return nums.front();
}

// Return whether the stack is empty
bool LeetCode::_0225_ImplementStackUsingQueues::empty() {
    return nums.empty();
}