//https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V,int E,vector<vector<int> > graph);
// Driver code

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector< vector<int> > graph(V,vector<int>(V,INT_MAX));

        while(E--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout<<spanningTree(V,E,graph)<<endl;
    }
    return 0;
}

// } Driver Code Ends
#define pii pair<int, int>
int spanningTree(int V,int E,vector<vector<int> > graph)//O(E log V), Prim's
{//Use Prim's algorithm when you have a graph with lots of edges.
    vector<int> weight(V, INT_MAX);
    vector<bool> vis(V, 0);
    weight[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({weight[0], 0});
    int i, j, sum=0;
    while(!pq.empty())
    {
        i = pq.top().second;
        pq.pop();
        if(!vis[i])
        {
            vis[i] = 1;
            sum += weight[i];
            for(j=0;j<V;j++)
                if(graph[i][j]!=INT_MAX && !vis[j] && graph[i][j]<weight[j])
                {
                    weight[j] = graph[i][j];
                    pq.push({weight[j], j});
                }
        }
    }
    return sum;
}
