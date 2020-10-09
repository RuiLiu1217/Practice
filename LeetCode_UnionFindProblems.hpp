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

}

#endif