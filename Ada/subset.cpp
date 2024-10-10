#include<iostream>
using namespace std;

// Global variables
int s[10], count = 0, set[10], d, n;
int flag = 0; // Flag to check if any subset is found

// Function to display a valid subset
void display(int);

// Recursive function to find subsets that sum to 'd'
void subset(int sum, int i) {
    // Base case: If the sum matches the desired sum 'd'
    if (sum == d) {
        flag = 1; // Mark that a valid subset is found
        display(count); // Display the subset
        return;
    }

    // Base case: If the sum exceeds 'd' or we've considered all elements
    if (sum > d || i >= n) {
        return;
    } else {
        // Include the current element in the subset
        set[count] = s[i];
        count++; // Increase the count of elements in the subset

        // Recur to include the next element in the subset
        subset(sum + s[i], i + 1);

        // Backtrack: Remove the last included element and try the next possibility
        count--;
        subset(sum, i + 1);
    }
}

// Function to display the current subset
void display(int count) {
    cout << "{ ";
    for (int i = 0; i < count; i++) {
        cout << set[i] <<" "; // Print elements of the subset
    }
    cout << "}\n";
}

// Main function
int main() {
    cout << "Enter number of elements in set\n";
    cin >> n; // Input the number of elements in the set

    cout << "Enter values\n";
    for (int i = 0; i < n; i++) {
        cin >> s[i]; // Input the elements of the set
    }

    cout << "Enter sum\n";
    cin >> d; // Input the desired sum 'd'

    cout << "The program output is:\n";
    subset(0, 0); // Start finding subsets with initial sum = 0 and starting index = 0

    // If no subset was found, print "There is no solution"
    if (flag == 0) {
        cout << "There is no solution";
    }

    return 0; // End of program
}
