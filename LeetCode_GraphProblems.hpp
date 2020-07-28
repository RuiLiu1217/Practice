#ifndef LEETCODE_GRAPHPROBLEM_HPP
#define LEETCODE_GRAPHPROBLEM_HPP

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

}

#endif