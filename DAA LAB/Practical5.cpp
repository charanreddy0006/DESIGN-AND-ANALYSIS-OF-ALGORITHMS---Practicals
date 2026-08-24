/*
The Knapsack Problem is a classic optimization problem where you must select items with given weights
 and values to maximize total value without exceeding a fixed capacity. In the 0/1 version, 
 each item can either be taken or left behind, and it's solved efficiently using dynamic programming. 
 It has real-world applications in resource allocation, budgeting, and cargo loading.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve 0/1 Knapsack problem
int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    // dp[i][w] = maximum value achievable using first 'i' items with capacity 'w'
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the DP table bottom-up
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                // Choice: either INCLUDE the item or EXCLUDE it
                // Include: value[i-1] + best of remaining capacity (w - weight)
                // Exclude: same as without this item
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]],
                               dp[i - 1][w]);
            } else {
                // Item too heavy for current capacity -> can't include it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity]; // Answer: all items considered, full capacity available
}

int main() {
    int n;      // number of items
    int capacity; // knapsack capacity

    // ---------- INPUT ----------
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<int> weights(n), values(n);

    cout << "Enter weight and value of each item:
";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " (weight value): ";
        cin >> weights[i] >> values[i];
    }

    // ---------- PROCESS ----------
    int maxValue = knapsack(capacity, weights, values, n);

    // ---------- OUTPUT ----------
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}

/* INPUT :
Enter number of items: 4
Enter knapsack capacity: 8
Enter weight and value of each item:
Item 1 (weight value): 2 3
Item 2 (weight value): 3 4
Item 3 (weight value): 4 5
Item 4 (weight value): 5 6
*/
/* OUTPUT
Maximum value in knapsack = 10
*/
