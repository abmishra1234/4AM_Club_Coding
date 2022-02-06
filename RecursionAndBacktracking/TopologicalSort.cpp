/*
	Topological Sort in Graphs
	- Yes this is very good concept, let's learn it and code it
	
	what is topological sort?
	Topological sort is a way to order in a direted cyclic graph. Confused?
	Ok, move on you will find more points with example...

	Let's understand the acyclic means?
	An acyclic graph is one that has no cycles, i.e., 
	a node is not reachable from its own ancestors.

	"A topological sort takes such a graph and finds the order of the nodes 
	so that it always starts from a node with no incoming edges 
	and then traverses its adjacent nodes".

	@Note, this time, the current node is printed first and then its neighbors are printed.

	Yes, so for understanding point of view if you are able create the dependency graph,
	than dfs will be the way to implement this topological sort.

	Let's implement and learn or practice it.
*/

#define FORREF
#ifndef FORREF
using namespace std;
#include<iostream>
#include<vector>


struct edge {
	int src, dst;
	edge() : src(0), dst(0){}
	edge(int s, int d) : src(s), dst(d) {}
	edge(const edge& e) {
		src = e.src;
		dst = e.dst;
	}
};
struct graph {
	int nodes;
	vector<edge> edges;
	graph(int n, vector<edge>e) {
		nodes = n;
		for (size_t i = 0; i < e.size(); ++i) {
			edges.push_back(e[i]);
		}
	}

	// This function implements the topological sorting
	void topologicalSort(int v, vector<int>& visited, vector<int>& ts)
	{
		//Base Case
		if (visited[v] == 1) { return; }

		else
		{
			visited[v] = 1;
			for (size_t i = 0; i < edges.size(); i++)
			{
				if (edges[i].src == v)
				{
					int dest = edges[i].dst;
					if (visited[dest] == 0)
					{
						topologicalSort(dest, visited, ts); //Recursive Case
					}
				}
			}
			ts.push_back(v);
		}
	}
};


int main() {
	edge one(0, 1);
	edge two(1, 2);
	edge three(2, 3);
	edge four(1, 3);
	edge five(0, 4);
	edge six(2, 4);

	vector<edge> e;
	e.push_back(one);
	e.push_back(two);
	e.push_back(three);
	e.push_back(four);
	e.push_back(five);
	e.push_back(six);

	int n = 5;
	graph g(n, e);
	vector<int> visit = { 0,0,0,0,0,0 };
	vector<int> ts;
	for (int i = 0; i < n; i++) {
		g.topologicalSort(i, visit, ts);
	}

	for (int i = ts.size() - 1; i > -1; i--) {
		cout << ts[i] << " ";
	}
	cout << endl;
}

#endif // FORREF