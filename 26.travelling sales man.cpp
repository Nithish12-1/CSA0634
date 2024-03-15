#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function prototype
int tsp(int **graph, int mask, int pos, int N);

int main() {
    int N;
    printf("Enter the number of cities: ");
    scanf("%d", &N);

    // Dynamically allocate memory for the graph
    int **graph = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        graph[i] = (int *)malloc(N * sizeof(int));
    }

    // Input distances between cities
    printf("Enter the distances between cities:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startCity = 0;
    int mask = 1 << startCity;

    // Call the tsp function and print the result
    printf("Minimum cost for TSP: %d\n", tsp(graph, mask, startCity, N));

    // Free dynamically allocated memory
    for (int i = 0; i < N; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

// Function definition for TSP
int tsp(int **graph, int mask, int pos, int N) {
    if (mask == (1 << N) - 1)
        return graph[pos][0];

    int minCost = INT_MAX;

    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newMask = mask | (1 << city);
            int cost = graph[pos][city] + tsp(graph, newMask, city, N);
            if (cost < minCost)
                minCost = cost;
        }
    }

    return minCost;
}

