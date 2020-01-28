#include "headers.hpp"

int LeetCode::_1323_Maximum69Number::maximum69Number(int num) {
    std::string a = std::to_string(num);
    size_t i = a.find('6');
    if(i < a.size()) {
        a[i] = '9';
    }
    return std::stoi(a);
}