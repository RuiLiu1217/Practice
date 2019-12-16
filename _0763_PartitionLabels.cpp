#include "headers.hpp"
#include <unordered_set>
// 完全抄答案的，应该看一下这道题如何做，如何想
// https://www.youtube.com/watch?v=s-1W5FDJ0lw
static int getFirstPartition(std::string S) {
    if(S.size() == 0) {
        return 0;
    }
    if(S.size() == 1) {
        return 1;
    }

    std::unordered_set<char> mySet;
    mySet.insert(S[0]);
    int bar = 0;
    bool setChange = false;
    do {
        for(int i = S.size() - 1; i > bar; --i) {
            if(mySet.find(S[i]) != mySet.end()) {
                bar = i;
                break;
            }
        }
        setChange = false;
        for(int i = 0; i <= bar; ++i) {
            if(mySet.find(S[i]) == mySet.end()) {
                mySet.insert(S[i]);
                setChange = true;
            }
        }
    } while(setChange);
    return bar + 1;
}

std::vector<int> LeetCode::_0763_PartitionLabels::partitionLabels(std::string S) {
    std::vector<int> res;
    while (S.size()) {
        int fpl = getFirstPartition(S);
        S = S.substr(fpl, S.size() - fpl);
        res.push_back(fpl);
    }
    return res;
}
    