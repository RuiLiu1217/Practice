#include "headers.hpp"

class LeetCode::_0981_TimeBasedKeyValueStore::TimeMap {
    std::unordered_map<std::string, std::map<int, std::string>> m;
public:
    TimeMap(){}
    void set(std::string key, std::string value, int timestamp) {
        m[key].insert({timestamp, value});
    }
    std::string get(std::string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it)->second;
    }
};