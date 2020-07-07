#include "headers.hpp"

bool LeetCode::_0342_PowerOfFour::isPowerOfFour(int num)
{
    if (num <= 0)
    {
        return false;
    }
    const int mask = 0x55555555;
    if ((num & (num - 1)) == 0)
    {
        if ((num | mask) == num)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}