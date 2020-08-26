#include "headers.hpp"

bool _1497_CheckIfArraypairsAreDivisibleByK::canArrange(std::vector<int>& arr, int k) {
    std::vector<int> mods(k, 0);
    for (int x : arr){
        ++mods[(x % k + k) % k];  
    }
    for (int i = 1; i < k; ++i) {
        if (mods[i] != mods[k - i]) return false;
    }
    
    return mods[0] % 2 == 0;
}