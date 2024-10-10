#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

// Function to partition the array for quicksort
int partition(int a[100], int low, int high) {
  int i, j;
  int pivot = a[low]; // Choosing the first element as the pivot
  i = low;
  j = high;

  // Loop to rearrange the array so that elements less than the pivot are on its left
  // and elements greater than the pivot are on its right
    while (i < j) 
    {
    while (a[i] <= pivot) // Increment i until an element greater than the pivot is found
      i++;
    while (a[j] > pivot) // Decrement j until an element less than or equal to the pivot is found
      j--;
    if (i < j) { // Swap elements at i and j if they are out of order
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }

  // Place the pivot in its correct position
  int v = a[low];
  a[low] = a[j];
  a[j] = v;

  // Return the index of the pivot
  return j;
}

// Recursive quicksort function
void qsort(int a[], int low, int high) 
{
  if (low < high) {
    int j = partition(a, low, high); // Partition the array and get the pivot index
    qsort(a, low, j-1);  // Recursively sort the left sub-array
    qsort(a, j+1, high); // Recursively sort the right sub-array
  }
}

int main() 
{
  int n, i;
  clock_t start, end;

  // Input the number of elements to be sorted
  cout << "\nEnter the number of data elements to be sorted: ";
  cin >> n;

  int a[n];

  // Input the array elements
   cout << "Enter element \n";
  for(i = 0; i < n; i++) {
   cin >> a[i];
  }

  // Record the start time for sorting
  start = clock();
  qsort(a, 0, n-1); // Call the quicksort function to sort the array

  // Printing the sorted data
  cout << "\nSorted Data: ";
  for(i = 0; i < n; i++) {
    cout << a[i] << "\t";
  }

  // Record the end time and calculate the elapsed time
  end = clock();
  cout << "\nThe time is = " << (double)(end - start) / CLOCKS_PER_SEC << " seconds";
  
  return 0;
}
