#include "headers.hpp"

LeetCode::_0281_ZigzagIterator::_0281_ZigzagIterator(std::vector<int>& v1, std::vector<int>& v2) {
    N = 2;
    it.resize(N);
    it[0] = v1.begin();
    it[1] = v2.begin();
    endIt.resize(N);
    endIt[0] = v1.end();
    endIt[1] = v2.end();
    i = 0;
}

int LeetCode::_0281_ZigzagIterator::next() {
    if (hasNext()) {
        while(it[i] == endIt[i]) {
            i = (i + 1) % N;
        }
        int res = *it[i];
        ++it[i];
        i = (i + 1) % N;
        return res;
    }   
    return -1;
}

bool LeetCode::_0281_ZigzagIterator::hasNext() {
    for(int i = 0; i < it.size(); ++i) {
        if(it[i] != endIt[i]) {
            return true;
        }
    }
    return false;
}