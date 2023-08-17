//https://www.geeksforgeeks.org/detecting-negative-cycle-using-floyd-warshall/

// C++ Program to check if there is a negative weight
// cycle using Floyd Warshall Algorithm
#include<bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 4

/* Define Infinite as a large enough value. This
value will be used for vertices not connected
to each other */
#define INF 99999

// A function to print the solution matrix
void printSolution(int dist[][V]);

// Returns true if graph has negative weight cycle
// else false.
bool negCyclefloydWarshall(int graph[][V])
{
	/* dist[][] will be the output matrix that will
	finally have the shortest
	distances between every pair of vertices */
	int dist[V][V], i, j, k;

	/* Initialize the solution matrix same as input
	graph matrix. Or we can say the initial values
	of shortest distances are based on shortest
	paths considering no intermediate vertex. */
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	/* Add all vertices one by one to the set of
	intermediate vertices.
	---> Before start of a iteration, we have shortest
		distances between all pairs of vertices such
		that the shortest distances consider only the
		vertices in set {0, 1, 2, .. k-1} as intermediate
		vertices.
	----> After the end of a iteration, vertex no. k is
		added to the set of intermediate vertices and
		the set becomes {0, 1, 2, .. k} */
	for (k = 0; k < V; k++)
	{
		// Pick all vertices as source one by one
		for (i = 0; i < V; i++)
		{
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < V; j++)
			{
				// If vertex k is on the shortest path from
				// i to j, then update the value of dist[i][j]
				if (dist[i][k] + dist[k][j] < dist[i][j])
						dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// If distance of any vertex from itself
	// becomes negative, then there is a negative
	// weight cycle.
	for (int i = 0; i < V; i++)
		if (dist[i][i] < 0)
			return true;
	return false;
}

// driver program
int main()
{
	/* Let us create the following weighted graph
			1
	(0)----------->(1)
	/|\			 |
	|			 |
-1 |			 | -1
	|			 \|/
	(3)<-----------(2)
		-1	 */
		
	int graph[V][V] = { {0 , 1 , INF , INF},
						{INF , 0 , -1 , INF},
						{INF , INF , 0 , -1},
						{-1 , INF , INF , 0}};
	
	if (negCyclefloydWarshall(graph))
	cout << "Yes";
	else
	cout << "No";
	return 0;
}



//https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/
// A C++ program for Bellman-Ford's single source
// shortest path algorithm.
#include <bits/stdc++.h>
using namespace std;

// a structure to represent a weighted edge in graph
struct Edge {
	int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph {
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[graph->E];
	return graph;
}

// The main function that finds shortest distances
// from src to all other vertices using Bellman-
// Ford algorithm. The function also detects
// negative weight cycle
bool isNegCycleBellmanFord(struct Graph* graph,
						int src, int dist[])
{
	int V = graph->V;
	int E = graph->E;

	// Step 1: Initialize distances from src
	// to all other vertices as INFINITE
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// Step 2: Relax all edges |V| - 1 times.
	// A simple shortest path from src to any
	// other vertex can have at-most |V| - 1
	// edges
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	// Step 3: check for negative-weight cycles.
	// The above step guarantees shortest distances
	// if graph doesn't contain negative weight cycle.
	// If we get a shorter path, then there
	// is a cycle.
	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			return true;
	}

	return false;
}

// Returns true if given graph has negative weight
// cycle.
bool isNegCycleDisconnected(struct Graph* graph)
{

	int V = graph->V;
	// To keep track of visited vertices to avoid
	// recomputations.
	bool visited[V];
	memset(visited, 0, sizeof(visited));

	// This array is filled by Bellman-Ford
	int dist[V];

	// Call Bellman-Ford for all those vertices
	// that are not visited
	for (int i = 0; i < V; i++) {
		if (visited[i] == false) {
			// If cycle found
			if (isNegCycleBellmanFord(graph, i, dist))
				return true;

			// Mark all vertices that are visited
			// in above call.
			for (int i = 0; i < V; i++)
				if (dist[i] != INT_MAX)
					visited[i] = true;
		}
	}

	return false;
}

// Driver program to test above functions
int main()
{
	/* Let us create the graph given in above example */
	int V = 5; // Number of vertices in graph
	int E = 8; // Number of edges in graph
	struct Graph* graph = createGraph(V, E);

	// add edge 0-1 (or A-B in above figure)
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;

	// add edge 0-2 (or A-C in above figure)
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;

	// add edge 1-2 (or B-C in above figure)
	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;

	// add edge 1-3 (or B-D in above figure)
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;

	// add edge 1-4 (or A-E in above figure)
	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;

	// add edge 3-2 (or D-C in above figure)
	graph->edge[5].src = 3;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 5;

	// add edge 3-1 (or D-B in above figure)
	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 1;

	// add edge 4-3 (or E-D in above figure)
	graph->edge[7].src = 4;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = -3;

	if (isNegCycleDisconnected(graph))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
