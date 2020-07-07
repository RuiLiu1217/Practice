#include "headers.hpp"

// Facebook

static std::string represent(int rep) {
    std::vector<std::string> singleNum2Str{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    std::vector<std::string> lessThan20Num2Str{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    std::vector<std::string> largerOrEqThan20Num2Str{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    std::string res;
    if(rep >= 100) {
        res += singleNum2Str[rep / 100] + " Hundred";
        rep %= 100;
        if(rep != 0) {
            res += " ";
        }
    }
    
    if(rep >= 20) {
        res += largerOrEqThan20Num2Str[rep/10];
        rep %= 10;
        if(rep != 0) {
            res += " ";
            res += singleNum2Str[rep];
        }
    } else if(rep >= 10) {
        res += lessThan20Num2Str[rep - 10];
    } else {
        if(rep != 0) {
            res += singleNum2Str[rep];
        }
        
    }
    return res;
}

std::string LeetCode::_0273_IntegerToEnglishWords::numberToWords(int num) {
    if(num == 0) {
        return "Zero";
    }
    int level = 0;
    std::stack<std::string> st;
    while(num) {
        int rep = num % 1000;
        std::string temp = represent(rep);
        st.push(temp);
        num /= 1000;            
    }
    std::string res;
    while(!st.empty()) {
        if(st.size() == 2) {
            if(st.top() != "") {
                res += (st.top() + " Thousand");
            }
            
        } else if(st.size() == 3) {
            if(st.top() != "") {
                res += (st.top() + " Million");
            }
        } else if(st.size() == 4) {
            if(st.top() != "") {
                res += (st.top() + " Billion");
            }
        } else {
            res += st.top();
        }
        st.pop();
        if(!st.empty() && st.top() != "") {
            res += " ";
        }
    }
    return res;
}