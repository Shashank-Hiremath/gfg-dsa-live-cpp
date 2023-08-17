//https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1

// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int shortest(vector<vector<int> > &grid ,int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int> > grid(n);

        for (int i = 0; i < n; i++) 
        {
            grid[i].resize(n);
            for (int j = 0; j < n; j++) 
            {
                cin >> grid[i][j];
            }
        }
        
        cout << shortest(grid,n) << endl;
    }
    return 0;
}
// } Driver Code Ends

static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
// grid : given n*n grid 
// n : size of the square grid
struct edge{
    int length;
    int to;
};
int shortest(vector<vector<int> > &grid, int n) {
    vector<vector<edge>> g(n*n);
    int i, j, k, i1, j1, row[4]={0, -1, 0, 1}, col[4]={1, 0, -1, 0}, curr;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(k=0;k<4;k++)
            {
                i1 = i + row[k];
                j1 = j + col[k];
                if(i1>=0 && i1<n && j1>=0 && j1<n)
                    g[n*i+j].push_back({grid[i][j], n*i1+j1});
            }
    vector<int> dist(n*n, INT_MAX);
    dist[0] = 0;
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    // pq.push({dist[0], 0});
    set<pair<int, int>> s;
    s.insert({dist[0], 0});
    // while(!pq.empty())
    while(!s.empty())
    {
        // curr = pq.top().second;
        // pq.pop();
        curr = s.begin()->second;
        s.erase(s.begin());
        for(auto ed: g[curr])
            if(dist[ed.to] > dist[curr] + ed.length)
            {
                dist[ed.to] = dist[curr] + ed.length;
                // pq.push({dist[ed.to], ed.to});
                s.insert({dist[ed.to], ed.to});
            }
    }
    return dist[n*n-1] + grid[n-1][n-1];
}