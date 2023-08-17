//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//By checking if topological sort possible
bool bfs(vector<int> adj[], vector<bool> &vis, int i)
{
    queue<pair<int, int>> q;
    q.push({i, -1});
    vis[i] = 1;
    int curr, parent;
    while(!q.empty())
    {
        curr = q.front().first;
        parent = q.front().second;
        q.pop();
        for(auto ne: adj[curr])
            if(!vis[ne])
            {
                q.push({ne, curr});
                vis[ne] = 1;
            }
            else if(ne != parent)
                return 1;
    }
    return 0;
}
bool isCyclic(vector<int> adj[], int V) //Check if ne is parent instead of recStack[]
{
    vector<bool> vis(V, 0);
    for(int i=0;i<V;i++)
        if(!vis[i] && bfs(adj, vis, i))
            return 1;
    return 0;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends



//------------------------------------------------------------------------------------------------
//By checking for a back edge
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

bool dfs(vector<int> adj[], vector<bool> &vis, int i, int parent)
{
    vis[i] = 1;
    for(auto ne: adj[i])
        if(!vis[ne])
        {
            if(dfs(adj, vis, ne, i))
                return 1;
        }
        else if(ne != parent)
            return 1;
    return 0;
}
bool isCyclic(vector<int> adj[], int V)
{
    vector<bool> vis(V, 0);
    for(int i=0;i<V;i++)
        if(!vis[i] && dfs(adj, vis, i, -1))
            return 1;
    return 0;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends