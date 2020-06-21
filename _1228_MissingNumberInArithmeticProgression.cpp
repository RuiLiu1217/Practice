#include "headers.hpp"

int LeetCode::_1228_MissingNumberInArithmeticProgression::missingNumber(std::vector<int>& arr) {
    int first = arr[0], last = arr[0], sum = 0, n = arr.size();
    for (int a : arr) {
        first = min(first, a);
        last = max(last, a);
        sum += a;
    }
    return (first + last) * (n + 1) / 2 - sum;
}