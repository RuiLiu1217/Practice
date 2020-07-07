#include "headers.hpp"
#include <unordered_map>
int LeetCode::_1090_LargestValuesFromLabels::largestValsFromLabels(std::vector<int>& values, std::vector<int>& labels, int num_wanted, int use_limit) {
    std::unordered_map<int, int> labelUsed;
    using Pair = std::pair<int, int>; // value, label
    auto Comp = [](Pair a, Pair b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    };
    std::priority_queue<Pair, std::vector<Pair>, decltype(Comp)> valuelabel{Comp};
    for(int i = 0; i < values.size(); ++i) {
        valuelabel.push({values[i], labels[i]});
    }
    int n = 0;
    int res = 0;
    while(n < num_wanted && !valuelabel.empty()) {
        auto t = valuelabel.top();
        valuelabel.pop();
        if(labelUsed.find(t.second) == labelUsed.end()) {
            labelUsed[t.second] = 0;
        }
        if(labelUsed[t.second] < use_limit) {
            ++labelUsed[t.second];
            res += t.first;
            ++n;
        }    
    }
    return res;
}