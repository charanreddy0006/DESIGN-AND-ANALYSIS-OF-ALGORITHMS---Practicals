
#include <iostream>
using namespace std;

#define MAX 20
#define INF 99999

// ============================================================
// TRAVELLING SALESMAN PROBLEM (TSP)
// ============================================================
//
// Travelling Salesman Problem finds the minimum cost tour
// in which a salesman visits every city exactly once
// and returns to the starting city.
//
// It uses the Brute Force (Permutation) Approach.
//
// The algorithm checks all possible city arrangements
// and selects the tour having minimum total cost.
//
// Time Complexity : O(V!)
// Space Complexity: O(V)
//
// V = Number of cities
// INF = Represents no direct connection
// ============================================================


// Matrix to store the cost between cities.
int cost[MAX][MAX];

// Array to track visited cities.
bool visited[MAX];

// Stores the minimum tour cost.
int minCost = INF;

// Stores the current and minimum paths.
int path[MAX];
int bestPath[MAX];


// ============================================================
// Function: tsp()
// Purpose : Explore all possible tours using recursion.
//
// currentCity = Current city
// count       = Number of visited cities
// currentCost = Cost of the current tour
// ============================================================

void tsp(int currentCity, int count, int currentCost, int v)
{
    int i;

    // If all cities are visited, return to the starting city.
    if (count == v)
    {
        // Check whether a return path exists.
        if (cost[currentCity][0] != INF)
        {
            int total = currentCost + cost[currentCity][0];

            // Update minimum cost if a better tour is found.
            if (total < minCost)
            {
                minCost = total;

                // Store the best path.
                for (i = 0; i < v; i++)
                {
                    bestPath[i] = path[i];
                }
            }
        }

        return;
    }

    // Try visiting every unvisited city.
    for (i = 0; i < v; i++)
    {
        // Check whether the city is unvisited
        // and a direct connection exists.
        if (!visited[i] && cost[currentCity][i] != INF)
        {
            // Mark the city as visited.
            visited[i] = true;

            // Store the city in the current path.
            path[count] = i;

            // Recursively visit the next city.
            tsp(i, count + 1,
                currentCost + cost[currentCity][i], v);

            // Backtrack and mark the city as unvisited.
            visited[i] = false;
        }
    }
}


// ============================================================
// Function: displayResult()
// Purpose : Display the minimum cost and optimal tour.
// ============================================================

void displayResult(int v)
{
    int i;

    cout << "\n============================================\n";
    cout << "       TRAVELLING SALESMAN PROBLEM          \n";
    cout << "============================================\n";

    if (minCost == INF)
    {
        cout << "No complete tour exists.\n";
        cout << "============================================\n";
        return;
    }

    cout << "Minimum Cost = " << minCost << endl;

    cout << "Optimal Tour = ";

    // Display the best path.
    for (i = 0; i < v; i++)
    {
        cout << bestPath[i] << " -> ";
    }

    // Return to the starting city.
    cout << bestPath[0] << endl;

    cout << "============================================\n";
}


// ============================================================
// Main Function
// ============================================================

int main()
{
    int v;
    int i, j;

    // Read the number of cities.
    cout << "Enter number of cities: ";
    cin >> v;

    // Validate the number of cities.
    if (v <= 0 || v > MAX)
    {
        cout << "Error: Invalid number of cities.\n";
        return 1;
    }

    // Read the cost adjacency matrix.
    cout << "\nEnter the cost matrix:\n";
    cout << "Enter 99999 if there is no direct connection.\n\n";

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            cin >> cost[i][j];

            // Validate the cost values.
            if (cost[i][j] < 0)
            {
                cout << "Error: Negative costs are not allowed.\n";
                return 1;
            }
        }
    }

    // Initially, mark all cities as unvisited.
    for (i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    // Start the tour from city 0.
    visited[0] = true;
    path[0] = 0;

    // Find the minimum cost tour.
    tsp(0, 1, 0, v);

    // Display the final result.
    displayResult(v);

    return 0;
}

/*
OUTPUT:

Enter number of cities: 4

Enter the cost matrix:
Enter 99999 if there is no direct connection.

0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0

============================================
       TRAVELLING SALESMAN PROBLEM
============================================
Minimum Cost = 80
Optimal Tour = 0 -> 1 -> 3 -> 2 -> 0
============================================

*/
