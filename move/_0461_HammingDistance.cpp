#include "headers.hpp"

int LeetCode::_0461_HammingDistance::hammingDistance(int x, int y) {
    int val = x ^ y;
    int dis = 0;
    while(val) {
        dis += (val & 1);
        val >>= 1;
    }
    return dis;
}