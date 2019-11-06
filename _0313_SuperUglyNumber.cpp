#include "headers.hpp"

int LeetCode::_0313_SuperUglyNumber::nthSuperUglyNumber(int n, std::vector<int>& primes) {
    std::vector<int> idx(primes.size(), 0);
    std::vector<int> res(1,1);
    while(res.size() < n)
    {
        res.push_back(_min(res, idx, primes));            
    }
    return res.back();
}

int LeetCode::_0313_SuperUglyNumber::_min(std::vector<int>& res, std::vector<int>& idx, std::vector<int>& primes) {
    int minV = res[idx[0]] * primes[0];
    for(int i = 1; i < primes.size(); ++i)
    {
        if(res[idx[i]] * primes[i] < minV)
        {
            minV = res[idx[i]] * primes[i];
        }
    }
    for(int i = 0; i < primes.size(); ++i)
    {
        if(minV == res[idx[i]] * primes[i])
        {
            ++idx[i];
        }
    }
    return minV;
}