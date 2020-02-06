#include "headers.hpp"
#include <unordered_map>

// 抄答案的，需要进一步分析，理解
std::string LeetCode::_0166_FractionToRecurringDecimal::fractionToDecimal(int n, int d) {
    if(n == 0) {
        return "0";
    }
    std::string res;
    // determine the sign
    if(n < 0 ^ d < 0) {
        res += "-";
    }
    n = std::abs(n);
    d = std::abs(d);

    // appending the integral part
    res += std::to_string(n / d);

    // in case no fractional part
    if(n % d == 0) {
        return res;
    }

    res += ".";

    std::unordered_map<int, int> map;

    //Simulate the division process
    for(int r = n % d; r; r %= d) {
        // meet a known remainder
        // so we reach the end of the repeating part
        if(map.count(r) > 0) {
            res.insert(map[r], 1, '(');
            res += ')';
            break;
        }

        // The remainder is first seen
        // remember the current position for it
        map[r] = res.size();
        r *= 10;

        // append the quotient digit
        res += std::to_string(r / d);
    }
    return res;
}