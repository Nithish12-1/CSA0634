#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    int list[n];
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    int minSequence[n]; 
    int maxSequence[n];
    minSequence[0] = list[0];
    maxSequence[0] = list[0];
    for (int i = 1; i < n; i++) {
        minSequence[i] = (list[i] < minSequence[i - 1]) ? list[i] : minSequence[i - 1];
        maxSequence[i] = (list[i] > maxSequence[i - 1]) ? list[i] : maxSequence[i - 1];
    }
    printf("Minimum value sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", minSequence[i]);
    }
    printf("\n");
    printf("Maximum value sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", maxSequence[i]);
    }
    printf("\n");

    return 0;
}
