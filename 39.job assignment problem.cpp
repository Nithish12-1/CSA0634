#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4 // Number of workers and tasks

// Function to find the minimum cost assignment using branch and bound
void branch_and_bound(int cost[N][N], int assignment[N], bool assigned[N], int current_cost, int depth, int* min_cost) {
    // If we have assigned all tasks, update the minimum cost
    if (depth == N) {
        if (current_cost < *min_cost) {
            *min_cost = current_cost;
            printf("Minimum cost: %d\n", *min_cost);
            printf("Assignment: ");
            for (int i = 0; i < N; i++) {
                printf("%d ", assignment[i]);
            }
            printf("\n");
        }
        return;
    }

    // Branch and bound pruning
    if (current_cost >= *min_cost) {
        return;
    }

    // Try assigning each task to each worker
    for (int i = 0; i < N; i++) {
        if (!assigned[i]) {
            assigned[i] = true;
            assignment[depth] = i;
            branch_and_bound(cost, assignment, assigned, current_cost + cost[depth][i], depth + 1, min_cost);
            assigned[i] = false;
        }
    }
}

// Main function
int main() {
    int cost[N][N] = {{9, 2, 7, 8},
                      {6, 4, 3, 7},
                      {5, 8, 1, 8},
                      {7, 6, 9, 4}}; // Cost matrix

    int assignment[N]; // To store the assignment
    bool assigned[N] = {false}; // To keep track of assigned tasks
    int min_cost = INT_MAX; // Initialize minimum cost to maximum possible value

    branch_and_bound(cost, assignment, assigned, 0, 0, &min_cost);

    printf("Minimum cost assignment: %d\n", min_cost);

    return 0;
}
