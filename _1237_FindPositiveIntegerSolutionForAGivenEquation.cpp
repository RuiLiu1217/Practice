#include "headers.hpp"
class CustomFunction {
public:
    int f(int x, int y){
        return 0;
    }
};

std::vector<std::vector<int>> findSolution(CustomFunction& customfunction, int z) {
    int x = 1;
    int y = 1000;
    std::vector<std::vector<int>> res;
    while(y > 0 && x <= 1000) {
        if(customfunction.f(x,y) > z) {
            --y;
        } else if(customfunction.f(x,y) < z){
            ++x;
        } else {
            res.push_back({x,y});
            ++x;
            --y;
        }
    }
    return res;
}