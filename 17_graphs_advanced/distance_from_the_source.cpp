//https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int s) {
        vector<int> dist(n, 1e8);
        dist[s] = 0;
        for(int i=0;i<n-1;i++)
            for(auto e: edges){
                int u = e[0];
                int v = e[1];
                int wt = e[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v])
                return {-1};
        }
        return dist;
    }
};