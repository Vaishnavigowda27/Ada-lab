#include<bits/stdc++.h>
using namespace std;

int ne = 1;          // Variable to keep track of the number of edges included in the spanning tree
int min_cost = 0;    // Variable to accumulate the minimum cost of the spanning tree

int main() {
  int n, i, min, cost[20][20], a, b, u, v, source, visited[20];

  // Input the number of nodes in the graph
  cout << "Enter the number of nodes: ";
  cin >> n;

  // Input the cost adjacency matrix representing the graph
  cout << "Enter the cost matrix: ";
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> cost[i][j];  // Reading cost of each edge
    }
  }

  // Initialize all nodes as unvisited
  for(int i = 1; i <= n; i++)
    visited[i] = 0;

  // Input the source/root node from where to start the algorithm
  cout << "\nEnter the root node: ";
  cin >> source;
  visited[source] = 1;  // Mark the source node as visited

  cout << "Minimum cost spanning tree is\n";

  // Start building the minimum cost spanning tree using Prim's algorithm
  while(ne < n) {
    min = 999;  // Initialize the minimum edge cost as a large number

    // Loop to find the minimum cost edge that connects a visited node to an unvisited node
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        // Check if the current edge has a lower cost and connects a visited node to an unvisited node
        if(cost[i][j] < min) {
          if(visited[i] == 0)
            continue;  // Skip if the starting node is unvisited
          else {
            min = cost[i][j];  // Update the minimum cost
            a = u = i;         // Store the starting node
            b = v = j;         // Store the ending node
          }
        }
      }
    }

    // If the edge connects a visited node to an unvisited node, include it in the spanning tree
    if(visited[u] == 0 || visited[v] == 0) {
      cout << "\nEdge " << ne++ << "\t" << a << " -> " << b << " = " << min << endl;
      min_cost += min;  // Add the edge cost to the total minimum cost
      visited[b] = 1;   // Mark the end node as visited
    }

    // Mark the edge as used by setting its cost to a large number (999) so it's not reused
    cost[a][b] = cost[b][a] = 999;
  }

  // Output the total minimum cost of the spanning tree
  cout << "\nMinimum cost = " << min_cost << endl;
  return 0;
}
