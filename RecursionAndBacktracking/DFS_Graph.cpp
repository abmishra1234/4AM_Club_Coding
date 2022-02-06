/*
	Depth First Search in Graphs
	
	This lesson will tell you how to write a recursive code 
	for depth first search in graphs.

	Depth First Search is a way to traverse and search all nodes in a graph.
	This traversal algorithm works in such a way that it starts 
	from the root node and then traverses all the way down that branch 
	until it reaches the leaf, i.e., the last node with no other children, 
	and then backtracks. This follows until all nodes are traversed.

	Let's do the implementation now...


*/

#define FORREF
#ifndef FORREF

using namespace std;
#include<iostream>
#include<vector>

struct edge {
	int srcv, destv;
	edge(int s, int d) : srcv(s), destv(d) {}
};

struct graph {

	int nodes;
	vector<edge> edges;

	/*
		n : nodes of graph
		e : vector of edges
	*/
	graph(int n, vector<edge> e) {
		nodes = n;
		for (size_t i = 0; i < e.size(); ++i) {
			edges.push_back(e[i]);
		}
	}
	
	/*
		vertex : This is to maintain the current vertex	
		visited : to maintain the already visited vertex to avoid the any infinite loop
	*/
	void DFS(int vertex, vector<int> &visited) {
		if (visited[vertex] == 1)
			return;
		else {
			cout << "Current vertex : " << vertex << endl;
			// mark this vertex with flag , to be explored
			visited[vertex] = 2;

			for (size_t i = 0; i < edges.size(); ++i) {
				if (edges[i].srcv == vertex) {
					// you found the edge which can be explored further
					if (visited[edges[i].destv] == 0) {
						DFS(edges[i].destv, visited);
					}
				}
			}
			// so now exploration of vertex is completed so mark with appropriate flag value
			visited[vertex] = 1;
		}
	}
};

// Driver code
int main() {
	edge one(0, 1);
	edge two(0, 2);
	edge three(1, 3);
	edge four(1, 4);
	edge five(2, 5);

	vector<edge> e;
	e.push_back(one);
	e.push_back(two);
	e.push_back(three);
	e.push_back(four);
	e.push_back(five);

	int n = 5;
	graph g(n, e);
	vector<int> visit = { 0,0,0,0,0,0 };

	for (int i = 0; i < n; i++) {
		g.DFS(i, visit);
	}
}
#endif // FORREF
