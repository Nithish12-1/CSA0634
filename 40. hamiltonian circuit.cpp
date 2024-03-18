#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices

// A utility function to check if the current vertex v can be added at index 'pos' in the Hamiltonian Circuit constructed so far
bool is_safe(int v, bool graph[V][V], int path[], int pos) {
    // Check if this vertex is an adjacent vertex of the previously added vertex
    if (!graph[path[pos - 1]][v])
        return false;

    // Check if the vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// A utility function to print the solution
void print_solution(int path[]) {
    printf("Hamiltonian Circuit found: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    // To close the Hamiltonian cycle
    printf("%d\n", path[0]);
}

// A recursive utility function to solve Hamiltonian cycle problem
bool hamiltonian_cycle_util(bool graph[V][V], int path[], int pos) {
    // Base case: If all vertices are included in the Hamiltonian Cycle
    if (pos == V) {
        // And if there is an edge from the last included vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as the next candidate in Hamiltonian Cycle. We don't need to try for vertex 0 as starting point is always vertex 0.
    for (int v = 1; v < V; v++) {
        // Check if this vertex can be added to Hamiltonian Cycle
        if (is_safe(v, graph, path, pos)) {
            path[pos] = v;

            // Recur to construct the rest of the path
            if (hamiltonian_cycle_util(graph, path, pos + 1) == true)
                return true;

            // If adding vertex v doesn't lead to a solution, then remove it
            path[pos] = -1;
        }
    }

    // If no vertex can be added to Hamiltonian Cycle constructed so far, then return false
    return false;
}

// A function to find Hamiltonian cycle
void hamiltonian_cycle(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start from the vertex 0 as the starting point for Hamiltonian Cycle
    path[0] = 0;
    if (hamiltonian_cycle_util(graph, path, 1) == false) {
        printf("No Hamiltonian Cycle exists\n");
        return;
    }

    print_solution(path);
}

// Main function
int main() {
    // Example graph
    bool graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };

    hamiltonian_cycle(graph);

    return 0;
}
