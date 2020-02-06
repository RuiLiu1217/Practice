#include "headers.hpp"

std::vector<int> LeetCode::_1317_ConvertIntegerToTheSumOfTwoNonZeroIntegers::getNoZeroIntegers(int n) {
    int a = 1;
    int b = n - a;
    while(true) {
        b = n - a;
        auto sa = std::to_string(a);
        auto sb = std::to_string(b);
        if((sa.find("0") == std::string::npos) && (sb.find("0") == std::string::npos)) {
            return {a,b};
        }
        ++a;
    }
    return {};
}