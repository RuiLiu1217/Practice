#include "headers.hpp"
#include <algorithm>
#include <random>
#include <ctime>

// There is better solution without sorting. (TODO)
int LeetCode::_0169_MajorityElement::majorityElement(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

/*
Hash Table
Count the number of appearances for each distinct number
in nums, once we see a number appear more than n / 2 times, 
it is the majority element.
*/
int majorityElement1(std::vector<int>& nums) {
    std::unordered_map<int, int> counter;
    for (int num : nums) {
        if (++counter[num] > nums.size() / 2) {
            return num;
        }
    }
    return 0;
}

/*
Sorting
Since the majority element appears more than n / 2 times, 
the n / 2-th element in the sorted nums must be the majority 
element. In this case, a partial sort by nth_element is enough.
*/
int majorityElement2(std::vector<int>& nums) {
    std::nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
}

/*
Randomization
Pick an element randomly and check whether it is the majority one.
*/
int majorityElement3(std::vector<int>& nums) {
    int n = nums.size(), candidate, counter;
    std::srand(unsigned(std::time(NULL)));
    while (true) {
        candidate = nums[rand() % n], counter = 0;
        for (int num : nums) {
            if (num == candidate) {
                counter++;
            }
        }
        if (counter > n / 2) {
            break;
        }
    }
    return candidate;
}

/*
Divide and Conquer
Recursively find the majority in the two halves of nums and combine the results. The base case is that the majority element of a single-element array is just that element.
*/
int majority(std::vector<int>& nums, int l, int r) {
    if (l == r) {
        return nums[l];
    }
    int m = l + (r - l) / 2, lm = majority(nums, l, m), rm = majority(nums, m + 1, r);
    if (lm == rm) {
        return lm;
    }
    return count(nums.begin() + l, nums.begin() + r + 1, lm) > count(nums.begin() + l, nums.begin() + r + 1, rm) ? lm : rm;
}

int majorityElement5(std::vector<int>& nums) {
    return majority(nums, 0, nums.size() - 1);
}

/*
Moore Voting Algorithm
*/
int majorityElement4(std::vector<int>& nums) {
    int counter = 0, majority;
    for (int num : nums) {
        if (!counter) {
            majority = num;
        }
        counter += num == majority ? 1 : -1;
    }
    return majority;
}

/*
Bit Manipulation
The bits in the majority are just the majority bits of all numbers.
*/
int majorityElement(std::vector<int>& nums) {
    int majority = 0;
    for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
        int bits = 0;
        for (int num : nums) {
            if (num & mask) {
                bits++;
            }
        }
        if (bits > nums.size() / 2) {
            majority |= mask;
        }
    }
    return majority;
}