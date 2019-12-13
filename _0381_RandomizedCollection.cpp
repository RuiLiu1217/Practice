#include "headers.hpp"

/** Initialize your data structure here. */
LeetCode::_0381_RandomizedCollection::_0381_RandomizedCollection() {
}
    
/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
bool LeetCode::_0381_RandomizedCollection::insert(int val) {
    data.push_back(val);
    map[val].insert(data.size() - 1);
    return map[val].size() == 1;
}
    
/** Removes a value from the collection. Returns true if the collection contained the specified element. */
bool LeetCode::_0381_RandomizedCollection::remove(int val) {
    auto it = map.find(val);
    if (it != end(map)) {
        auto free_pos = *it->second.begin();
        it->second.erase(it->second.begin());
        data[free_pos] = data.back();
        map[data.back()].insert(free_pos);
        map[data.back()].erase(data.size() - 1);
        data.pop_back();
        if (it->second.size() == 0) map.erase(it);
        return true;            
    }
    return false;
    
}
    
/** Get a random element from the collection. */
int LeetCode::_0381_RandomizedCollection::getRandom() {
    return data[rand() % data.size()];
}