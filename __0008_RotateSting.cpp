#include "headers.hpp"
#include <string>

void LintCode::_0008_RotateString::rotateString(std::string &str, int offset) {
    // write your code here
    int strSize = str.size(); 
    if(str.empty()) {
        return;
    }
    offset = offset % strSize;
    for(int i = 0, j = strSize - offset - 1; j > i; ++i, --j) {
        char a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
    
    for(int i = strSize - offset, j = strSize - 1; j > i; ++i, --j) {
        char a = str[i];
        str[i] = str[j];
        str[j] = a;   
    }
    
    for(int i = 0, j = strSize - 1 ; j > i ; ++i, --j) {
        char a = str[i];
        str[i] = str[j];
        str[j] = a;   
    }
}