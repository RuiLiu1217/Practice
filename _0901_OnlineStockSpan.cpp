#include "headers.hpp"

// Copy from the solution
int LeetCode::_0901_OnlineStockSpan::next(int price) {
    int span = 1;
    while(!st.empty() && st.top().first <= price) {
        span += st.top().second;
        st.pop();
    }
    st.push({price, span});
    return st.top().second;
}