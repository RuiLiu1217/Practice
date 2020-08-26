#include "headers.hpp"
#include <algorithm>
 int numRescueBoats(std::vector<int>& people, int limit) {
    std::sort(begin(people), end(people));
    int l = 0;
    int r = people.size() - 1;
    int count = 0;
    while(l < r) {
        if(people[l] + people[r] <= limit) {
            ++count;
            ++l;
            --r;
        } else {
            ++count;
            --r;
        }
    }
    if(l == r) {
        ++count;
    }
    return count;
}