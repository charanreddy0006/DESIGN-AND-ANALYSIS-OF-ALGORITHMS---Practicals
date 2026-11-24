
#include <iostream>
using namespace std;

#define MAX 20
#define INF 99999

// ============================================================
// FLOYD-WARSHALL ALGORITHM - ALL PAIRS SHORTEST PATH
// ============================================================
//
// Floyd-Warshall algorithm finds the shortest paths
// between all pairs of vertices in a weighted graph.
//
// It follows Dynamic Programming Approach.
//
// It works with directed as well as undirected graphs.
// It can also handle negative edge weights, but not
// negative weight cycles.
//
// Time Complexity : O(V^3)
// Space Complexity: O(V^2)
//
// V = Number of vertices
// INF = Represents infinity (no direct edge)
// ============================================================


// Matrix to store the graph and shortest distances.
int dist[MAX][MAX];


// ============================================================
// Function: floydWarshall()
// Purpose : Find shortest distances between all pairs
//           of vertices using Dynamic Programming.
//
// dist[i][j] represents the shortest distance
// from vertex i to vertex j.
// ============================================================

void floydWarshall(int v)
{
    int i, j, k;

    // Consider each vertex as an intermediate vertex.
    for (k = 0; k < v; k++)
    {
        // Check every possible source vertex.
        for (i = 0; i < v; i++)
        {
            // Check every possible destination vertex.
            for (j = 0; j < v; j++)
            {
                // Update the distance if a shorter path
                // is found through intermediate vertex k.
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}


// ============================================================
// Function: displayMatrix()
// Purpose : Display the shortest distance matrix.
// ============================================================

void displayMatrix(int v)
{
    int i, j;

    cout << "\nShortest Distance Matrix:\n";
    cout << "--------------------------------------------\n";

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF\t";
            }
            else
            {
                cout << dist[i][j] << "\t";
            }
        }

        cout << endl;
    }

    cout << "--------------------------------------------\n";
}


// ============================================================
// Main Function
// ============================================================

int main()
{
    int v;
    int i, j;

    // Read the number of vertices.
    cout << "Enter number of vertices: ";
    cin >> v;

    // Validate the number of vertices.
    if (v <= 0 || v > MAX)
    {
        cout << "Error: Invalid number of vertices.\n";
        return 1;
    }

    // Read the adjacency matrix.
    cout << "\nEnter the adjacency matrix:\n";
    cout << "Enter 99999 for INF (no direct edge).\n\n";

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            cin >> dist[i][j];

            // Validate the distance values.
            if (dist[i][j] < 0 && dist[i][j] == INF)
            {
                cout << "Error: Invalid distance.\n";
                return 1;
            }
        }
    }

    // Apply Floyd-Warshall algorithm.
    floydWarshall(v);

    // Display the final shortest distance matrix.
    cout << "\n============================================\n";
    cout << "       FLOYD-WARSHALL ALGORITHM             \n";
    cout << "============================================\n";

    displayMatrix(v);

    // Check for negative weight cycles.
    for (i = 0; i < v; i++)
    {
        if (dist[i][i] < 0)
        {
            cout << "\nNegative weight cycle detected.\n";
            cout << "Shortest paths are not well-defined.\n";
            return 0;
        }
    }

    cout << "\nAll-Pairs Shortest Paths calculated successfully.\n";

    cout << "============================================\n";

    return 0;
}

/*
OUTPUT:

Enter number of vertices: 4

Enter the adjacency matrix:
Enter 99999 for INF (no direct edge).

0 5 99999 10
99999 0 3 99999
99999 99999 0 1
99999 99999 99999 0

============================================
       FLOYD-WARSHALL ALGORITHM
============================================

Shortest Distance Matrix:
--------------------------------------------
0       5       8       9
INF     0       3       4
INF     INF     0       1
INF     INF     INF     0
--------------------------------------------

All-Pairs Shortest Paths calculated successfully.
============================================

*/
