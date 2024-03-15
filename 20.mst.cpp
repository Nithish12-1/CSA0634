#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the vertex with minimum key value
int min_key(int key[], int mst_set[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mst_set[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}
int V;
// Function to print MST using parent array
void print_mst(int parent[], int graph[][V], int V) {
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to find Minimum Spanning Tree using Prim's algorithm
void prim_mst(int graph[][V], int V) {
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values used to pick minimum weight edge in cut
    int mst_set[V]; // To represent set of vertices not yet included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mst_set[i] = 0;
    }

    // Always include first 0th vertex in MST.
    // Make key 0 so that this vertex is picked as the first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = min_key(key, mst_set, V);

        // Add the picked vertex to the MST set
        mst_set[u] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of m
            // mst_set[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mst_set[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    print_mst(parent, graph, V);
}

// Main function
int main() {
    int V;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];

    printf("Enter the adjacency matrix representing the graph:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    // Print the Minimum Spanning Tree
    prim_mst(graph, V);

    return 0;
}
