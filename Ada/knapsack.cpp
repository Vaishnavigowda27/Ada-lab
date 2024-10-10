#include<bits/stdc++.h>
using namespace std;

#define MAX 10 // Define a constant for the maximum size of the knapsack and arrays

int knap[MAX][MAX]; // Declare a 2D array to store the maximum profit values for subproblems

// Function to return the maximum of two integers
int max(int a, int b) 
{
  return (a > b) ? a : b;
}

// Function to solve the knapsack problem using dynamic programming
int knapsack(int items, int capacity, int profit[], int weight[]) 
{
  int i, j;

  // Loop through each item
  for(int i = 1; i <= items; i++) 
  {
    // Loop through each possible capacity of the knapsack
    for(int j = 1; j <= capacity; j++) 
    {

      // If the current item's weight is more than the current capacity, skip it
      if(j < weight[i]) 
      {
        knap[i][j] = knap[i-1][j]; 
      } 
      // Otherwise, consider including the current item and find the maximum profit
      else {
        knap[i][j] = max(knap[i-1][j], profit[i] + knap[i-1][j-weight[i]]);
      }
    }
  }
  // Return the maximum profit that can be achieved with the given items and capacity
  return knap[items][capacity];
}
int main() 
{
  int i, j, n, items, capacity, profit[MAX];
  int weight[MAX], optimum_val;

  // Input the number of items
  cout << "Enter number of items: ";
  cin >> items;

  // Input the weights of the items
  cout << "Enter the weights: ";
  for(i = 1; i <= items; i++)
    cin >> weight[i];

  // Input the profits of the items
  cout << "Enter the profits: ";
  for(i = 1; i <= items; i++)
    cin >> profit[i];

  // Input the capacity of the knapsack
  cout << "Enter the capacity of knapsack: ";
  cin >> capacity;

  // Call the knapsack function to calculate the maximum profit
  optimum_val = knapsack(items, capacity, profit, weight);

  // Display the profit table
  cout << "Profit table\n";
  for(int i = 0; i <= items; i++) {
    for(int j = 0; j <= capacity; j++) {
      cout << knap[i][j] << "\t";
    }
    cout << "\n";
    cout << "\n";
  }

  // Display the maximum profit
  cout << "\nThe max profit is: " << optimum_val;
}
