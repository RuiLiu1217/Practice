#include "LeetCode_GreedyAlgorithmProblems.hpp"
#include <functional>

// Google
int LC::_0011_ContainerWithMostWater::maxArea(std::vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int water = 0;
    while(i < j) {
        int h = std::min(height[i], height[j]);
        water = std::max(water, h * (j - i));
        while(i < j && height[i] <= h) { // Caution: the edge case it should be <= not < to guarantee that it can terminate
            ++i;
        }
        while(i < j && height[j] <= h) {
            --j;
        }
    }
    return water;
}


// Google
std::string LC::_0012_IntegerToRoman::intToRoman(int num) {
    int value[13] =       {1000,   900,   500,    400,   100,    90,    50,    40,   10,     9,    5,     4,   1};
    std::string str[13] = {"M",   "CM",   "D",   "CD",   "C",  "XC",   "L",  "XL",  "X",  "IX",  "V",  "IV",  "I"};
    std::string res;
    for(int i = 0; i < 13; ++i) {
        if(num >= value[i]) {
            int count = num / value[i];
            num %= value[i];
            for(int j = 0; j < count; ++j) {
                res += str[i];
            }
        }
    }
    return res;
}

/*
Google
Solution:
计数规则：
相同的数字连写，所表示的数等于这些数字相加得到的数，例如：III = 3
小的数字在大的数字右边，所表示的数等于这些数字相加得到的数，例如：VIII = 8
小的数字，限于（I、X和C）在大的数字左边，所表示的数等于大数减去小数所得的数，例如：IV = 4
正常使用时，连续的数字重复不得超过三次
在一个数的上面画横线，表示这个数扩大1000倍（本题只考虑3999以内的数，所以用不到这条规则）

其次，罗马数字转阿拉伯数字规则（仅限于3999以内）：

从前向后遍历罗马数字，如果某个数比前一个数小，则加上该数。反之，减去前一个数的两倍然后加上该数
*/
int LC::_0013_RomanToInteger::romainToInt(std::string s) {
    std::function<int(char)> char2Int = [](char c){
        switch(c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    };
    int pre = 0;
    int cur = char2Int(s[0]);
    int sum = 0;
    for(auto c : s) {
        int cur = char2Int(c);
        if(cur <= pre) {
            sum += cur;
        } else {
            sum += (cur - pre * 2);
        }
        pre = cur;
    }
    return sum;
}