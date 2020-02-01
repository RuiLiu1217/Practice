#include "headers.hpp"

static std::vector<int> operator-(std::vector<int> a, std::vector<int> b) {
    std::vector<int> res(2, 0);
    res[0] = a[0] - b[0];
    res[1] = a[1] - b[1];
    return res;
}

static int operator*(std::vector<int> a, std::vector<int> b) {
    return a[0] * b[0] + a[1] * b[1];
}

static int lenSqu(std::vector<int> a) {
    return a[0] * a[0] + a[1] * a[1];
}

static bool operator==(std::vector<int> a, std::vector<int> b) {
    return (a[0] == b[0] && a[1] == b[1]);
}

bool LeetCode::_0593_ValidSquare::validSquare(std::vector<int>& p1, std::vector<int>& p2, std::vector<int>& p3,
    std::vector<int>& p4) 
{
    if(p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
        return false;
    }
    std::vector<int> v1 = p2 - p1;
    std::vector<int> v2 = p3 - p1;
    std::vector<int> v3 = p4 - p1;
    if(v1 * v2 == 0) {
        if(lenSqu(v1) != lenSqu(v2)) {
            return false;
        }
        std::vector<int> w1 = p4 - p2;
        std::vector<int> w2 = p4 - p3;
        if(w1 * w2 != 0) {
            return false;
        }
        return true;
    } else if(v1 * v3 == 0) {
        if(lenSqu(v1) != lenSqu(v3)) {
            return false;
        }
        std::vector<int> w1 = p3 - p2;
        std::vector<int> w2 = p3 - p4;
        if(w1 * w2 != 0) {
            return false;
        }
        return true;
    } else if(v2 * v3 == 0) {
        if(lenSqu(v3) != lenSqu(v2)) {
            return false;
        }
        std::vector<int> w1 = p3 - p2;
        std::vector<int> w2 = p2 - p4;
        if(w1 * w2 != 0) {
            return false;
        }
        return true;
    } else {
        return false;
    }
}