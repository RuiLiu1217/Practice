#include "headers.hpp"

// Challenge : How to solve it with only one "if" ? 有的面试官会要求你能不能只用一个 if 语句来完成这个题，这是一个参考。突破点在于：那我可以用 while 呀~ (好贱！)
std::vector<std::string> LintCode::_0009_FizzBuzz::fizzBuzz(int n) {
    // write your code here
    std::vector<std::string> res;
    for(int i = 1; i <= n; ++i) {
        if( (i%3 == 0) && (i%5 == 0)) {
            res.push_back("fizz buzz");
        } else if ((i%3==0)) {
            res.push_back("fizz");
        } else if ((i%5==0)) {
            res.push_back("buzz");
        } else {
            res.push_back(std::to_string(i));
        }
    }
    return res;
}