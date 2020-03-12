#include "headers.hpp"

LeetCode::_0604_DesignCompressedStringIterator::_0604_DesignCompressedStringIterator(std::string compressedString) {
    std::string curChar;
    std::string numStr;
    for(int i = 0; i < compressedString.size(); ++i) {
        if(compressedString[i] >= '0' && compressedString[i] <= '9') {
            numStr += compressedString[i];
        } else {
            if(!curChar.empty()) {
                q.push({curChar, std::stoi(numStr)});
                numStr.clear();
                curChar.clear();
            }
            curChar += compressedString[i];
        }
    }
    if(!numStr.empty()) {
        q.push({curChar, std::stoi(numStr)});
        numStr.clear();
        curChar.clear();
    }
}

char LeetCode::_0604_DesignCompressedStringIterator::next() {
    if(hasNext()) {
        char ret = q.front().first[0];
        if(q.front().second == 1) {
            q.pop();
        } else {
            --q.front().second;
        }
        return ret;
    } else {
        return ' ';
    }
}

bool LeetCode::_0604_DesignCompressedStringIterator::hasNext() {
    return !q.empty();
}