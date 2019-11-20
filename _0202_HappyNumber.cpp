#include "headers.hpp"
#include <cmath>
#include <algorithm>
#include <unordered_set>
int LeetCode::_0202_HappyNumber::gat(int n) {
    int sum = 0;
    while(n > 0)
    {
        sum += std::pow(n % 10, 2);
        n = n / 10;
    }
    return sum;
}

bool LeetCode::_0202_HappyNumber::isHappy(int n) {
    int newN = gat(n);
    std::unordered_set<int> loops;
    if(newN == 1)
    {
        return true;
    }
    while(loops.find(newN) == loops.end())
    {
        loops.insert(newN);
        newN = gat(newN);
        if(newN == 1)
        {
            return true;
        }
    }
    return false;        
}
