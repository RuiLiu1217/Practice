#ifndef LEETCODE_UNIONFINDPROBLEMS_HPP
#define LEETCODE_UNIONFINDPROBLEMS_HPP

#include <vector>
#include <string>
#include "HeaderFiles.hpp"
namespace LC {
    /*
    Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.
    For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, 
    but "star" is not similar to "tars", "rats", or "arts".
    Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that 
    "tars" and "arts" are in the same group even though they are not similar. Formally, each group is such that a 
    word is in the group if and only if it is similar to at least one other word in the group.

    We are given a list A of strings.  Every string in A is an anagram of every other string in A. 
    How many groups are there?

    Input: A = ["tars","rats","arts","star"]
    Output: 2

    Constraints:
    1 <= A.length <= 2000
    1 <= A[i].length <= 1000
    A.length * A[i].length <= 20000
    All words in A consist of lowercase letters only.
    All words in A have the same length and are anagrams of each other.
    The judging time limit has been increased for this question.
    */
    class _0839_SimilarStringGroups {
    public:
        int numSimilarGroups(std::vector<std::string>& A);
    private:
        bool areSimilar(const std::string& a, const std::string& b);
    };

    /*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = 
[a, b] indicates 2 indices(0-indexed) of the string. You can swap the characters at any pair of 
indices in the given pairs any number of times.
Return the lexicographically smallest string that s can be changed to after using the swaps.

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
*/
class _1202_SmallestStringWithSwaps {
public:
    class UnionFind {
public:
    std::vector<int> parent;
    UnionFind(int k) {
        parent.resize(k);
        for(int i = 0; i < k; ++i) {
            parent[i] = i;
        }
    }
    int find(int m) {
        if(parent[m] != m) {
            parent[m] = find(parent[m]);
        }
        return parent[m];
    }
    void Union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) {
            return;
        }
        parent[pa] = pb; // for simple, can be optimized
    }
};
    std::string smallestStringWithSwaps(std::string s, std::vector<std::vector<int>>& pairs) {
        UnionFind uf(s.size());
        for(auto& pair : pairs) {
            uf.Union(pair[0], pair[1]);
        }
        
        std::vector<int> parent(s.size());
        for(int i = 0; i < s.size(); ++i) {
            parent[i] = uf.find(i);
        }
        std::unordered_map<int, std::priority_queue<char, std::vector<char>, std::greater<char>>> map;
        
        for(int i = 0; i < s.size(); ++i) {
            int pnt = uf.find(i);
            map[pnt].push(s[i]);
        }
        
        for(int i = 0; i < s.size(); ++i) {
            int pnt = uf.find(i);
            auto& pair = map[pnt];
            s[i] = pair.top();
            pair.pop();
        }
        return s;
    }
};

/*
1579. Remove Max Number of Edges to Keep Graph Fully Traversable
Alice and Bob have an undirected graph of n nodes and 3 types of edges:

Type 1: Can be traversed by Alice only.
Type 2: Can be traversed by Bob only.
Type 3: Can by traversed by both Alice and Bob.
Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional 
edge of type typei between nodes ui and vi, find the maximum number of edges 
you can remove so that after removing the edges, the graph can still be fully 
traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob 
if starting from any node, they can reach all other nodes.
Return the maximum number of edges you can remove, or return -1 if it's impossible 
for the graph to be fully traversed by Alice and Bob. 

Example 1:
Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.

Example 2:
Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.

Example 3:
Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.

Constraints:

1 <= n <= 10^5
1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
edges[i].length == 3
1 <= edges[i][0] <= 3
1 <= edges[i][1] < edges[i][2] <= n
All tuples (typei, ui, vi) are distinct.
*/
class _1579_RemoveMaxNumberOfEdgesToKeepGraphFullyTraversable {
public:
    int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges);
};
}

#endif