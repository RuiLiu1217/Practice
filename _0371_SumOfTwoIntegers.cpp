#include "headers.hpp"

int LeetCode::_0371_SumOfTwoIntegers::getSum(int a, int b) {
    const int max_bits = 32;
    auto carry = 0;
    int _sum = 0;
    for (int i = 0; i < max_bits; ++i)
    {
        auto a_bit = (a >> i) & 1;
        auto b_bit = (b >> i) & 1;
        auto tmp = (a_bit ^ b_bit ^ carry) << i;
        _sum |= tmp;
        carry = ((a_bit & b_bit) ||
                    (a_bit & carry) ||
                    (b_bit & carry))
                    ? 1
                    : 0;
    }
    return _sum;
}