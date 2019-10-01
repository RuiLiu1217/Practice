#include "headers.hpp"

std::string LeetCode::_0006_ZigZagConversion::convert(std::string s, int numRows)
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