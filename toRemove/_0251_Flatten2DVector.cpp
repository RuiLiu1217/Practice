#include "headers.hpp"

LeetCode::_0251_Flatten2DVector::_0251_Flatten2DVector(std::vector<std::vector<int>>& v) {
    i = v.begin();
    iEnd = v.end();
}

int LeetCode::_0251_Flatten2DVector::next() {
    if(hasNext()) {
        return (*i)[j++];
    }
    return -1;
}

bool LeetCode::_0251_Flatten2DVector::hasNext() {
    while(i != iEnd && j == (*i).size()) {
        ++i;
        j = 0;
    }
    return i != iEnd;
}
