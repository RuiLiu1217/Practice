#include "headers.hpp"
#include <stack>
#include <algorithm>
std::vector<int> LeetCode::_0735_AsteroidCollision::asteroidCollision(std::vector<int>& asteroids) {
    std::stack<int> st;
    int i = 0; 
    
    for(int i = 0; i < asteroids.size(); ++i) {
        if(st.empty()) {
            st.push(asteroids[i]);
            continue;
        }
        if (!st.empty() && st.top() < 0) {
            st.push(asteroids[i]);
            continue;
        } else {
            if(asteroids[i] > 0) {
                st.push(asteroids[i]);
                continue;
            } else {
                while(!st.empty() && st.top() > 0 && st.top() < -asteroids[i]) {
                    st.pop();
                }
                if(!st.empty()) {
                    if(st.top() + asteroids[i] == 0) {  
                        st.pop();
                    } else if(st.top() < 0) {
                        st.push(asteroids[i]);
                    }
                } else {
                    st.push(asteroids[i]);
                }
            }
        }            
    }
    std::vector<int> res;
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();            
    }
    std::reverse(res.begin(), res.end());
    return res;
}
