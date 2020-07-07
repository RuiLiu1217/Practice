#include "headers.hpp"
// The sqrt of N is just to get the solution of f(x) = x^2 - N when y = 0;
// f'(x) = 2x, therefore the slope of f(x) when x = x_n is 2x_n;
// Therefore the slope line is f(x) - (x_n^2 - N) = 2 x_n (x - x_n);, let f(x) = 0,
// we have:  x_n+1 = (x_n + N / x_n) / 2
int LeetCode::_0069_SqrtX::mySqrt(int x) {
    if(x == 0) {
        return 0;
    }
    double g = x / 2.0;
    int lasRes = g;
    int curRes = lasRes + 1;
    while(curRes != lasRes) {
        lasRes = curRes;
        g = (g + x / g) * 0.5;
        curRes = g;
    }
    return curRes;
}
