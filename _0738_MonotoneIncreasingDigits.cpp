#include "headers.hpp"

// 突然懵住，一道很简单的题目，从后往前扫描，遇到比前面一个数字小的，就记下来marker，然后之前那个数字减1，
// 再从marker开始扫描，之后的数字都变成'9'
int LeetCode::_0738_MonotoneIncreasingDigits::monotoneIncreasingDigits(int N) {
    std::string n_str = std::to_string(N);        
    int marker = n_str.size();
    for(int i = n_str.size()-1; i > 0; i--) {
        if(n_str[i] < n_str[i-1]) {
            marker = i;
            n_str[i-1] = n_str[i-1]-1;
        }
    }
    
    for(int i = marker; i < n_str.size(); i ++) n_str[i] = '9';
    
    return std::stoi(n_str);
}