#include <stdio.h>

// Function to recursively find all factors of n
void findFactors(int n, int i) {
    if (i > n)
        return;

    if (n % i == 0) {
        printf("%d ", i); // If i is a factor, print it
        findFactors(n, i + 1); // Recur for the next number
    } else {
        findFactors(n, i + 1); // Otherwise, check the next number
    }
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Factors of %d are: ", n);
    findFactors(n, 1); // Start with i = 1
    printf("\n");

    return 0;
}
