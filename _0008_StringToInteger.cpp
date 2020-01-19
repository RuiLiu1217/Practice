#include "headers.hpp"

int LeetCode::_0008_StringToInteger::myAtoi(std::string str) {
    int i = 0;
    int num = 0;
    while(i < str.length() && str[i] == ' ') {
        ++i;
    }
    
    bool isNegative = false;
    if(str[i] == '-' || str[i] == '+')
    {
        isNegative = str[i] == '-'; // Whether it is a negative value
        i++;
    }
    while(i < str.length() && str[i] == '0') {
        ++i;
    }
    while(i < str.length() && (str[i] - '0') <= 9 && (str[i] - '0') >= 0) {
        // This is very tricky!! See just before overflow, judge whether the last digit is larger than 7
        if((num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > 7)))
            return isNegative ? INT_MIN :INT_MAX;
        num = ((num * 10) + (str[i] - '0'));
        ++i;
    }
    
    return isNegative ? (num * -1) : num; 
}