#include "headers.hpp"

std::vector<int> LeetCode::_0089_GrayCode::grayCode(int n) {
    if(n == 0) {
        return {0};
    }
    if(n == 1) {
        return {0, 1};
    } else {
        std::vector<int> last = grayCode(n-1);
        std::vector<int> flip(last.rbegin(), last.rend());
        for(int i = 0; i < flip.size(); ++i) {
            flip[i] |= 1<<(n-1);
            last.push_back(flip[i]);
        }
        return last;
    }
}
