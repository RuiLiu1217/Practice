#include "headers.hpp"
#include <stack>
bool LeetCode::_0946_ValidateStackSequences::_0946_ValidateStackSequences::validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
    const int N = popped.size();
    std::stack<int> st;
    int j = 0;
    for(int x : pushed) {
        st.push(x);
        while(!st.empty() && j < N && st.top() == popped[j]) {
            st.pop();
            ++j;
        }
    }
    return j == N;
}
