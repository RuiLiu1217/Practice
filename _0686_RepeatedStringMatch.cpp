#include "headers.hpp"

int LeetCode::_0686_RepeatedStringMatch::repeatedStringMatch(std::string A, std::string B) {
    std::string res = A;
    for(int rep = 1; rep <= B.length() / A.length() + 2; rep++, res += A) {
        if(res.find(B) != std::string::npos) {
            return rep;
        }
    }
    return -1;
}

