#include "headers.hpp"

std::string LeetCode::_0984_StringWithoutAAAOrBBB::strWithout3a3b(int A, int B) {
    if(A == 0 && B == 0) {
        return "";
    } else if(A == 0 && B != 0) {
        std::string res;
        for(int i = 0; i < B; ++i) {
            res += "b";
        }
        return res;
    } else if(A != 0 && B == 0) {
        std::string res;
        for(int i = 0; i < A; ++i) {
            res += "a";
        }
        return res;
    } else {
        if(A > B) {
            return "aab" + strWithout3a3b(A-2, B-1);
        } else if(A < B) {
            return "bba" + strWithout3a3b(A-1, B-2);
        } else {
            return "ab" + strWithout3a3b(A-1, B-1);
        }
    }
}