//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <bits/stdc++.h>

using namespace std;




/* You have to complete this function*/

/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
void bfs(int s, vector<int> g[], vector<bool> &vis, int N) {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    int curr;
    while(!q.empty())
    {
        curr = q.front();
        q.pop();
        cout<<curr<<' ';
        for(auto x: g[curr])
            if(!vis[x])
            {
                q.push(x);
                vis[x] = 1;
            }
    }
}