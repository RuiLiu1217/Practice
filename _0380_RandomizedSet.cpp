#include "headers.hpp"

 /*  Copy from the solution
To have O(1) look up and delete time, we can use a combination 
of HashMap and a double LinkedList or something that can support 
the delete operation in O(1) time and we can facilitate our map 
to do it. We can use a vector as well instead of a double Linked 
List and I guess, it would be easy to implement and work on.

Map (O(1) look-up time) + vector (O(1) delete time)
map: value, index_of_vector
*/

/** Initialize your data structure here. */
LeetCode::_0380_RandomizedSet::_0380_RandomizedSet() {
    
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool LeetCode::_0380_RandomizedSet::insert(int val) {
    if(valueIndex.find(val) != valueIndex.end()) {
        return false;
    } else {
        values.push_back(val);
        valueIndex[val] = values.size() - 1;
        return true;
    }
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool LeetCode::_0380_RandomizedSet::remove(int val) {
    if(valueIndex.find(val) == valueIndex.end()) return false;
    int idx = valueIndex[val];  // Very interesting operation and high effective.
    int last = values.back();
    
    valueIndex[last] = idx;
    values[idx] = last;
    values.pop_back();
    valueIndex.erase(val);
    return true;
}

/** Get a random element from the set. */
int LeetCode::_0380_RandomizedSet::getRandom() {
    int n = rand() % values.size();
    return values[n];
}