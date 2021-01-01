#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <unordered_set>
#include <stack>
#include <queue>
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


// Dijkstra Algorithm

class DirectedEdge {
private:
    int v; // start point of an edge
    int w; // end point of an edge
    double weight; // weight of an edge;
public:
    DirectedEdge(int v, int w, double weight) : v(v), w(w), weight(weight) {}
    DirectedEdge() : v(INT_MAX), w(INT_MAX), weight(INT_MIN) {}
    int from() const {
        return v;
    }
    int to() const {
        return w;
    }
    double getWeight() const {
        return weight;
    }
    bool isNull() const {
        return weight == INT_MIN && v == w && v == INT_MAX;
    }
};

class DirectedEdgeHash {
public:
    size_t operator()(const DirectedEdge& v) {
        std::size_t h1 = std::hash<std::string>{}(std::to_string(v.from()));
        std::size_t h2 = std::hash<std::string>{}(std::to_string(v.to()));
        std::size_t h3 = std::hash<std::string>{}(std::to_string(v.getWeight()));
        return (h1 ^ h2 ^ h3);
    }
};

class EdgeWeightedDigraph {
private:
    int V; // number of vertex
    int E; // number of Edges;
public:
    using AdjList = std::unordered_set<DirectedEdge, DirectedEdgeHash>;
    std::vector<AdjList> adj; // adjcent list
    EdgeWeightedDigraph(int V): V(V), E(E) {
        adj.resize(V);
    }

    int getV() const { return V; }
    int getE() const { return E; }
    void addEdge(DirectedEdge e) {
        adj[e.from()].insert(e);
        ++E;
    }

    AdjList getAdj(int v) {
        return adj[v];
    }
    AdjList getEdges() {
        AdjList bag;
        for(auto& a : adj) {
            for(auto& e : a) {
                bag.insert(e);
            }
        }
        return bag;
    }
};


class DijkstraSP {
private:   
    std::vector<DirectedEdge> edgeTo;
    std::vector<double> distTo;
    std::priority_queue<std::pair<int, double>, std::vector<std::pair<int, double>>, std::greater<std::pair<int, double>>> pq;
public:
    // Graph start from indexed vertex s;
    DijkstraSP(EdgeWeightedDigraph G, int s) {
        edgeTo.resize(G.getV());
        distTo.resize(G.getV());
        pq.resize(G.getV());
        for(int v = 0; v < G.getV(); ++v) {
            distTo[v] = INT_MAX;
        }
        distTo[s] = 0.0;
        pq.insert(s, 0.0);
        while(!pq.empty()) {
            relax(G, pq.top());
            pq.pop();
        }
    }
        
    double getDistTo(int v) {
        return distTo[v];
    }
    bool hasPathTo(int v) {
        return distTo[v] < INT_MAX ? distTo[v] : INT_MAX;
    }
    std::stack<DirectedEdge> getPathTo(int v) {
        if(!hasPathTo(v)) {
            return {};
        }
        std::stack<DirectedEdge> path;
        for(auto e = edgeTo[v]; !e.isNull(); e = edgeTo[e.from()]) {
            path.push(e);
        }

    }
private:
    void relax(EdgeWeightedDigraph G, int v) {
        for(DirectedEdge e : G.getAdj(v)) {
            int w = e.to(); //
            if(distTo[w] > distTo[v] + e.getWeight()) {
                distTo[w] = distTo[v] + e.getWeight();
                edgeTo[w] = e;
                if(pq.contains(w)) {
                    pq.change(w, distTo[w]);
                } else {
                    pq.insert(w, distTo[w]);
                }
            }
        }
    }
};


#endif