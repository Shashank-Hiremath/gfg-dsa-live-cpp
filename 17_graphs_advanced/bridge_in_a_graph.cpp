//https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

// Initial template
#include <bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    list<int> *adj;

  public:
    Graph(int V);
    int addEdge(int v, int w);
    bool isBridge(int u, int v);
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
int Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Driver Program
int main() {

    int T;
    cin >> T;
    while (T--) {
        int s, N;
        cin >> s >> N;
        Graph *g = new Graph(s);
        for (int i = 0; i < N; i++) {
            int u, v;
            cin >> u >> v;
            g->addEdge(u, v);
        }
        int a, b;
        cin >> a >> b;

        if (g->isBridge(a, b))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
// } Driver Code Ends


// your task is to complete this function

/*The structure of the class is as follows
which contains an integer V denoting the no
of vertices and a list of adjacency vertices.
class Graph
{
    int V;
    list<int> *adj;
public :
    Graph(int V);
    void addEdge(int v,int w);
    bool isBridge();
};*/
void dfs(int i, list<int> *adj, vector<bool> &vis)
{
    vis[i] = 1;
    for(auto ne: adj[i])
        if(!vis[ne])
            dfs(ne, adj, vis);
}
bool Graph::isBridge(int u, int v) {
    int cnt=0, i;
    vector<bool> vis(V, 0);
    for(i=0;i<V;i++)
        if(!vis[i])
        {
            dfs(i, adj, vis);
            cnt++;
        }
    adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
    adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
    fill(vis.begin(), vis.end(), 0);
    for(i=0;i<V;i++)
        if(!vis[i])
        {
            dfs(i, adj, vis);
            cnt--;
        }
    return cnt==-1;
}