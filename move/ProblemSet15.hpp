#ifndef PROBLEM_SET15_HPP
#define PROBLEM_SET15_HPP

#include <vector>
#include <string>
#include <stack>
#include <queue>

#include "Tree.hpp"
#include "LinkList.hpp"

// Problem 1501 - 1600
namespace LeetCode {
    /*
    Given an array of integers nums.
    A pair (i,j) is called good if nums[i] == nums[j] and i < j.
    Return the number of good pairs.
    
    Input: nums = [1,2,3,1,1,3]
    Output: 4
    Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
    
    Input: nums = [1,1,1,1]
    Output: 6
    Explanation: Each pair in the array are good.
    
    Input: nums = [1,2,3]
    Output: 0
    
    Constraints:
        1 <= nums.length <= 100
        1 <= nums[i] <= 100
    */
    class _1512_NumberOfGoodPairs {
    public:
        int numIdenticalPairs(std::vector<int>& nums);
    };

    /*
    Given a directed acyclic graph, with n vertices numbered from 0 to 
    n-1, and an array edges where edges[i] = [fromi, toi] represents a 
    directed edge from node fromi to node toi.
    Find the smallest set of vertices from which all nodes in the graph 
    are reachable. It's guaranteed that a unique solution exists.
    Notice that you can return the vertices in any order.
    
    Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
    Output: [0,3]
    Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].
    
    Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
    Output: [0,2,3]
    Explanation: Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. Also any of these vertices can reach nodes 1 and 4.
    
    Constraints:

    2 <= n <= 10^5
    1 <= edges.length <= min(10^5, n * (n - 1) / 2)
    edges[i].length == 2
    0 <= fromi, toi < n
    All pairs (fromi, toi) are distinct.
    */
    class _1557_MinimumNumberOfVerticesToReachAllNodes {
    public:
        std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>>& edges);
    };
    
}