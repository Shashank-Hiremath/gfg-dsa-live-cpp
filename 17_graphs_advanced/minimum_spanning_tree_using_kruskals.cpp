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


int find(vector<int> &parent, int i)
{
    if(parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}
void _union(vector<int> &parent, int i, int j)
{
    parent[find(parent, i)] = find(parent, j);
}
int Find(int i,int parent[])
{
    if(parent[i] == -1)
    return i;
    
    return Find(parent[i],parent);
}

void Union(int i,int j, int parent[],int n)
{
    int pI = Find(i,parent);
    int pJ = Find(j,parent);
    
    int temp = pJ;
    parent[pJ] = pI;
    
    for(int k=0;k<n;k++)
    if(parent[k] == temp)
    parent[k] = pI;
    
    return;
    
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V,int E,vector<vector<int> > graph)//O(E log V), Kruskal --> TLE
{//Use Prim's algorithm when you have a graph with lots of edges.
    vector <pair<int,pair<int,int> > > v;
    
    for(int i=0;i<V;i++)
    {
        for(int j=i+1;j<V;j++)
        {
            if(graph[i][j] != INT_MAX)
            {
                v.push_back(make_pair(graph[i][j],make_pair(i,j)));
            }
        }
    }
    
    int n = v.size();
    sort(v.begin(),v.end());
    
    int parent[V];
    memset(parent,-1,sizeof(parent));
    
   /* int rank[V];
    for(int i=0;i<V;i++)
    rank[i] = 1;*/
    
    int edge = 1;
    int i=0;
    int ans = 0;
    while(edge <= V-1)
    {
        if(Find(v[i].second.first,parent) != Find(v[i].second.second,parent))
        {
            ans += v[i].first;
            
            Union(v[i].second.first,v[i].second.second,parent,V);
            edge++;
        }
        i++;
    }
    
    return ans;
    // vector<vector<int>> edges;
    // vector<int> parent(V);
    // int i, j, cnt, sum;
    // for(i=0;i<V;i++)
    //     for(j=0;j<V;j++)
    //         if(graph[i][j] != INT_MAX)
    //             edges.push_back({graph[i][j], i, j});
    // sort(edges.begin(), edges.end());
    
    // iota(parent.begin(), parent.end(), 0);
    // for(i=0, cnt=0, sum=0;cnt<V-1 && i<edges.size();i++)
    //     if(find(parent, edges[i][1]) != find(parent, edges[i][2]))
    //     {
    //         sum += edges[i][0];
    //         _union(parent, edges[i][1], edges[i][2]);
    //         cnt++;
    //     }
    // return sum;
}






