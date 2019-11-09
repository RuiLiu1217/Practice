#include "headers.hpp"
// 抄答案的，需要认真从头再看尤其是list 的各种操作，需要熟悉。
LeetCode::_0146_LRUCache::_0146_LRUCache(int capacity) : mCapacity(capacity) {}

int LeetCode::_0146_LRUCache::get(int key) {
    const auto it = mMap.find(key);
    if(it == mMap.end()) {
        return -1;
    } else {
        // EXAMPLE: void splice (iterator position, list& x, iterator i);   // transfers only the element pointed by i from x into the container.
        // Transfers elements from x into the container, inserting them at position. 
        // This effectively inserts those elements into the container and removes them 
        // from x, altering the sizes of both containers. The operation does not involve 
        // the construction or destruction of any element. They are transferred, no 
        // matter whether x is an lvalue or an rvalue, or whether the value_type supports
        //  move-construction or not.
        mCache.splice(mCache.begin(), mCache, it->second);  // Move this key to the front of the list. 
        return it->second->second;
    }
}

void LeetCode::_0146_LRUCache::put(int key, int value) {
    const auto it = mMap.find(key);
    if(it != mMap.end(0)) {
        it->second->second = value;
        mCache.splice(mCache.begin(), mCache, it->second);
        return;
    }

    if(mCache.size() == mCapacity) {
        const auto& node = mCache.back();
        mMap.erase(node.first);
        mCache.pop_back();
    }
    mCache.emplace_front(key, value);
    mMap[key] = mCache.begin();
}