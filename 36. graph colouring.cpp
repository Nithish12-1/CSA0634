#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10 // Maximum number of vertices in the graph

// Function to check if it's safe to assign color c to vertex v
bool is_safe(int v, int graph[][MAX_VERTICES], int color[], int c, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

// Recursive function to perform graph coloring
bool graph_coloring_util(int graph[][MAX_VERTICES], int m, int color[], int v, int num_vertices) {
    if (v == num_vertices)
        return true;

    for (int c = 1; c <= m; c++) {
        if (is_safe(v, graph, color, c, num_vertices)) {
            color[v] = c;
            if (graph_coloring_util(graph, m, color, v + 1, num_vertices))
                return true;
            color[v] = 0;
        }
    }

    return false;
}

// Function to perform graph coloring
bool graph_coloring(int graph[][MAX_VERTICES], int m, int num_vertices) {
    int color[MAX_VERTICES];
    for (int i = 0; i < num_vertices; i++)
        color[i] = 0;

    if (!graph_coloring_util(graph, m, color, 0, num_vertices)) {
        printf("Solution does not exist.\n");
        return false;
    }

    printf("Solution exists. The color assignments are:\n");
    for (int i = 0; i < num_vertices; i++)
        printf("Vertex %d: Color %d\n", i, color[i]);
    return true;
}

// Main function
int main() {
    int num_vertices, num_edges, m;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {{0}};

    printf("Enter the edges of the graph (vertex1 vertex2):\n");
    for (int i = 0; i < num_edges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1; // Since it's an undirected graph
    }

    printf("Enter the number of colors available: ");
    scanf("%d", &m);

    graph_coloring(graph, m, num_vertices);

    return 0;
}
