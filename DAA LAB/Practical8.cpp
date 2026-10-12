// ============================================================
// Graph Traversal using DFS and BFS
// ============================================================

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ============================================================
// Depth First Search (DFS)
// ============================================================
// DFS explores a path as deeply as possible before backtracking.
//
// Time Complexity  : O(V^2) using an adjacency matrix
// Space Complexity : O(V) for visited array and recursion stack
// ============================================================

void dfs(vector<vector<int>>& graph, vector<bool>& visited,
         int v, int n) {

    // Mark the current vertex as visited.
    visited[v] = true;

    // Print the current vertex.
    cout << v << " ";

    // Check all possible adjacent vertices.
    for (int i = 0; i < n; i++) {

        // If an edge exists and the vertex is unvisited,
        // recursively perform DFS from that vertex.
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, n);
        }
    }
}

// ============================================================
// Breadth First Search (BFS)
// ============================================================
// BFS visits vertices level by level using a queue.
//
// Time Complexity  : O(V^2) using an adjacency matrix
// Space Complexity : O(V) for visited array and queue
// ============================================================

void bfs(vector<vector<int>>& graph, int start, int n) {

    // Create a visited array initialized to false.
    vector<bool> visited(n, false);

    // Create a queue to store vertices.
    queue<int> q;

    // Mark the starting vertex as visited.
    visited[start] = true;

    // Insert the starting vertex into the queue.
    q.push(start);

    // Continue until the queue becomes empty.
    while (!q.empty()) {

        // Remove the front vertex from the queue.
        int v = q.front();
        q.pop();

        // Print the current vertex.
        cout << v << " ";

        // Check all possible adjacent vertices.
        for (int i = 0; i < n; i++) {

            // If an edge exists and the vertex is unvisited,
            // mark it visited and add it to the queue.
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// ============================================================
// Main Function
// ============================================================

int main() {

    // Read the number of vertices.
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    // Read the adjacency matrix.
    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter Adjacency Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Read the starting vertex.
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // Validate the starting vertex.
    if (start < 0 || start >= n) {
        cout << "Invalid starting vertex!" << endl;
        return 1;
    }

    // Display traversal options.
    int choice;
    cout << "\n1. DFS\n";
    cout << "2. BFS\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    // Perform DFS.
    if (choice == 1) {
        vector<bool> visited(n, false);

        cout << "\nDFS Traversal: ";
        dfs(graph, visited, start, n);
        cout << endl;
    }

    // Perform BFS.
    else if (choice == 2) {
        cout << "\nBFS Traversal: ";
        bfs(graph, start, n);
        cout << endl;
    }

    // Handle an invalid menu choice.
    else {
        cout << "Invalid Choice!" << endl;
    }

    return 0;
}

// ============================================================
// End of Program
// ============================================================


/*
OUTPUT:
PS C:\Users\chara\OneDrive\One drive\DAA PRACTICALS\DAA LAB> cd "c:\Users\chara\OneDrive\One drive\DAA PRACTICALS\" ; if ($?) { g++ Practical8.cpp -o Practical8 } ; if ($?) { .\Practical8 }
Enter number of vertices: 4
Enter Adjacency Matrix:
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter starting vertex: 0

1. DFS
2. BFS

Enter your choice: 1

DFS Traversal: 0 1 3 2 
PS C:\Users\chara\OneDrive\One drive\DAA PRACTICALS> 
*/