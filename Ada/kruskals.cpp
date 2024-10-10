#include<bits/stdc++.h>
using namespace std;

int ne = 1, min_cost = 0;  // `ne` tracks the number of edges in the spanning tree, `min_cost` accumulates the total cost.

int main() {
  int n, i, min, cost[20][20], a, b, u, v, parent[20];

  // Input the number of nodes in the graph
  cout << "Enter the number of nodes: ";
  cin >> n;

  // Input the cost adjacency matrix representing the graph
  cout << "Enter the cost matrix:";
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> cost[i][j];  // Reading the cost of each edge
    }
  }

  // Initialize the parent array to 0, indicating that all nodes are initially their own parent
  for(int i = 1; i <= n; i++)
    parent[i] = 0;

  cout << "Minimum cost spanning tree is\n";

  // Loop to find the minimum cost spanning tree
  while(ne < n) {
    min = 999;  // Initialize the minimum cost to a large number

    // Find the edge with the minimum cost in the graph
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(cost[i][j] < min) {
          min = cost[i][j];  // Update the minimum cost
          a = u = i;  // Store the starting node of the edge
          b = v = j;  // Store the ending node of the edge
        }
      }
    }

    // Find the root of the starting node's set
    while(parent[u])
      u = parent[u];

    // Find the root of the ending node's set
    while(parent[v])
      v = parent[v];

    // If the roots are different, the edge does not form a cycle
    if(u != v) {
      cout << "\nEdge " << ne++ << "\t" << a << " -> " << b << " = " << min << endl;
      min_cost += min;  // Add the edge's cost to the total minimum cost
      parent[v] = u;    // Union the sets by making the root of one set the parent of the other
    }

    // Mark the edge as used by setting its cost to a large number (999)
    cost[a][b] = cost[b][a] = 999;
  }

  // Output the total minimum cost of the spanning tree
  cout << "\nMinimum cost = " << min_cost << endl;
  return 0;
}
