#include "headers.hpp"

bool LeetCode::_0359_LoggerRateLimiter::shouldPrintMessage(int timestamp, std::string message) {
    if(map.find(message) == map.end()) {
        map[message] = timestamp;
        return true;
    } else {
        int oldTimeStamp = map[message];
        if(timestamp - oldTimeStamp < 10) {
            return false;
        } else {
            map[message] = timestamp;
            return true;
        }
    }
}