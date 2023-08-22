//https://practice.geeksforgeeks.org/problems/mother-vertex/1

//Initial Template for C++


#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


/*
 * Function to find if there is a mother vertex in the given graph 
 * V: number of vertices in the graph
 * adj[]: graph representation
 */
void dfs(vector<int> adj[], vector<bool> &vis, int i)
{
    vis[i] = 1;
    for(auto ne: adj[i])
        if(!vis[ne])
            dfs(adj, vis, ne);
}

int findMother(int V, vector<int> adj[]) 
{ 
    int i, mother;
    vector<bool> vis(V, 0);
    for(i=0;i<V;i++)
        if(!vis[i])
        {
            dfs(adj, vis, i);
            mother = i;
        }
    fill(vis.begin(), vis.end(), 0);
    dfs(adj, vis, mother);
    for(i=0;i<V;i++)
        if(!vis[i])
            return -1;
    return mother;
} 

// { Driver Code Starts.

int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}   // } Driver Code Ends