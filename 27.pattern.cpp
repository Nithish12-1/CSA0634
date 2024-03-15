#include <stdio.h>
void printPattern(int n) {
    if (n > 0) {
        for (int i = 0; i < n; i++) {
            printf("* ");
        }
        printf("\n");
        printPattern(n - 1);
        for (int i = 0; i < n; i++) {
            printf("* ");
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &n);
    printPattern(n);
    return 0;
}
