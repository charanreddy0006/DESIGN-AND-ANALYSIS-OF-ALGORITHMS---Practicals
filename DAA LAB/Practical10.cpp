
#include <iostream>
using namespace std;

#define MAX 20

// ============================================================
// KRUSKAL'S ALGORITHM - MINIMUM SPANNING TREE (MST)
// ============================================================
//
// Kruskal's algorithm finds a Minimum Spanning Tree (MST)
// of a connected, undirected, weighted graph.
//
// It follows the Greedy Approach by selecting the smallest
// available edge that does not form a cycle.
//
// Time Complexity : O(E^2) using Bubble Sort
// Space Complexity: O(V + E)
//
// V = Number of vertices
// E = Number of edges
// ============================================================


// Structure to store the details of an edge.
// u = Source vertex
// v = Destination vertex
// w = Weight (cost) of the edge

struct Edge
{
    int u, v, w;
};


// Array to store all edges of the graph.
Edge edge[MAX];

// Parent array used to represent disjoint sets.
// It helps determine whether two vertices belong
// to the same connected component.
int parent[MAX];


// ============================================================
// Function: find()
// Purpose : Find the representative (parent) of a vertex.
//
// If parent[x] == x, then x is the representative.
// Otherwise, keep following parent links until the
// representative is found.
// ============================================================

int find(int x)
{
    while (parent[x] != x)
    {
        x = parent[x];
    }

    return x;
}


// ============================================================
// Function: Union()
// Purpose : Merge two different disjoint sets.
//
// This function connects the representative of one set
// to the representative of the other set.
// ============================================================

void Union(int a, int b)
{
    parent[a] = b;
}


// ============================================================
// Function: sortEdges()
// Purpose : Sort all edges in increasing order of weight.
//
// Bubble Sort compares adjacent edges and swaps them
// whenever they are in the wrong order.
// ============================================================

void sortEdges(int e)
{
    int i, j;
    Edge temp;

    // Repeat passes until all edges are sorted.
    for (i = 0; i < e - 1; i++)
    {
        // Compare adjacent edges in the unsorted section.
        for (j = 0; j < e - i - 1; j++)
        {
            // Swap if the current edge has a greater weight.
            if (edge[j].w > edge[j + 1].w)
            {
                temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }
}


// ============================================================
// Main Function
// ============================================================

int main()
{
    int v, e;
    int i;
    int totalCost = 0;

    // Read the number of vertices.
    cout << "Enter number of vertices: ";
    cin >> v;

    // Read the number of edges.
    cout << "Enter number of edges: ";
    cin >> e;

    // Validate the input sizes.
    if (v <= 0 || v > MAX || e < 0 || e > MAX)
    {
        cout << "Error: Invalid number of vertices or edges.\n";
        return 1;
    }

    // Read the source, destination, and weight of each edge.
    cout << "\nEnter Source Destination Weight:\n";
    cout << "Example: 0 1 10\n\n";

    for (i = 0; i < e; i++)
    {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;

        // Check whether the entered vertices are valid.
        if (edge[i].u < 0 || edge[i].u >= v ||
            edge[i].v < 0 || edge[i].v >= v)
        {
            cout << "Error: Invalid vertex number.\n";
            return 1;
        }
    }

    // Initialize every vertex as a separate set.
    // Initially, each vertex is its own parent.
    for (i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    // Sort all edges by increasing weight.
    sortEdges(e);

    // Display the selected edges of the MST.
    cout << "\n============================================\n";
    cout << "       MINIMUM SPANNING TREE (KRUSKAL)      \n";
    cout << "============================================\n";
    cout << "Source  Destination  Weight\n";
    cout << "--------------------------------------------\n";

    // Count the number of edges selected for the MST.
    int selectedEdges = 0;

    // Examine edges in increasing order of weight.
    for (i = 0; i < e && selectedEdges < v - 1; i++)
    {
        // Find the representatives of both endpoints.
        int p1 = find(edge[i].u);
        int p2 = find(edge[i].v);

        // If representatives differ, adding this edge
        // will not create a cycle.
        if (p1 != p2)
        {
            // Merge the two sets.
            Union(p1, p2);

            // Display the selected edge and its weight.
            cout << edge[i].u << "       "
                 << edge[i].v << "            "
                 << edge[i].w << endl;

            // Add the edge weight to the total MST cost.
            totalCost += edge[i].w;

            // Increase the number of selected edges.
            selectedEdges++;
        }
    }

    cout << "--------------------------------------------\n";

    // An MST must contain exactly V - 1 edges.
    if (selectedEdges == v - 1)
    {
        cout << "Minimum Cost = " << totalCost << endl;
    }
    else
    {
        cout << "The graph is disconnected.\n";
        cout << "A Minimum Spanning Tree cannot be formed.\n";
    }

    cout << "============================================\n";

    return 0;
}

/*
OUTPUT:
Enter number of vertices: 4
Enter number of edges: 5

Enter Source Destination Weight:
Example: 0 1 10

0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

============================================
       MINIMUM SPANNING TREE (KRUSKAL)   
============================================
Source  Destination  Weight
--------------------------------------------
2       3            4
0       3            5
0       1            10
--------------------------------------------
Minimum Cost = 19
============================================
PS C:\Users\chara\OneDrive\One drive\DAA PRACTICALS\DAA LAB> 
*/