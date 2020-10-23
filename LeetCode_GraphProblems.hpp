#ifndef LEETCODE_GRAPHPROBLEM_HPP
#define LEETCODE_GRAPHPROBLEM_HPP
#include "HeaderFiles.hpp"

namespace LC {
/*
Facebook
There is a new alien language which uses the latin alphabet. However, 
the order among letters are unknown to you. You receive a list of 
non-empty words from the dictionary, where words are sorted lexicographically 
by the rules of this new language. Derive the order of letters in 
this language.

Input:
["wrt", "wrf", "er", "ett", "rftt"]
Output: "wertf"

Input:
["z", "x"]
Output: "zx"

Input:
["z", "x", "z"] 
Output: "" 

Explanation: The order is invalid, so return "".
Note:

You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b 
in the given dictionary. If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.
*/
class _0269_AlienDictionary {
public:
    // ! There are several weird edge cases
    std::string alienOrder(std::vector<std::string>& words) {
        if(words.size() == 0) {
            return "";
        }
        if(words.size() == 1) {
            std::sort(begin(words[0]), end(words[0]));
            return words[0]; // This is weird
        }
        std::unordered_map<char, std::unordered_set<char>> adjList;
        std::unordered_set<char> charSet;
        for(int i = 0; i < words.size() - 1; ++i) {
            std::string sWord = words[i];
            std::string bWord = words[i+1];
            int idx = 0;
            while(idx < std::min(sWord.size(), bWord.size()) &&
                 sWord[idx] == bWord[idx]) {
                ++idx;
            }
            if(idx < std::min(sWord.size(), bWord.size())) {
                adjList[sWord[idx]].insert(bWord[idx]);
            }
            if(idx == bWord.size() && idx < sWord.size()) {
                return "";
            }
            for(int t = 0; t < sWord.size(); ++t) {
                charSet.insert(sWord[t]);
            }
            for(int t = 0; t < bWord.size(); ++t) {
                charSet.insert(bWord[t]);
            }
        }
        
        std::unordered_map<char, bool> visited;
        std::unordered_map<char, int> inDegree;
        for(char c : charSet) {
            visited[c] = false;
            if (inDegree.find(c) == inDegree.end()) {
                inDegree[c] = 0;
            }            
            auto toNode = adjList[c];
            for(auto t : toNode) {
                ++inDegree[t];
            }
        }
        std::queue<char> q;
        for(auto& ind : inDegree) {
            if(ind.second == 0) {
                q.push(ind.first);
            }
        }
        
        std::string res;
        while(!q.empty()) {
            const int N = q.size();
            for(int i = 0; i < N; ++i) {
                char node = q.front();
                q.pop();
                visited[node] = true;
                res += node;
                
                auto adjNodes = adjList[node];
                for(auto& adjN : adjNodes) {
                    --inDegree[adjN];
                    if(!visited[adjN] && inDegree[adjN] == 0) {
                        q.push(adjN);
                    }
                }
            }
        }
        int remain = 0;
        for(auto& ind : inDegree) {
            remain += ind.second;
        }
        return remain == 0 ? res : "";
    }

};


    // BFS, DFS
    // In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.
    // If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.
    // Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal 
    // node. More specifically, there exists a natural number K so that for any choice of where to walk, 
    // we must have stopped at a terminal node in less than K steps.

    // Which nodes are eventually safe?  Return them as an array in sorted order. The directed graph has N 
    // nodes with labels 0, 1, ..., N-1, where N is the length of graph. The graph is given in the following 
    // form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.
    
    // Example:
    // Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    // Output: [2,4,5,6]
    // Here is a diagram of the above graph.
    
    // Note: graph will have length at most 10000. The number of edges in the graph will not exceed 32000. 
    // Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].
    class _0802_FindEventualSafeStates {
    public:
        std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph);
        std::vector<int> eventualSafeNodes_BFS(std::vector<std::vector<int>>& graph);
        std::vector<int> eventualSafeNodes_DFS(std::vector<std::vector<int>>& graph);
    private:
        bool helper(std::vector<std::vector<int>>& graph, int cur, std::vector<int>& color);
    };


    /*
        Facebook
        !!! Copy from the solution, but TLE!!!

        Tag: DFS, Graph
        Given a reference of a node in a connected undirected graph, return a deep copy 
        (clone) of the graph. Each node in the graph contains a val (int) and a list 
        (List[Node]) of its neighbors.

        Input:
        {"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":
        [{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],
        "val":2},{"$ref":"4"}],"val":1}

        Explanation:
        Node 1's value is 1, and it has two neighbors: Node 2 and 4.
        Node 2's value is 2, and it has two neighbors: Node 1 and 3.
        Node 3's value is 3, and it has two neighbors: Node 2 and 4.
        Node 4's value is 4, and it has two neighbors: Node 1 and 3.
        

        Note:

        The number of nodes will be between 1 and 100.
        The undirected graph is a simple graph, which means no repeated edges and no self-loops in the graph.
        Since the graph is undirected, if node p has node q as neighbor, then node q must have node p as neighbor too.
        You must return the copy of the given node as a reference to the cloned graph.
    */
    class _0133_CloneGraph {        
    public:
        class Node {
            public:
                int val;
                std::vector<Node*> neighbors;
                Node(){}
                Node(int _val, std::vector<Node*> _neighbors): val(_val), neighbors(_neighbors) {}
        };
        Node* cloneGraph(Node* node);
    private:
        std::unordered_map<Node*, Node*> map;
    };



    /* There are a total of n courses you have to take, labeled from 0 to n-1.
    Some courses may have prerequisites, for example to take course 0 you have to 
    first take course 1, which is expressed as a pair: [0,1]
    Given the total number of courses and a list of prerequisite pairs, is it possible 
    for you to finish all courses?

    Input: 2, [[1,0]] 
    Output: true
    Explanation: There are a total of 2 courses to take. 
                To take course 1 you should have finished course 0. So it is possible.
    Example 2:

    Input: 2, [[1,0],[0,1]]
    Output: false
    Explanation: There are a total of 2 courses to take. 
                To take course 1 you should have finished course 0, and to take course 0 you should
                also have finished course 1. So it is impossible.
    Note:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.
    */
    class _0207_CourseSchedule {
        using Graph = std::vector<std::vector<int>>;
        Graph createGraph(int numCourses, std::vector<std::vector<int>>& prerequisites);
        bool isCyclicUtils(Graph g, int v, std::vector<bool>& visited, std::vector<bool>& recStack);
        std::vector<int> computeIndegrees(Graph& g);
    public:    
        bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);
    };


    

/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you 
have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of 
them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 
you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
There are a total of 4 courses to take. To take course 3 you should have finished both     
courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not 
adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/
class _0210_CourseScheduleII {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites);
private:
     void BFS(const std::vector<std::vector<int>>& graph, std::vector<int>& inDegree, std::vector<int>& res);
};

/*
In this problem, a tree is an undirected graph that is connected and has no cycles.
The given input is a graph that started as a tree with N nodes (with distinct values 
1, 2, ..., N), with one additional edge added. The added edge has two different 
vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair 
[u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. 
If there are multiple answers, return the answer that occurs last in the given 2D-array. 
The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

Update (2017-09-26):
We have overhauled the problem description + test cases and specified clearly the graph is 
an undirected graph. For the directed graph follow up please see Redundant Connection II). 
We apologize for any inconvenience caused.
! 非常重要且经典的图论题目
! Just use the DFS to find out, if DFS can connect source and target with the given edge before this edge is added 
! to the graph, there must be circle.
*/
class _0684_RedundantConnection {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        std::vector<std::unordered_set<int>> graph;
        int nodeNum = 0;
        for(int i = 0; i < edges.size(); ++i) {
            nodeNum = std::max(nodeNum, edges[i][0]);
            nodeNum = std::max(nodeNum, edges[i][1]);
        }
        graph.resize(nodeNum);

        for(auto e : edges) {
            std::vector<int> visited(nodeNum, 0); 
            if(!graph[e[0]].empty() && !graph[e[1]].empty() && dfs(graph, visited, e[0], e[1])) { 
                return e;
            }
            graph[e[0]].insert(e[1]); // 一边 DFS， 一边 建立这个图，这样可以节省一部分时间，一旦有环，直接会被下一次 DFS 测出来。没有必要在建立整个图之后再开始检测。
            graph[e[1]].insert(e[0]);
        }
        return {};
    }
    bool dfs(std::vector<std::unordered_set<int>>& graph, std::vector<int>& visited, int source, int target) {
        if(!visited[source]) {
            visited[source] = 1;
            if(source == target) {
                return true; // contains circle
            }
            for(int adj : graph[source]) {
                if(dfs(graph, visited, adj, target)) {
                    return true;
                }
            }
        }
        return false;
    }
};

/*
Given an undirected graph, return true if and only if it is bipartite.
Recall that a graph is bipartite if we can split it's set of nodes into 
two independent subsets A and B such that every edge in the graph has 
one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j
for which the edge between nodes i and j exists.  Each node is an integer 
between 0 and graph.length - 1.  There are no self edges or parallel edges: 
graph[i] does not contain i, and it doesn't contain any element twice.

Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.

Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.
The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
*/
class _0785_IsGraphBipartitle {
    public:
        bool isBipartite(std::vector<std::vector<int>>& graph);
        bool DFS(std::vector<std::vector<int>>& graph, std::vector<int>& visited, int nodeIdx, int color);
};


/*
Given a directed, acyclic graph of N nodes.  Find all possible paths 
from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  
graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:
The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path.
*/
class _0797_AllPathsFromSourceToTarget {
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph);
};

/*
There are N cities numbered from 1 to N.
You are given connections, where each connections[i] = [city1, city2, cost] represents the cost to connect 
city1 and city2 together. (A connection is bidirectional: connecting city1 and city2 is the same as 
connecting city2 and city1.)

Return the minimum cost so that for every pair of cities, there exists a path of connections (possibly of 
length 1) that connects those two cities together. The cost is the sum of the connection costs used. If the 
task is impossible, return -1.

Input: N = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: 
Choosing any 2 edges will connect all cities so we choose the minimum 2.

Input: N = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: 
There is no way to connect all cities even if all edges are used.

Note:

1 <= N <= 10000
1 <= connections.length <= 10000
1 <= connections[i][0], connections[i][1] <= N
0 <= connections[i][2] <= 10^5
connections[i][0] != connections[i][1]
*/
class _1135_ConnectingCitiesWithMinimumCost {
    struct Edge {
        int from;
        int to;
        int weight;
        Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
    };
    class compare {
    public:
        bool operator()(Edge a, Edge b) {
            return a.weight > b.weight;
        };
    };

    std::vector<bool> marked;
    std::queue<Edge> mst;
    std::priority_queue<Edge,std::vector<Edge>, compare> pq;
    std::vector<std::vector<Edge>> graph;

    void createGraph(int N, std::vector<std::vector<int>>& connections) {
        graph.resize(N);
        marked = std::vector<bool>(N, false);
        for(auto& connection : connections) {
            graph[connection[0]-1].emplace_back(Edge(connection[0]-1, connection[1]-1, connection[2]));
            graph[connection[1]-1].emplace_back(Edge(connection[1]-1, connection[0]-1, connection[2]));
        }
    }
    
    void visit(int v) {
        marked[v] = true;
        for(Edge& e : graph[v]) {
            if(!marked[e.to]) {
                pq.push(e);
            }
        }
    }
public:
    int minimumCost(int N, std::vector<std::vector<int>>& connections);
};


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
! Careful of in-degrees of the node, if it is 0, it definitely in the set.
*/
class _1557_MinimumNumberOfVerticesToReachAllNodes {
public:
    std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>>& edges);
};

}

#endif