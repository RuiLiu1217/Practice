#include "headers.hpp"
#include <algorithm>

// Facebook 

int LeetCode::_0621_TaskScheduler::leastInterval(std::vector<char>& tasks, int n) {
    std::vector<int> count(26,0);
    for(const char task : tasks) {
        ++count[task - 'A'];
    }
    int maxCount = *std::max_element(begin(count), end(count));
    size_t ans = (maxCount - 1) * (n + 1);
    ans += std::count_if(begin(count), end(count), [maxCount](int c){
        return c == maxCount;
    });
    return std::max(ans, tasks.size());
}