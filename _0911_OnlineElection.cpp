#include "headers.hpp"

LeetCode::_0911_OnlineElection::_0911_OnlineElection(std::vector<int>& persons, std::vector<int>& times) {
    std::vector<int> tickets(5000, 0);
    int maxV = 0;
    int leadPerson = -1;
    
    Map.insert(std::make_pair(0, -1)); // 在0时刻之前，领先的候选人是 -1;
    int kk = -1;
    for(int i = 0; i < persons.size(); ++i) {
        ++tickets[persons[i]];
        if(tickets[persons[i]] >= maxV) {
            if(leadPerson != persons[i]) {
                Map.insert(std::make_pair(times[i], leadPerson)); // 在times[i]之前，领先者是 leadPerson
                leadPerson = persons[i];
            } 
            maxV = tickets[persons[i]];
            kk = i;
        }
    }
    Map.insert(std::make_pair(INT_MAX, persons[kk])); // Finally, persons[kk] wins
}

int LeetCode::_0911_OnlineElection::q(int t) {
    auto it = Map.upper_bound(t);
    return it->second;
}