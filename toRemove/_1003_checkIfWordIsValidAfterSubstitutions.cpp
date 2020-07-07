#include "headers.hpp"

bool LeetCode::_1003_CheckIfWordIsValidAfterSubstitutions::isValid(std::string S) {
    if(S.length() % 3) {
        return false;
    }
    if(S[0] != 'a' || S[S.length()-1] != 'c') {
        return false;
    }
    int countA = 0;
    int countB = 0;
    int countC = 0;
    std::stack<char> st;
    for(int i = 0; i < S.length(); ++i) {
        if(S[i] == 'a') {
            ++countA;
            st.push(S[i]);
        } else if(S[i] == 'b') {
            ++countB;
            st.push(S[i]);
        } else if(S[i] == 'c') {
            ++countC;
            if(st.size() < 2) {
                return false;
            }
            if(st.top() != 'b') {
                return false;
            } else {
                st.pop();
                if(st.top() != 'a') {
                    return false;
                } else {
                    st.pop();
                }
            }
        } else {
            return false;
        }
        if((countA < countB) || (countB < countC)) {
            return false;
        }
    } 
    if((countA != countB) || (countB != countC)) {
        return false;
    }
    return st.empty();
}