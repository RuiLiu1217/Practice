#include "headers.hpp"
// !!! Copy from solution
int LeetCode::_0227_BasicCalculatorII::calculate(std::string s) {
    const int n = s.size();
    std::stack<int> st;
    char op = '+';
    long res = 0;
    int num = 0;

    for(int i = 0; i < n; ++i) {
        if(s[i] >= '0' && s[i] <= '9') { // if it is a digit
            num = num * 10 + (s[i] - '0');
        }
        if((s[i] < '0' && s[i] != ' ') || i == n - 1) {
            if(op == '+') {
                st.push(num);
            }
            if(op == '-') {
                st.push(-num);
            }
            if(op == '*' || op == '/') {
                int tmp = (op == '*') ? st.top() * num : st.top() / num;
                st.pop();
                st.push(tmp);
            }
            op = s[i];
            num = 0;
        }
    }

    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}