//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

class Solution
{
	public:
    void dfs(vector<vector<int>>& adj, vector<bool> &vis, int i, stack<int> &st)
    {
        vis[i] = 1;
        for(auto ne: adj[i])
            if(!vis[ne])
                dfs(adj, vis, ne, st);
        st.push(i);
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        int i, ans=0;
        vector<vector<int>> rev(V);
        vector<bool> vis(V, 0);
        stack<int> st;
        for(i=0;i<V;i++)
            if(!vis[i])
                dfs(adj, vis, i, st);
        for(i=0;i<V;i++)
            for(auto ne: adj[i])
                rev[ne].push_back(i);
        fill(vis.begin(), vis.end(), 0);
        stack<int> st2;
        while(!st.empty())
        {
            i = st.top();
            st.pop();
            if(!vis[i])
            {
                dfs(rev, vis, i, st2);
                ans++;
            }
        }
        return ans;
    }
};


//Using BFS: https://www.geeksforgeeks.org/check-given-directed-graph-strongly-connected-set-2-kosaraju-using-bfs/
// C++ program to check if a given directed graph
// is strongly connected or not with BFS use
#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V; // No. of vertices
	list<int> *adj; // An array of adjacency lists

	// A recursive function to print DFS starting from v
	void BFSUtil(int v, bool visited[]);
public:

	// Constructor and Destructor
	Graph(int V) { this->V = V; adj = new list<int>[V];}
	~Graph() { delete [] adj; }

	// Method to add an edge
	void addEdge(int v, int w);

	// The main function that returns true if the
	// graph is strongly connected, otherwise false
	bool isSC();

	// Function that returns reverse (or transpose)
	// of this graph
	Graph getTranspose();
};

// A recursive function to print DFS starting from v
void Graph::BFSUtil(int v, bool visited[])
{
	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[v] = true;
	queue.push_back(v);

	// 'i' will be used to get all adjacent vertices
	// of a vertex
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue
		v = queue.front();
		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it
		// visited and enqueue it
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

// Function that returns reverse (or transpose) of this graph
Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
			g.adj[*i].push_back(v);
	}
	return g;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// The main function that returns true if graph
// is strongly connected
bool Graph::isSC()
{
	// Step 1: Mark all the vertices as not
	// visited (For first BFS)
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Step 2: Do BFS traversal starting
	// from first vertex.
	BFSUtil(0, visited);

	// If BFS traversal doesn’t visit all
	// vertices, then return false.
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			return false;

	// Step 3: Create a reversed graph
	Graph gr = getTranspose();

	// Step 4: Mark all the vertices as not
	// visited (For second BFS)
	for(int i = 0; i < V; i++)
		visited[i] = false;

	// Step 5: Do BFS for reversed graph
	// starting from first vertex.
	// Starting Vertex must be same starting
	// point of first DFS
	gr.BFSUtil(0, visited);

	// If all vertices are not visited in
	// second DFS, then return false
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			return false;

	return true;
}

// Driver program to test above functions
int main()
{
	// Create graphs given in the above diagrams
	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(1, 2);
	g1.addEdge(2, 3);
	g1.addEdge(3, 0);
	g1.addEdge(2, 4);
	g1.addEdge(4, 2);
	g1.isSC()? cout << "Yes\n" : cout << "No\n";

	Graph g2(4);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.addEdge(2, 3);
	g2.isSC()? cout << "Yes\n" : cout << "No\n";

	return 0;
}
