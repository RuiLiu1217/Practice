#include "headers.hpp"

std::vector<std::string> LeetCode::_0412_FizzBuzz::fizzBuzz(int n) {
    std::vector<std::string> res;
    for(int i = 1; i <= n; ++i) {
        if(!(i%15)) {
            res.push_back("FizzBuzz");
            continue;
        }
        if(!(i%3)) {
            res.push_back("Fizz");
            continue;
        }
        if(!(i%5)) {
            res.push_back("Buzz");
            continue;
        }
        res.push_back(std::to_string(i));
    }
    return res;
}