#include "headers.hpp"

int LeetCode::_1358_NumberOfSubstringsContainingAllThreeCharacters::numberOfSubstrings(std::string s) {
    int endPoint = 0;
    int res = 0;
    const int N = s.size();
    for(int frontPoint = 0; frontPoint < s.size(); ++frontPoint) {
        ++count[s[frontPoint] - 'a'];
        while(contains3()) {
            res += N - frontPoint;
            --count[s[endPoint++] - 'a'];
        }
    }
    return res;
}