#include "headers.hpp"

std::string LintCode::_1535_ToLowerCase::toLowerCase(std::string &str) {
     for(char& c : str) {
        if(c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
    return str;
}