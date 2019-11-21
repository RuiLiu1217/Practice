#include "headers.hpp"

std::string LeetCode::_1017_ConvertToBase_Negative2::baseNeg2(int N) {
    std::string res;
    while(N) {
        res = std::to_string(N & 1) + res;
        N = -(N>>1);
    }
    return res.empty() ? "0" : res;
}