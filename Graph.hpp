#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <unordered_set>
#include <stack>

class Graph {
private:
    int V; // number of vertex
    int E; // number of Edges
    std::vector<std::unordered_set<int>> adj;
public:
    Graph(int v) : V(v) {
        adj.resize(V);
    }

    int getV() const {
        return V;
    }
    int getE() const {
        return E;
    }
    void addEdge(int v, int w) {
        adj[v].insert(w);
        adj[w].insert(v);
        ++E;
    }
    std::unordered_set<int> getAdjEdges(int v) {
        return adj[v];
    }
};

class Search {
private:
    Graph g;
    
public:
    Search(Graph G, int s);
    bool marked(int v);
    int count();
};

class DepthFirstSearch {
protected:
    std::vector<bool> marked;
private:
    int count;
    virtual void dfs(Graph G, int v) {
        marked[v] = true;
        ++count;
        for(int m : G.getAdjEdges(v)) {
            if(!marked[m]) {
                dfs(G, m);
            }
        }
    }
public: 
    bool isMarked(int w) const {
        return marked[w];
    }
    int getCount() const {
        return count;
    }
    DepthFirstSearch(Graph G, int s) {
        marked.resize(G.getV());
        dfs(G, s);
    }
};

class Paths : public DepthFirstSearch{
private:
    std::vector<int> edgeTo;
    int S;
    virtual void dfs(Graph G, int v) override {
        marked[v] = true;
        for(int w : G.getAdjEdges(v)) {
            if(!marked[v]) {
                edgeTo[w] = v;
                dfs(G, w);
            }
        }
    }
public:
    Paths(Graph G, int s) : S(s){
        edgeTo.resize(G.getV());
    }
    bool hasPathTo(int v) {
        return marked[v];
    }
    std::stack<int> pathTo(int v) {
        if(!hasPathTo(v)) {
            return {};
        }
        std::stack<int> path;
        for(int x = v; x != S; x = edgeTo[x]) {
            path.push(x);
        }
        path.push(S);
        return path;
    }
};

#endif