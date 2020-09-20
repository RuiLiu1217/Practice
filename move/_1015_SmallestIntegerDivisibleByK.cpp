#include "headers.hpp"
#include <unordered_set>
// Pure math problem. 
// Copy from the solution
int _1015_SmallestIntegerDivisibleByK::smallestRepunitDivByK(int K) {
    if(K % 2 == 0 || K % 5 == 0) {
        return -1;
    }
    int i = 0;
    int mod = 0;
    std::unordered_set<int> remainder;
    while(true) {
        mod = (mod * 10 + 1) % K;
        if(remainder.find(mod) != remainder.end()) {
            return -1;
        }
        ++i;
        if(mod == 0) {
            return i;
        }
        remainder.insert(mod);
    }
    return -1;
}