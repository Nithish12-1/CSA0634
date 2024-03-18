#include <stdio.h>

#define MAX_SIZE 100

// Function to check if there exists a subset with given sum using backtracking
int isSubsetSum(int set[], int n, int target_sum, int subset[], int subset_size) {
    // If the target sum is 0, it means the subset is found, so print it
    if (target_sum == 0) {
        printf("Subset found: ");
        for (int i = 0; i < subset_size; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return 1;
    }

    // If all elements are processed, or target sum is negative, return false
    if (n == 0 || target_sum < 0)
        return 0;

    // Exclude the current element and process remaining elements
    if (isSubsetSum(set, n - 1, target_sum, subset, subset_size))
        return 1;

    // Include the current element in the subset
    subset[subset_size] = set[n - 1];
    return isSubsetSum(set, n - 1, target_sum - set[n - 1], subset, subset_size + 1);
}

int main() {
    int n, target_sum;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[MAX_SIZE];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    int subset[MAX_SIZE];
    if (!isSubsetSum(set, n, target_sum, subset, 0))
        printf("No subset found with the given sum.\n");

    return 0;
}
