#include "LeetCode_SlidingWindowProblems.hpp"
#include <vector>
#include <climits>
#include <algorithm>
#include <deque>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#define ALPHALEN 256

// Google
// HashTable + Sliding Window:
// Using a hashtable to remember the last index of every char, And keep tracking the starting
// point of a valid substring
int LC::_0003_LongestSubstringWithoutRepeatingCharacters::lengthOfLongestSubstring(std::string s) {
    const int l = s.length(); // length of the string
    int idx[256] = {INT_MIN}; // The vector based map of all chars, it records the last index of a char
    int res = 0;
    int start = 0;
    for(int i = 0; i < l; ++i) {
        if(idx[s[i]] != INT_MIN) { // We already see that character
            start = std::max(start, idx[s[i]] + 1); // update the new start postion of substring
        }
        res = std::max(res, i - start + 1);
        idx[s[i]] = i;
    }
    return res;
}


// Facebook
std::string LC::_0076_MinimumWindowSubstring::minWindow(std::string s, std::string t) {
    std::function<bool(const std::vector<int>&, std::vector<int>& )> isLargerOrEqual = [](const std::vector<int>& tMap, std::vector<int>& cur){
        for(int i = 0; i < 256; ++i) {
            if(tMap[i] > cur[i]) {
                return false;
            }
        }
        return true;
    };
    
    std::vector<int> tMap(256, 0);
    for(char c : t) {
        ++tMap[static_cast<int>(c)];
    }
    
    std::vector<int> curMap(256, 0);
    int tail = 0;
    int length = INT_MAX;
    std::string res;
    for(int i = 0; i < s.size(); ++i) {
        ++curMap[s[i]];
        while(isLargerOrEqual(tMap, curMap)) {
            if(i - tail + 1 < length) { // edge cases
                length = std::min(length, i - tail + 1);
                res = s.substr(tail, i - tail + 1);
            }
            
            --curMap[s[tail]];
            ++tail;
        }
    }
    return res;
}


// Facebook
int LC::_0340_LongestSubstringWithAtMostKDistintCharacters::lengthOfLongestSubstringKDistinct(std::string s, int k) {
    if(k <= 0) {
        return 0;
    }
    std::unordered_map<char, int> map;
    int endidx = 0;
    int length = 0;
    int startidx = 0;
    for(; startidx < s.size(); ++startidx) {
        ++map[s[startidx]];
        length = std::max(length, startidx - endidx);
        while(map.size() > k && endidx < startidx) {
            --map[s[endidx]];
            if(map[s[endidx]] == 0) {
                map.erase(s[endidx]);
            }
            ++endidx;
        }
    }
    return map.size() > k ? length : std::max(length, startidx - endidx);
}


std::vector<double> LC::_0480_SlidingWindowMedian::medianSlidingWindow(std::vector<int>& nums, int k) {
    return medianSlidingWindowMultiSetBased(nums, k);
}

std::vector<double> LC::_0480_SlidingWindowMedian::medianSlidingWindowMultiSetBased(std::vector<int>& nums, int k) {
    std::vector<double> ans;
    if(k == 0) {
        return ans;
    }
    
    std::vector<int> window(nums.begin(), nums.begin() + k - 1); // not the whole length, but less 1, 
    std::sort(begin(window), end(window));

    for(int i = k - 1; i < nums.size(); ++i) {
        window.push_back(nums[i]);
        auto it = std::prev(window.end(), 1); //
        
        // Implement the insertion sort
        auto const insertionPoint = std::upper_bound(window.begin(), it, *it); // Find the insertion point of the new added element *it.
        std::rotate(insertionPoint, it, it + 1); // insert the element. 
        
        // No matter even or odd are good to calculate the median.
        ans.push_back((static_cast<double>(window[k / 2]) + window[(k-1) / 2]) / 2);
        
        // complexity O(k)
        window.erase(std::lower_bound(window.begin(), window.end(), nums[i-k+1]));
    }

    return ans;
}


// Copy from the solution
std::vector<double> LC::_0480_SlidingWindowMedian::medianSlidingWindowInsertionSortBased(std::vector<int>& nums, int k) {
    std::vector<double> ans;
    if(k == 0) {
        return ans;
    }
    
    std::multiset<int> window(nums.begin(), nums.begin() + k);
    auto mid = std::next(window.begin(), (k-1) / 2); // get the iterator of the left mid, it also may have the right mid if the length k is even
    for(int i = k; i <= nums.size(); ++i) {
        ans.push_back((static_cast<double>(*mid) + *next(mid, (k+1) % 2)) / 2.0);
        
        if(i == nums.size()) break;
        
        window.insert(nums[i]);
        if(nums[i] < *mid) --mid; // after insert the last element, move mid
        if(nums[i-k] <= *mid) ++mid; // before deleting the heading element, move mid
        window.erase(window.lower_bound(nums[i-k]));
    }

    return ans;
}


std::vector<int> LC::_0239_SlidingWindowMaximum::maxSlidingWindow(std::vector<int>& nums, int k) {
    return maxSlidingWindow_Deque(nums, k);
}

std::vector<int> LC::_0239_SlidingWindowMaximum::maxSlidingWindow_Deque(std::vector<int>& nums, int k) {
    std::deque<int> index;
    std::vector<int> ans;
    
    for(int i = 0; i < nums.size(); ++i) {
        while(!index.empty() && nums[i] >= nums[index.back()]) {
            index.pop_back();
        }
        index.push_back(i);
        if(i - k + 1 >= 0) {
            ans.push_back(nums[index.front()]);
        }
        if(i - k + 1 >= index.front()) {
            index.pop_front();
        }
    }
    return ans;
}

std::vector<int> LC::_0239_SlidingWindowMaximum::maxSlidingWindow_MultiSet(std::vector<int>& nums, int k) {
    std::vector<int> ans;
    std::multiset<int> window;
    for(int i = 0; i < nums.size(); ++i) {
        window.insert(nums[i]);
        if(i - k + 1 >= 0) {
            ans.push_back(*window.rbegin());
            window.erase(window.equal_range(nums[i-k+1]).first);
        }
    }
    return ans;
}

std::vector<int> LC::_0239_SlidingWindowMaximum::maxSlidingWindow_Monotic(std::vector<int>& nums, int k) {
    class MonotonicQueue {
        public:
            void push(int e) {
                while(!data_.empty() && e > data_.back()) {
                    data_.pop_back();
                }
                data_.push_back(e);
            }
            
            void pop(){
                data_.pop_front();
            }
            
            int max() const {
                return data_.front();
            }
        private:
            std::deque<int> data_;
    };

    MonotonicQueue q;
    std::vector<int> ans;
    
    for(int i = 0; i < nums.size(); ++i) {
        q.push(nums[i]);
        if(i - k + 1 >= 0) {
            ans.push_back(q.max());
            if(nums[i-k+1] == q.max()) {
                q.pop();
            }
        }
    }
    return ans;
}


int LC::_0713_SubarrayProductLessThanK::numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    if(k <= 1) {
        return 0;
    }
    int res = 0;
    int prod = 1;
    int left = 0;
    for(int i = 0; i < nums.size(); ++i) {
        prod *= nums[i];
        while(left <= i && prod >= k) {
            prod /= nums[left];
            ++left;
        }
        res += i - left + 1;
    }
    return res;
}