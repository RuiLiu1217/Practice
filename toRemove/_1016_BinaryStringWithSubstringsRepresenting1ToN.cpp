#include "headers.hpp"

bool LeetCode::_1016_BinaryStringWithSubstringsRepresenting1ToN::queryString(std::string S, int N) {
    for(int i = N; i > 0; --i) {
        std::string n = std::to_string(i);
        if(S.find(n) == std::string::npos) {
            return false;
        }
    }
    return true;
}