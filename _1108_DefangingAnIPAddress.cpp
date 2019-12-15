#include "headers.hpp"

std::string LeetCode::_1108_DefangingAnIPAddress::defangIPaddr(std::string address) {
    std::string res;
    for(char c : address) {
        if(c == '.') {
            res += "[.]";
        } else {
            res += c;
        }
    }
    return res;
}
