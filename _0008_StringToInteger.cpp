#include "headers.hpp"

int LeetCode::_0008_StringToInteger::myAtoi(std::string str) {
    int i,num = 0;

    for(i = 0; (str[i] == ' ') && i < str.length(); i++){ // Jump extra spaces

    }

    bool isNegative = false;
    if(str[i] == '-' || str[i] == '+')
    {
        isNegative = str[i] == '-'; // Whether it is a negative value
        i++;
    }

    for(;(str[i] -'0') == 0;i++) {  // Jump front zeros

    }

    for(; (str[i] - '0') <= 9 && (str[i] - '0') >= 0 && i < str.length(); i++)
    { 
        if((num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > 7))) // This is very tricky!! See just before overflow, judge whether the last digit is larger than 7
            return isNegative ? INT_MIN :INT_MAX;

        num = ((num * 10) + (str[i] - '0'));
    }
    return isNegative ? (num * -1) : num; 
}