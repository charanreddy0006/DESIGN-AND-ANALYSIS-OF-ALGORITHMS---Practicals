
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

// ============================================================
// PRIM'S ALGORITHM - MINIMUM SPANNING TREE (MST)
// ============================================================
//
// Prim's algorithm finds a Minimum Spanning Tree of a connected,
// undirected, weighted graph.
//
// Time Complexity  : O(V^2) using an adjacency matrix
// Space Complexity : O(V^2) for the adjacency matrix
//
// V = Number of vertices
// ============================================================

const int INF = numeric_limits<int>::max();

// ------------------------------------------------------------
// Function: primMST()
// Purpose : Find and display the Minimum Spanning Tree.
// ------------------------------------------------------------

void primMST(const vector<vector<int>>& graph, int n) {

    // Track vertices already included in the MST.
    vector<bool> selected(n, false);

    // Store the total cost of the Minimum Spanning Tree.
    long long totalCost = 0;

    // Start from vertex 0.
    selected[0] = true;

    // An MST with n vertices contains exactly n - 1 edges.
    cout << "\n============================================\n";
    cout << "       MINIMUM SPANNING TREE (PRIM'S)       \n";
    cout << "============================================\n";
    cout << left << setw(12) << "Source"
         << setw(16) << "Destination"
         << "Weight\n";
    cout << "--------------------------------------------\n";

    // Select n - 1 edges to construct the MST.
    for (int edge = 0; edge < n - 1; edge++) {

        // Initially, no minimum edge has been found.
        int minimum = INF;
        int source = -1;
        int destination = -1;

        // Examine all vertices already included in the MST.
        for (int i = 0; i < n; i++) {

            if (selected[i]) {

                // Find the smallest edge connecting an included
                // vertex to a vertex outside the MST.
                for (int j = 0; j < n; j++) {

                    if (!selected[j] &&
                        graph[i][j] != INF &&
                        graph[i][j] < minimum) {

                        minimum = graph[i][j];
                        source = i;
                        destination = j;
                    }
                }
            }
        }

        // If no edge is found, the graph is disconnected.
        if (source == -1) {
            cout << "\nError: The graph is disconnected.\n";
            cout << "A Minimum Spanning Tree cannot be formed.\n";
            return;
        }

        // Display the selected edge and its weight.
        cout << left << setw(12) << source
             << setw(16) << destination
             << minimum << '\n';

        // Add the edge weight to the total MST cost.
        totalCost += minimum;

        // Include the destination vertex in the MST.
        selected[destination] = true;
    }

    // Display the final minimum cost.
    cout << "--------------------------------------------\n";
    cout << "Minimum Cost = " << totalCost << '\n';
    cout << "============================================\n";
}

// ------------------------------------------------------------
// Main Function
// ------------------------------------------------------------

int main() {

    int n;

    // Display the program heading.
    cout << "\n============================================\n";
    cout << "          PRIM'S ALGORITHM IN C++           \n";
    cout << "============================================\n";

    // Read the number of vertices.
    cout << "\nEnter number of vertices: ";
    cin >> n;

    // Validate the number of vertices.
    if (n <= 0) {
        cout << "Error: Number of vertices must be positive.\n";
        return 1;
    }

    // Create an n x n cost adjacency matrix.
    vector<vector<int>> graph(n, vector<int>(n));

    // Read the cost adjacency matrix.
    cout << "\nEnter Cost Adjacency Matrix:\n";
    cout << "Enter " << n << " rows with " << n << " values each.\n";
    cout << "Use 0 for no edge between different vertices.\n\n";

    for (int i = 0; i < n; i++) {

        cout << "Row " << i << ": ";

        for (int j = 0; j < n; j++) {

            cin >> graph[i][j];

            // A negative edge weight is not supported here.
            if (graph[i][j] < 0) {
                cout << "\nError: Enter non-negative edge weights.\n";
                return 1;
            }
        }
    }

    // Replace zero weights between different vertices with INF.
    // Diagonal entries represent a vertex connected to itself.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i != j && graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    // Run Prim's algorithm to construct the MST.
    primMST(graph, n);

    return 0;
}

/*
Output:
============================================
          PRIM'S ALGORITHM IN C++   
============================================

Enter number of vertices: 4

Enter Cost Adjacency Matrix:
Enter 4 rows with 4 values each.
Use 0 for no edge between different vertices.

Row 0: 0 10 6 0
Row 1: 10 0 5 15
Row 2: 6 5 0 4
Row 3: 0 15 4 0

============================================
       MINIMUM SPANNING TREE (PRIM'S)   
============================================
Source      Destination     Weight
--------------------------------------------
0           2               6
2           3               4
2           1               5
--------------------------------------------
Minimum Cost = 15
============================================
PS C:\Users\chara\OneDrive\One drive\DAA PRACTICALS\DAA LAB> 
*/