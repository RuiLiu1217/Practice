#include "headers.hpp"

static  bool isEvenNumberOfDigits(int num) {
    int count = 0;
    while(num) {
        ++count;
        num /= 10;
    }
    return count % 2 == 0;
}

int LeetCode::_1295_FindNumbersWithEvenNumberOfDigits::findNumber(std::vector<int>& nums) {
    int count = 0;
    for(auto n : nums) {
        if(isEvenNumberOfDigits(n)) {
            ++count;
        }
    }
    return count;
}