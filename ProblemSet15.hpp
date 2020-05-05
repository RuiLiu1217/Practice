#ifndef PROBLEM_SET15_HPP
#define PROBLEM_SET15_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"

// Problem 1401 - 1500
namespace LeetCode {
    /*
    You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from 
    cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

    It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

    Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
    Output: "Sao Paulo" 
    Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist 
    of: "London" -> "New York" -> "Lima" -> "Sao Paulo".


    Input: paths = [["B","C"],["D","B"],["C","A"]]
    Output: "A"
    Explanation: All possible trips are: 
    "D" -> "B" -> "C" -> "A". 
    "B" -> "C" -> "A". 
    "C" -> "A". 
    "A". 
    Clearly the destination city is "A".

    Input: paths = [["A","Z"]]
    Output: "Z"
    

    Constraints:
        1 <= paths.length <= 100
            paths[i].length == 2
        1 <= cityAi.length, cityBi.length <= 10
            cityAi != cityBi
        All strings consist of lowercase and uppercase English letters and the space character.
    */
    class _1436_DestinationCity {
        public:
            std::string destCity(std::vector<std::vector<std::string>>& paths);
    };

    /*
    Given an array nums of 0s and 1s and an integer k, return True if all 1's are at least k places away from each other, otherwise return False.
    Input: nums = [1,0,0,0,1,0,0,1], k = 2
    Output: true
    Explanation: Each of the 1s are at least 2 places away from each other.
    
    Input: nums = [1,0,0,1,0,1], k = 2
    Output: false
    Explanation: The second 1 and third 1 are only one apart from each other.
    
    Input: nums = [1,1,1,1,1], k = 0
    Output: true
    
    Input: nums = [0,1,0,1], k = 1
    Output: true
    
    Constraints:
        1 <= nums.length <= 10^5
        0 <= k <= nums.length
        nums[i] is 0 or 1
    */
    class _1437_CheckIf1sAreAtLeastLengthKPlacesAway {
        public:
            bool kLengthApart(std::vector<int>& nums, int k);
    };
}
#endif
