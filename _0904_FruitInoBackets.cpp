#include "headers.hpp"
#include <unordered_map>

int LeetCode::_0904_FruitInoBackets::totalFruit(std::vector<int>& tree) {
    std::unordered_map<int, int> map;
    int backIndex = 0;
    int maxLength = INT_MIN;
    for(int forwardIndex = 0; forwardIndex != tree.size(); ++forwardIndex) {
        if(map.size() == 2) {
            bool extraValueExist = true;
            if(map.size() == 2) {
                bool extraValueExist = true;
                for(auto& m : map) {
                    if(m.first == tree[forwardIndex]) {
                        extraValueExist = false;
                        break;
                    }
                }

                if(extraValueExist) {
                    while(backIndex <= forwardIndex) {
                        int key = tree[backIndex];
                        ++backIndex;
                        --map[key];
                        if(map[key] == 0) {
                            map.erase(key);
                            break;
                        }
                    }
                }
            }
            ++map[tree[forwardIndex]];
            maxLength = std::max(maxLength, forwardIndex - backIndex + 1);
        }
        return maxLength;
    }
}