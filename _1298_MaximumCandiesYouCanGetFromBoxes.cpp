#include "headers.hpp"

int LeetCode::_1298_MaximumCandiesYouCanGetFromBoxes::maxCandies(
    std::vector<int>& status, std::vector<int>& candies, 
    std::vector<std::vector<int>>& keys,
    std::vector<std::vector<int>>& containedBoxes, std::vector<int>& initialBoxes) 
{
    const int N = status.size(); // number of box array
    std::vector<bool> visited(N, false);
    int res = 0;
    std::queue<int> qBox;
    std::unordered_set<int> hasKey;
    for(int initB : initialBoxes) {
        qBox.push(initB);
    }

    bool hasOperation = false;
    while(!qBox.empty()) {
        const int N = qBox.size();
        for(int i = 0; i < N; ++i) {
            int cBox = qBox.front(); // get a box
            qBox.pop();

            if(status[cBox] == 0) { // Cannot open the current box
                if(hasKey.count(cBox)) {
                    hasOperation = true;
                    status[cBox] = 1;
                    visited[cBox] = true;
                    res += candies[cBox];
                    candies[cBox] = 0;

                    // Get all keys
                    for(int kk : keys[cBox]) {
                        hasKey.insert(kk);
                    }

                    for(int cont : containedBoxes[cBox]) {
                        if(!visited[cont]) {
                            qBox.push(cont);
                        }
                    }
                    hasKey.erase(cBox);
                } else {
                    qBox.push(cBox);
                    hasOperation = false;
                }
            } else {
                hasOperation = true;
                visited[cBox] = true;
                res += candies[cBox];
                candies[cBox] = 0;

                // get all keys
                for(int kk : keys[cBox]) {
                    hasKey.insert(kk);
                }

                for(int cont : containedBoxes[cBox]) {
                    if(!visited[cont]) {
                        qBox.push(cont);
                    }
                }
            }
        }
        if(!hasOperation) {
            break;
        }
    }
    return res;
}