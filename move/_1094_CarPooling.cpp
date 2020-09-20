#include "headers.hpp"

bool LeetCode::_1094_CarPooling::carPooling(std::vector<std::vector<int>>& trips, int capacity) {
    std::vector<int> peoples(1001, 0);
    for(auto t : trips) {
        peoples[t[1]] += t[0];
        peoples[t[2]] -= t[0];
    }
    
    int currentPeople = 0;
    for(int i = 0; i < peoples.size(); ++i) {
        currentPeople += peoples[i];
        if(currentPeople > capacity) {
            return false;
        }
    }
    return true;
}