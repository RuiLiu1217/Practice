#include "headers.hpp"
// Google
 static int absPathLength(std::stack<std::string>& a) {
    std::stack<std::string> b;
    int length = 0;
    const int n = a.size();
    while(!a.empty()) {
        length += a.top().size();
        b.push(a.top());
        a.pop();
    }
    while(!b.empty()) {
        a.push(b.top());
        b.pop();
    }
    return length + n - 1;
}

int LeetCode::_0388_LongestAbsoluteFilePath::lengthLongestPath(std::string input) {
    std::string temp;
    int layer = 0;
    std::stack<std::string> st;
    int length = 0;
    input += '\n';
    for(auto c : input) {
        if(c == '\n') {
            if(!temp.empty()) {
                while(!st.empty() && st.size() > layer) {
                    st.pop();
                }

                if(layer == st.size()) {
                    st.push(temp);
                    layer = 0;
                }

                if(temp.find(".") != std::string::npos) {
                    length = std::max(length, absPathLength(st));
                }
                temp.clear();
            }
        } else if(c == '\t') {
            ++layer;
        } else {
            temp += c;
        }
    }
    if (!st.empty() && st.top().find(".") != std::string::npos) {
        length = std::max(length, absPathLength(st));
    }
    return length;
}