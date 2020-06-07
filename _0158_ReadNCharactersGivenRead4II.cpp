#include "headers.hpp"

int LeetCode::_0158_ReadNCharactersGivenRead4II::read(char* buf, int n) {
    for(int i = 0; i < n ; ++i) {
        if(readPos == writePos) {
            writePos = read4(buf4);
            readPos = 0;
            if(writePos == 0) {
                return i;
            }
        }
        buf[i] = buf4[readPos++];
    }
    return n;
}