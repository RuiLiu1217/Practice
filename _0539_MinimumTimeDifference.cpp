#include "headers.hpp"
#include <sstream>

int LeetCode::_0539_MinimumTimeDifference::findMinDifference(std::vector<std::string>& timePoints) {
    std::vector<int> time;
    for(std::string& timePoint : timePoints) {
        std::istringstream iss(timePoint);
        int min = 0;
        std::string token;
        while(getline(iss, token, ':')) {
            min = min * 60 + std::stoi(token);
        }
        time.push_back(min);
    }
    std::sort(begin(time), end(time));
    int minT = INT_MAX;
    for(int i = 1; i < time.size(); ++i) {
        minT = std::min(minT, time[i] - time[i-1]);
    }
    minT = std::min(minT, time.front() + 24 * 60 - time.back());
    return minT;
}