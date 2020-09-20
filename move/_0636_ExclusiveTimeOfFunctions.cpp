#include "headers.hpp"

// Facebook
std::vector<int> LeetCode::_0636_ExclusiveTimeOfFunctions::exclusiveTime(int n, std::vector<std::string>& logs) {
    std::vector<int> ans(n, 0);
    char action[6];
    int fid;
    int curr;
    int prev;
    std::stack<int> s;
    for(const std::string& log : logs) {
        sscanf(log.c_str(), "%d:%[a-z]:%d", &fid, action, &curr);
        if(action[0] == 's') { // start
            if(!s.empty()) {
                ans[s.top()] += curr - prev;
            }
            s.push(fid);
            prev = curr;
        } else {
            ans[s.top()] += curr - prev + 1;
            s.pop();
            prev = curr + 1;
        }
    }
    return ans;
}