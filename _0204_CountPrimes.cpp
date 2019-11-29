#include "headers.hpp"
#include <cmath>
#include <algorithm>
int LeetCode::_0204_CountPrimes::countPrimes(int n) {
    if(n <= 2) {
        return 0;
    }
    std::vector<bool> isPrime(n,true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 4; i < n; i = i + 2)
    {
        isPrime[i] = false;
    }

    int sqt = std::sqrt(n);
    for(int i = 3; i <= sqt; i = i + 2)
    {
        if(isPrime[i])
        {
            for(int j = i * i; j < n; j = j + i)
            {
                isPrime[j] = false;
            }
        }
    }
    return std::count(isPrime.begin(), isPrime.end(), true);   
}