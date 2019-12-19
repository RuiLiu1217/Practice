#include "headers.hpp"
#include <algorithm>

// 这道题反而有点懵，抄答案得来的

std::vector<int> diStringMatch(std::string S) {
    // For example -> IIDDIDI, left = 3; right = 3;
    int left = std::count(S.begin(), S.end(), 'D'), right = left;
    std::vector<int> res = {left}; // [3]

    // NOTE: How the for loop works in this case
    // [3] 
    // I
    // [3, 4] 
    // I
    // [3, 4, 5]
    // D
    // [3, 4, 5, 2]
    // D
    // [3, 4, 5, 2, 1]
    // I
    // [3, 4, 5, 2, 1, 6]
    // D
    // [3, 4, 5, 2, 1, 6, 0]
    // I
    // [3, 4, 5, 2, 1, 6, 0, 7]
    for (char c : S)
        res.push_back(c == 'I' ? ++right : --left); 
    return res;
}