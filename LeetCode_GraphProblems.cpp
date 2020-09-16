#include "LeetCode_GraphProblems.hpp"
#include <set>
#include <queue>

// 802 BFS solution
// 这道题给了我们一个有向图，然后定义了一种最终安全状态的结点，就是说该结点要在自然数K步内停止，
// 所谓停止的意思，就是再没有向外的边，即没有出度，像上面例子中的结点5和6就是出度为0，因为
// graph[5]和graph[6]均为空。那么我们分析题目中的例子，除了没有出度的结点5和6之外，结点2和4也
// 是安全状态结点，为啥呢，我们发现结点2和4都只能到达结点5，而结点5本身就是安全状态点，所以2和
// 4也就是安全状态点了，所以我们可以得出的结论是，若某结点唯一能到达的结点是安全状态结点的话，
// 那么该结点也同样是安全状态结点。那么我们就可以从没有出度的安全状态往回推，比如结点5，往回推
// 可以到达结点4和2，先看结点4，此时我们先回推到结点4，然后将这条边断开，那么此时结点4出度为0，
// 则标记结点4也为安全状态结点，同理，回推到结点2，断开边，此时结点2虽然入度仍为2，但是出度为0了，
// 标记结点2也为安全状态结点。
// 分析到这里，思路应该比较明朗了，由于我们需要回推边，所以需要建立逆向边，用一个集合数组来存，
// 由于题目要求返回的结点有序，我们可以利用集合TreeSet的自动排序的特性，由于需要断开边，为了不
// 修改输入数据，所以我们干脆再建一个顺向边得了，即跟输入数据相同。还需要一个safe数组，布尔型的，
// 来标记哪些结点是安全状态结点。在遍历结点的时候，直接先将出度为0的安全状态结点找出来，排入一个
// 队列queue中，方便后续的处理。后续的处理就有些类似BFS的操作了，我们循环非空queue，取出队首元
// 素，标记safe中该结点为安全状态结点，然后遍历其逆向边的结点，即可以到达当前队首结点的所有结点，
// 我们在正向边集合中删除对应的边，如果此时结点出度为0了，将其加入队列queue中等待下一步处理，这
// 样while循环退出后，所有的安全状态结点都已经标记好了，我们直接遍历safe数组，将其存入结果res中
// 即可.
std::vector<int> LC::_0802_FindEventualSafeStates::eventualSafeNodes(std::vector<std::vector<int>>& graph) {
    return eventualSafeNodes_DFS(graph);
}
std::vector<int> LC::_0802_FindEventualSafeStates::eventualSafeNodes_BFS(std::vector<std::vector<int>>& graph) {
    std::vector<int> res;
    int n = graph.size();
    std::vector<bool> safe(n, false);
    std::vector<std::set<int>> g(n, std::set<int>()), revg = g;
    std::queue<int> q;
    for(int i = 0; i < n; ++i) {
        if(graph[i].empty()) {
            q.push(i);
        }
        for(int j : graph[i]) {
            g[i].insert(j);
            revg[j].insert(i);
        }
    }

    while(!q.empty()) {
        auto t = q.front();
        q.pop();

        safe[t] = true;
        for(int i : revg[t]) {
            g[i].erase(t);
            if(g[i].empty()) {
                q.push(i);
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        if(safe[i]) {
            res.push_back(i);
        }
    }

    return res;
}

// 802 DFS Solution
// 我们再来看一种DFS遍历有向图的解法。仔细分析题目中的例子，不难发现，
// 之所以某些结点不是安全状态，因为有环的存在，而环经过的所有结点，一
// 定不是安全状态结点，所以我们可以通过DFS遍历有向图来找出环即可。在
// 大多数的算法中，经典的DFS遍历法对于结点都有三种状态标记，
// white，gray，和black，其中white表示结点还未遍历，gray表示正在遍历
// 邻结点，black表示已经结束该结点的遍历。那么我们可以对每个结点都调用
// 递归函数，在递归函数中，如果当前结点不是white，表示该结点已经访问过
// 了，那么如果当前结点是black，直接返回true，如果是gray，直接返回
// false，因为遇到gray的结点，表示一定有环存在。否则我们给结点标记gray，
// 然后开始遍历所有邻接结点，如果某个邻结点是black，直接跳过该结点。
// 如果某个邻结点是gray，或者对该邻结点调用递归返回false了，说明当前结
// 点是环结点，返回false。如果循环结束了，当前结点标记为black，并且返回
// true，参见代码如下：
std::vector<int> LC::_0802_FindEventualSafeStates::eventualSafeNodes_DFS(std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<int> res, color(n); // 0 white, 1 gray and 2 black
    for(int i = 0; i < n; ++i) {
        if(helper(graph, i, color)) {
            res.push_back(i);
        }
    }
    return res;
}

bool LC::_0802_FindEventualSafeStates::helper(std::vector<std::vector<int>>& graph, int cur, std::vector<int>& color) {
    if(color[cur] > 0) {
        return color[cur] == 2;
    }
    color[cur] = 1;
    for(int i : graph[cur]) {
        if(color[i] == 2) {
            continue;
        }
        if(color[i] == 1 || !helper(graph, i, color)) {
            return false;
        }
    }
    color[cur] = 2;
    return true;
}


// 用一个 map 来建立当前节点pointer 与 要clone 的节点pointer 的映射。
LC::_0133_CloneGraph::Node* LC::_0133_CloneGraph::cloneGraph(Node* node) {
    if(map.find(node) == map.end()) {  // 如果没有这个节点，说明还没有clone 它
        Node* newNode = new Node(node->val, std::vector<Node*>{}); // 新建一个节点
        map[node] = newNode; // 他的映射建立，以后再遇到它就不用clone 了;
        
        for(int i = 0; i < node->neighbors.size(); ++i) {
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));  // 基于DFS， 新节点的每个neighbor 都是从旧节点 neighbor 的 clone.
        }
        return newNode;
    } else {
        return map[node]; // 如果这个节点已经有了，就不需要clone了，直接返回新节点的指针。
    }
}


// Tag: topological sorting, Graph
// TODO: DFS based topological sorting 
LC::_0207_CourseSchedule::Graph LC::_0207_CourseSchedule::createGraph(
    int numCourses, std::vector<std::vector<int>>& prerequisites) {
    Graph g(numCourses);
    for(auto p : prerequisites) {
        g[p[1]].push_back(p[0]);
    }
    return g;
}

bool LC::_0207_CourseSchedule::isCyclicUtils(LC::_0207_CourseSchedule::Graph g, 
    int v, std::vector<bool>& visited, std::vector<bool>& recStack) {
    if(visited[v] == false) {
        visited[v] = true;
        recStack[v] = true;
        
        auto& adj = g[v];
        for(auto i : adj) {
            if(!visited[i] && isCyclicUtils(g, i, visited, recStack)) {
                return true;
            } else if(recStack[i]) {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

std::vector<int> LC::_0207_CourseSchedule::computeIndegrees(
    LC::_0207_CourseSchedule::Graph& g) {
    std::vector<int> degrees(g.size(), 0);
    for (auto adj : g) {
        for (int v : adj) {
            degrees[v]++;
        }
    }
    return degrees;
}

bool LC::_0207_CourseSchedule::canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    Graph g = createGraph(numCourses, prerequisites);
    std::vector<int> degrees = computeIndegrees(g);
    for (int i = 0; i < numCourses; i++) {
        int j = 0;
        for (; j < numCourses; j++) {
            if (!degrees[j]) {
                break;
            }
        }
        if (j == numCourses) {
            return false;
        }
        degrees[j]--;
        for (int v : g[j]) {
            degrees[v]--;
        }
    }
    return true;
}


// Tag: Topological sorting
std::vector<int> LC::_0210_CourseScheduleII::findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<int> inDegree(numCourses, 0);
    std::vector<std::vector<int>> graph(numCourses, std::vector<int>());
    for(auto edge : prerequisites) {
        graph[edge[1]].push_back(edge[0]);
        ++inDegree[edge[0]];
    }
    
    // BFS
    std::vector<int> res;
    BFS(graph, inDegree, res);
    return res.size() == numCourses ? res : std::vector<int>();
}

void LC::_0210_CourseScheduleII::BFS(const std::vector<std::vector<int>>& graph, std::vector<int>& inDegree, std::vector<int>& res) {
    std::vector<int> visited(inDegree.size(), 0);
    std::queue<int> q;
    for(int i = 0; i < inDegree.size(); ++i) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int canLearn = q.front();
        res.push_back(canLearn);
        q.pop();
        visited[canLearn] = 1;
        
        std::vector<int> toLearn = graph[canLearn];
        for(int i = 0; i < toLearn.size(); ++i) {
            --inDegree[toLearn[i]];
            if(inDegree[toLearn[i]] == 0 && !visited[toLearn[i]]) {
                q.push(toLearn[i]);
            }
        }
    }        
}

int LC::_1135_ConnectingCitiesWithMinimumCost::minimumCost(int N, std::vector<std::vector<int>>& connections) {
    createGraph(N, connections);
    visit(0);
    while(!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        int v = e.from;
        int w = e.to;
        if(marked[v] && marked[w]) {
            continue;
        }
        mst.push(e);
        if(!marked[v]) {
            visit(v);
        }
        if(!marked[w]) {
            visit(w);
        }
    }
    
    if(mst.size() < N - 1) {
        return -1;
    }
    int cost = 0;
    while(!mst.empty()) {
        cost += mst.front().weight;
        mst.pop();
    }
    return cost;
}