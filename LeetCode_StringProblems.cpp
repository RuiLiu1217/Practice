#include "LeetCode_StringProblems.hpp"
#include <functional>
#include <climits>
std::string LC::_0005_LongestPalindromicSubstring::longestPalidrome(std::string s) {
    if(s.size() == 0) {
        return "";
    }
    int start = 0;
    int end = 0;

    std::function<int(int, int)> expandAroundCent = [&](int i, int j){
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
        }
        return j - i - 1; // not + 1 because both i and j are one step outside the palindromic.
    };

    for(int i = 0; i < s.size(); ++i) {
        int len1 = expandAroundCent(i, i); // Expand with one core center;
        int len2 = expandAroundCent(i, i + 1); // Expand with neighbor same;
        int l = std::max(len1, len2);
        if(l > end - start) {
            // The difficulty is how to calculate the start and end 
            // index according to the given center index
            start = i - (l - 1) / 2; 
            end = i + l / 2;
        }
    }
    return s.substr(start, end - start + 1);
}



std::string LC::_0006_ZigZagConversion::convert(std::string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    int period = numRows + numRows - 2; // The big loop will be 0 1 2 3 2 1 | 0 1 2 3 2 1 ...
    int k = period / 2;                 // k = P / 2;
    std::vector<std::string> subRows(numRows, "");
    int rowIdx = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        rowIdx = k - std::abs(k - i % period);   // rowIdx = k - |k - i % P|;
        subRows[rowIdx] += s[i];
    }
    std::string res;
    for (auto su : subRows)
    {
        res += su;
    }
    return res;
}


/*
Google
This is not a good problem, like handing writing different edge cases
*/
int LC::_0008_StringToInteger::myAtoi(std::string str) {
    int i = 0;
    int num = 0;
    // Remove extra spaces
    while(i < str.length() && str[i] == ' ') {
        ++i;
    }
    // whether it is a negative number
    bool isNegative = false;
    if(str[i] == '-' || str[i] == '+') {
        isNegative = str[i] == '-'; // Whether it is a negative value
        i++;
    }

    // remove heading 0s
    while(i < str.length() && str[i] == '0') {
        ++i;
    }
    // Start converting
    while(i < str.length() && (str[i] - '0') <= 9 && (str[i] - '0') >= 0) {
        // !! This is very tricky!! See just before overflow, judge whether the last digit is larger than 7
        if((num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > 7)))
            return isNegative ? INT_MIN :INT_MAX;
        num = ((num * 10) + (str[i] - '0'));
        ++i;
    }
    
    return isNegative ? (num * -1) : num; 
}