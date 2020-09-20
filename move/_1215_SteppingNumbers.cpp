#include "headers.hpp"

std::vector<int> LeetCode::_1215_SteppingNumbers::countSteppingNumbers(int low, int high) {
    constexpr auto res = [](){
        std::array<int, 3600> v{0,1,2,3,4,5,6,7,8,9};
        v.back() = INT_MAX;
        for(int i = 1, p = 10; p < v.size() - 1; ++i) {
            int m1 = v[i] % 10 - 1;
            int m2 = v[i] % 10 + 1;
            if(m1 >= 0) {
                v[p++] = v[i] * 10 + m1;
            }
            if(m2 <= 9) {
                v[p++] = v[i] * 10 + m2;
            }
        }
        return v;
    }(); // Calcualte the result at the compile time.
     
    auto lb = std::lower_bound(begin(res), end(res), low);
    auto ub = std::upper_bound(begin(res), end(res), high);
    return std::vector<int>(lb, ub);

}