//https://practice.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>

using namespace std;

int *topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int res[], vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int *res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array
*/
int* topoSort(int V, vector<int> adj[]) {
    vector<int> queue, indegree(V, 0);
    int i;
    for(i=0;i<V;i++)
        for(auto ne: adj[i])
            indegree[ne]++;
    for(i=0;i<V;i++)
        if(!indegree[i])
            queue.push_back(i);
    for(i=0;i<queue.size();i++)
        for(auto ne: adj[queue[i]])
            if(--indegree[ne] == 0)
                queue.push_back(ne);
    int *ret = new int[V];
    copy(queue.begin(), queue.end(), ret);
    return ret;
}

//------------------------------------------------------------------------------------------------
//Using DFS
#include <bits/stdc++.h>

using namespace std;

int *topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int res[], vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int *res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends

void dfs(vector<int> adj[], vector<bool> &vis, int i, stack<int> &topo)
{
    vis[i] = 1;
    for(auto ne: adj[i])
        if(!vis[ne])
            dfs(adj, vis, ne, topo);
    topo.push(i);
}

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array
*/
int* topoSort(int V, vector<int> adj[]) {
    stack<int> topo;
    vector<bool> vis(V, 0);
    int i, *ret = new int[V];
    for(i=0;i<V;i++)
        if(!vis[i])
            dfs(adj, vis, i, topo);
    for(i=0;i<V;i++, topo.pop())
        ret[i] = topo.top();
    return ret;
}