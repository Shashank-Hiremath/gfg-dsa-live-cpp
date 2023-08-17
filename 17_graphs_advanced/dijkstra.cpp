//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> , int ,int );


int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
struct edge{
    int length;
    int to;
};
void dijkstra(vector<vector<int>> graph, int src, int V)
{
    vector<vector<edge>> g(V);
    int i, j, m = graph.size(), n = graph[0].size(), curr;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(graph[i][j])
                g[i].push_back({graph[i][j], j});
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
    pq.push({dist[src], src});
    while(!pq.empty())
    {
        curr = pq.top().second;
        pq.pop();
        for(auto ed: g[curr])
            if(dist[ed.to] > dist[curr] + ed.length)
            {
                dist[ed.to] = dist[curr] + ed.length;
                pq.push({dist[ed.to], ed.to});
            }
    }
    for(i=0;i<V;i++)
        cout<<dist[i]<<" ";
}