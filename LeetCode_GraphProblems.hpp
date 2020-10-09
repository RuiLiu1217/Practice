#ifndef LEETCODE_GRAPHPROBLEM_HPP
#define LEETCODE_GRAPHPROBLEM_HPP
#include <queue>
#include <vector>
#include <unordered_map>
namespace LC {

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