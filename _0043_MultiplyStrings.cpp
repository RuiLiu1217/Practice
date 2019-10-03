#include "headers.hpp"

std::string LeetCode::_0043_MultiplyStrings::multiply(std::string num1, std::string num2)
{
    const int L1 = num1.size();
    const int L2 = num2.size();
    if (num1 == "0" || num2 == "0")
    {
        return "0";
    }
    if (L2 < L1)
    {
        return multiply(num2, num1);
    }
    else
    {
        std::string res;
        for (int i = 0; i < L2; ++i)
        {
            std::string p = multiply(num1, num2, L2 - 1 - i);
            res = add(res, p);
        }
        return res;
    }
}

std::string LeetCode::_0043_MultiplyStrings::multiply(const std::string &num1, const std::string &num2, int idx)
{
    char c = num2[idx];
    int ic = c - '0';
    std::string res;
    int carry = 0;
    for (int i = num1.size() - 1; i >= 0; --i)
    {
        int curC = (num1[i] - '0');
        int prd = curC * ic + carry;
        if (prd >= 10)
        {
            carry = prd / 10;
            prd = prd % 10;
        }
        else
        {
            carry = 0;
        }
        res += (prd + '0');
    }
    if (carry)
    {
        res += (carry + '0');
        carry = 0;
    }

    std::reverse(res.begin(), res.end());
    for (int i = 0; i < (num2.size() - 1 - idx); ++i)
    {
        res += '0';
    }
    return res;
}

std::string add(std::string num1, std::string num2)
{
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    int minL = std::min(num1.size(), num2.size());
    int carry = 0;
    int i = 0;
    std::string res;
    for (i = 0; i < minL; ++i)
    {
        int v = ((num1[i] - '0') + (num2[i] - '0') + carry);
        if (v >= 10)
        {
            carry = 1;
            v -= 10;
        }
        else
        {
            carry = 0;
        }
        res += ('0' + v);
    }
    if (minL < num1.size())
    {
        for (; i < num1.size(); ++i)
        {
            int v = (carry + (num1[i] - '0'));
            if (v >= 10)
            {
                carry = 1;
                v -= 10;
            }
            else
            {
                carry = 0;
            }
            res += ('0' + v);
        }
        if (carry)
        {
            res += (carry + '0');
        }
    }
    else if (minL < num2.size())
    {
        for (; i < num2.size(); ++i)
        {
            int v = (carry + (num2[i] - '0'));
            if (v >= 10)
            {
                carry = 1;
                v -= 10;
            }
            else
            {
                carry = 0;
            }
            res += ('0' + v);
        }
        if (carry)
        {
            res += (carry + '0');
        }
    }
    else if (carry != 0)
    {
        res += (carry + '0');
    }

    std::reverse(res.begin(), res.end());
    return res;
}